// OvertimeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "COWA.h"
#include "OvertimeDlg.h"
#include "RecordDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern CDatabase Db;
/////////////////////////////////////////////////////////////////////////////
// COvertimeDlg property page

IMPLEMENT_DYNCREATE(COvertimeDlg, CPropertyPage)

COvertimeDlg::COvertimeDlg() : CPropertyPage(COvertimeDlg::IDD)
{
	//{{AFX_DATA_INIT(COvertimeDlg)
	m_CurTime = 0;
	m_OvertimeHours = 0;
	//}}AFX_DATA_INIT
}

COvertimeDlg::~COvertimeDlg()
{
}

void COvertimeDlg::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COvertimeDlg)
	DDX_Control(pDX, IDC_OVERTIME_LIST, m_OvertimeList);
	DDX_DateTimeCtrl(pDX, IDC_CUR_TIME, m_CurTime);
	DDX_Text(pDX, IDC_OVERTIME_HOURS, m_OvertimeHours);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(COvertimeDlg, CPropertyPage)
	//{{AFX_MSG_MAP(COvertimeDlg)
	ON_EN_CHANGE(IDC_CLERK_ID, OnChangeClerkId)
	ON_BN_CLICKED(IDC_ADD_OVERTIME_R, OnAddOvertimeR)
	ON_BN_CLICKED(IDC_DELETE_OVERTIM_R, OnDeleteOvertimR)
	ON_BN_CLICKED(IDC_OVERTIMR_SEARCH, OnOvertimrSearch)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COvertimeDlg message handlers

void COvertimeDlg::OnChangeClerkId() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CPropertyPage::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	CString PersonD;
	CPersonRS PersonRS(&Db);
	GetDlgItemText(IDC_CLERK_ID,PersonD);
	PersonRS.m_strFilter="ID = '"+PersonD + "'";
	PersonRS.Open();
	if (PersonRS.GetRecordCount()==1)
	{
		SetDlgItemText(IDC_CLERK_NAME,PersonRS.m_NAME);
	}
	else
	{
		SetDlgItemText(IDC_CLERK_NAME,"");
	}
	PersonRS.Close();
	// TODO: Add your control notification handler code here
	
}

BOOL COvertimeDlg::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	// TODO: Add extra initialization here
    //初始化列表控件
	m_OvertimeList.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	m_OvertimeList.InsertColumn(0,"ID",LVCFMT_LEFT,90);
	m_OvertimeList.InsertColumn(1,"PERSON",LVCFMT_LEFT,110);
	m_OvertimeList.InsertColumn(2,"WORK_HOURS",LVCFMT_LEFT,90);
	m_OvertimeList.InsertColumn(3,"WORK_DATE",LVCFMT_LEFT,160);
    //显示列表
    ShowList();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void COvertimeDlg::ShowList()
{
	int i=0;
	CString Str;
	COvertimeRS OvertimeRS(&Db);
	OvertimeRS.Open();
	m_OvertimeList.DeleteAllItems();
	while (!OvertimeRS.IsEOF())
	{
		m_OvertimeList.InsertItem(i," ");
		Str.Format("%d",OvertimeRS.m_ID);
		m_OvertimeList.SetItemText(i,0,Str);
		m_OvertimeList.SetItemText(i,1,OvertimeRS.m_PERSON);
        Str.Format("%d",OvertimeRS.m_WORK_HOURS);
		m_OvertimeList.SetItemText(i,2,Str);
		Str=OvertimeRS.m_WORK_DATE.Format("%Y-%m-%d");
		m_OvertimeList.SetItemText(i,3,Str);
		OvertimeRS.MoveNext();
		i++;
	}
	OvertimeRS.Close();
}

void COvertimeDlg::OnAddOvertimeR() 
{
	// TODO: Add your control notification handler code here
	if (GetDlgItem(IDC_CLERK_ID)->GetWindowTextLength()==0)   //待完善
	{
		MessageBox("请输入员工号","提示",MB_OK | MB_ICONINFORMATION);
		return;
	}
	//
	UpdateData();
	//添加考勤COUNTER表中加班记录
	int CounterA;            //考勤计数保存，后面添加考勤记录时赋值给类CRecordset的派生类的成员函数m_ID
	CcounterRS CounterRS(&Db); 
	CounterRS.m_strFilter = "ID='O'"; 
	CounterRS.Open(); 
	CounterRS.Edit(); 
	CounterRS.m_COUNTER_VALUE++; 
	CounterA=CounterRS.m_COUNTER_VALUE;
	CounterRS.Update(); 
	CounterRS.Close(); 

	////在OVERTIME表中添加加班记录
	COvertimeRS OvertimeRS(&Db);
	OvertimeRS.Open();
	OvertimeRS.AddNew();
	//add ID
	OvertimeRS.m_ID=CounterA;
	//add person
	CString Str; 
	//GetDlgItem(IDC_CLERK_ID)->GetWindowText(Str);     
	GetDlgItemText(IDC_CLERK_ID,Str);              
    OvertimeRS.m_PERSON=Str;
	//add WORK_HOURS
	OvertimeRS.m_WORK_HOURS=m_OvertimeHours;
	//add WORK_DATE
// 	UpdateData();
//     CString str=m_CurTime.Format("%Y-%m-%d %H:%M:%S");
// 	AfxMessageBox(str);
	OvertimeRS.m_WORK_DATE=m_CurTime;
	OvertimeRS.Update();
	OvertimeRS.Close();
	ShowList();
}

void COvertimeDlg::OnDeleteOvertimR() 
{
	// TODO: Add your control notification handler code here
	int Index;
	CString Sql;
	POSITION pos=m_OvertimeList.GetFirstSelectedItemPosition();
	if (pos==NULL)
	{
		return;
	}
	Index=m_OvertimeList.GetNextSelectedItem(pos);
	Sql="delete * from OVERTIME where ID="+m_OvertimeList.GetItemText(Index,0);
	Db.ExecuteSQL(Sql);
	m_OvertimeList.DeleteAllItems();
	ShowList();
}

void COvertimeDlg::OnOvertimrSearch() 
{
	// TODO: Add your control notification handler code here
	CRecordDlg *PDlg=(CRecordDlg *)(GetParent()->GetParent());
	//数据赋值
	PDlg->UpdateData();
	//时间和员工检索条件都为假
	if (PDlg->m_CheckClerk==FALSE && PDlg->m_CheckTime==FALSE)
	{
		MessageBox("请选择检索条件","提示",MB_OK | MB_ICONINFORMATION);
		return;
	}
    //
	COvertimeRS OvertimeRS(&Db);
	CString StartTime,EndTime;
	StartTime=PDlg->m_StartTime.Format("%Y-%m-%d");
	EndTime=PDlg->m_EndTime.Format("%Y-%m-%d");
	//时间和员工检索条件都为真
	if (PDlg->m_CheckClerk==TRUE && PDlg->m_CheckTime==TRUE)
	{
		OvertimeRS.m_strFilter="PERSON = '" + PDlg->m_ClerkID + "' and WORK_DATE >= #" +StartTime + "# and WORK_DATE <= #" + EndTime + "#";  
	}
	//时间检索条件为真，员工检索条件为假
	else if (PDlg->m_CheckTime==TRUE && PDlg->m_CheckClerk==FALSE)
	{
		OvertimeRS.m_strFilter="WORK_DATE >= #" +StartTime + "# and WORK_DATE <= #" + EndTime + "#";
	}
	//时间检索条件为假，员工检索条件为真
	else
	{
		OvertimeRS.m_strFilter="PERSON = '" + PDlg->m_ClerkID + "'";
	}
	//显示
	int i=0;
	CString Str;
    OvertimeRS.Open();
	m_OvertimeList.DeleteAllItems();
	while (!OvertimeRS.IsEOF())
	{
		Str.Format("%d",OvertimeRS.m_ID);
		m_OvertimeList.InsertItem(i," ");
		m_OvertimeList.SetItemText(i,0,Str);
		m_OvertimeList.SetItemText(i,1,OvertimeRS.m_PERSON);
        Str.Format("%d",OvertimeRS.m_WORK_HOURS);
		m_OvertimeList.SetItemText(i,2,Str);
		Str=OvertimeRS.m_WORK_DATE.Format("%Y-%m-%d %H:%M:%S");
		m_OvertimeList.SetItemText(i,3,Str);
		OvertimeRS.MoveNext();
		i++;
	}
	OvertimeRS.Close();
}

