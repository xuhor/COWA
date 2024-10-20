// BusTripDlg.cpp : implementation file
//

#include "stdafx.h"
#include "COWA.h"
#include "BusTripDlg.h"
#include "RecordDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern CDatabase Db;
/////////////////////////////////////////////////////////////////////////////
// CBusTripDlg property page

IMPLEMENT_DYNCREATE(CBusTripDlg, CPropertyPage)

CBusTripDlg::CBusTripDlg() : CPropertyPage(CBusTripDlg::IDD)
{
	//{{AFX_DATA_INIT(CBusTripDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CBusTripDlg::~CBusTripDlg()
{
}

void CBusTripDlg::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBusTripDlg)
	DDX_Control(pDX, IDC_B_T_LIST, m_BTList);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBusTripDlg, CPropertyPage)
	//{{AFX_MSG_MAP(CBusTripDlg)
	ON_EN_CHANGE(IDC_B_T_CLERK_ID, OnChangeBTClerkId)
	ON_BN_CLICKED(IDC_ADD_B_T_RECORD, OnAddBTRecord)
	ON_BN_CLICKED(IDC_DELETE_B_T_RECORD, OnDeleteBTRecord)
	ON_BN_CLICKED(IDC_B_T_CHECK, OnBTCheck)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBusTripDlg message handlers

void CBusTripDlg::OnChangeBTClerkId() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CPropertyPage::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	CString PersonD;
	CPersonRS PersonRS(&Db);
	GetDlgItemText(IDC_B_T_CLERK_ID,PersonD);
	PersonRS.m_strFilter="ID = '"+PersonD + "'";
	PersonRS.Open();
	if (PersonRS.GetRecordCount()==1)
	{
		SetDlgItemText(IDC_B_T_CLERK_NAME,PersonRS.m_NAME);
	}
	else
	{
		SetDlgItemText(IDC_B_T_CLERK_NAME,"");
	}
	PersonRS.Close();
	// TODO: Add your control notification handler code here
	
}

void CBusTripDlg::OnAddBTRecord() 
{
	// TODO: Add your control notification handler code here
	int CounterA;            //考勤计数保存，后面添加考勤记录时赋值给类CRecordset的派生类的成员函数m_ID
	CcounterRS CounterRS(&Db); 
	CounterRS.m_strFilter = "ID='O'"; 
	CounterRS.Open(); 
	CounterRS.Edit(); 
	CounterRS.m_COUNTER_VALUE++; 
	CounterA=CounterRS.m_COUNTER_VALUE;
	CounterRS.Update(); 
	CounterRS.Close(); 
	//添加LEAVE记录
	CErrandRS ErrandRS(&Db);
	ErrandRS.Open();
	ErrandRS.AddNew();
	//get ID
	ErrandRS.m_ID=CounterA;
	//get PERSON
	CString Temp;
	GetDlgItem(IDC_B_T_CLERK_ID)->GetWindowText(Temp);
	ErrandRS.m_PERSON=Temp;
	//获取时间
	CString StartTime,EndTime;
	int Year,Month,Day,Hour,Minute,Second;
	//获取请假起始时间
	GetDlgItem(IDC_B_T_START_TIME)->GetWindowText(StartTime);
	sscanf(StartTime.Left(4), "%d", &Year); // 得到年
	sscanf(StartTime.Mid(5,2), "%d", &Month); // 得到月
	sscanf(StartTime.Mid(8,2), "%d", &Day); // 得到日
	sscanf(StartTime.Mid(11,2), "%d", &Hour); // 得到时
	sscanf(StartTime.Mid(14,2), "%d", &Minute); // 得到分
	sscanf(StartTime.Mid(17,2), "%d", &Second); // 得到秒
	CTime STime(Year,Month,Day,Hour,Minute,Second);
	ErrandRS.m_START_TIME=STime;
	//获取请假结束时间
	GetDlgItem(IDC_B_T_END_TIME)->GetWindowText(StartTime);
	sscanf(StartTime.Left(4), "%d", &Year); // 得到年
	sscanf(StartTime.Mid(5,2), "%d", &Month); // 得到月
	sscanf(StartTime.Mid(8,2), "%d", &Day); // 得到日
	sscanf(StartTime.Mid(11,2), "%d", &Hour); // 得到时
	sscanf(StartTime.Mid(14,2), "%d", &Minute); // 得到分
	sscanf(StartTime.Mid(17,2), "%d", &Second); // 得到秒
	CTime ETime(Year,Month,Day,Hour,Minute,Second);
	ErrandRS.m_END_TIME=ETime;
	//get REASON
    GetDlgItem(IDC_B_T_DESCRIPTION)->GetWindowText(Temp);
	ErrandRS.m_DESCRIPTION=Temp;
	ErrandRS.Update();
    ShowBTRecord();
}

BOOL CBusTripDlg::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_BTList.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	m_BTList.InsertColumn(0,"ID",LVCFMT_LEFT,60);
	m_BTList.InsertColumn(1,"PERSON",LVCFMT_LEFT,70);
	m_BTList.InsertColumn(2,"START_TIME",LVCFMT_LEFT,110);
	m_BTList.InsertColumn(3,"END_TIME",LVCFMT_LEFT,110);
	m_BTList.InsertColumn(4,"DESCRIPTION",LVCFMT_LEFT,110);
	//初始化控件IDC_L_START_TIME和IDC_L_END_TIME显示时间
	CTime CurTime;
	CurTime=CTime::GetCurrentTime();
	CString Time=CurTime.Format("%Y-%m-%d %H:%M:%S");
	GetDlgItem(IDC_B_T_START_TIME)->SetWindowText(Time);
	GetDlgItem(IDC_B_T_END_TIME)->SetWindowText(Time);
	//show list
	ShowBTRecord();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CBusTripDlg::ShowBTRecord()
{
	int i=0;
	CErrandRS ErrandRS(&Db);
	ErrandRS.Open();
	m_BTList.DeleteAllItems();
	while (!ErrandRS.IsEOF())
	{
		CString Str;
		m_BTList.InsertItem(i," ");
		Str.Format("%d",ErrandRS.m_ID);
		m_BTList.SetItemText(i,0,Str);
		m_BTList.SetItemText(i,1,ErrandRS.m_PERSON);
		//start time
		Str=ErrandRS.m_START_TIME.Format("%Y-%m-%d %H:%M:%S");
		m_BTList.SetItemText(i,2,Str);
		// end time
		Str=ErrandRS.m_END_TIME.Format("%Y-%m-%d %H:%M:%S");
		m_BTList.SetItemText(i,3,Str);
        m_BTList.SetItemText(i,4,ErrandRS.m_DESCRIPTION);
		ErrandRS.MoveNext();
		i++;
	}
	ErrandRS.Close();
}

void CBusTripDlg::OnDeleteBTRecord() 
{
	// TODO: Add your control notification handler code here
	int Index;
	CString Sql;
	POSITION pos=m_BTList.GetFirstSelectedItemPosition();
	if (pos==NULL)
	{
		return;
	}
	Index=m_BTList.GetNextSelectedItem(pos);
	Sql="delete * from ERRAND where ID="+m_BTList.GetItemText(Index,0);
	Db.ExecuteSQL(Sql);
	m_BTList.DeleteAllItems();
	ShowBTRecord();
}

void CBusTripDlg::OnBTCheck() 
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
	CErrandRS ErrandRS(&Db);
	CString StartTime,EndTime;
	StartTime=PDlg->m_StartTime.Format("%Y-%m-%d");
	EndTime=PDlg->m_EndTime.Format("%Y-%m-%d");
	//时间和员工检索条件都为真
	if (PDlg->m_CheckClerk==TRUE && PDlg->m_CheckTime==TRUE)
	{
		ErrandRS.m_strFilter="PERSON = '" + PDlg->m_ClerkID + "' and START_TIME >= #" +StartTime + "# and END_TIME <= #" + EndTime + "#";  
	}
	//时间检索条件为真，员工检索条件为假
	else if (PDlg->m_CheckTime==TRUE && PDlg->m_CheckClerk==FALSE)
	{
		ErrandRS.m_strFilter="START_TIME >= #" +StartTime + "# and END_TIME <= #" + EndTime + "#";
	}
	//时间检索条件为假，员工检索条件为真
	else
	{
		ErrandRS.m_strFilter="PERSON = '" + PDlg->m_ClerkID + "'";
	}
	//显示
	int i=0;
	CString Str;
    ErrandRS.Open();
	m_BTList.DeleteAllItems();
	while (!ErrandRS.IsEOF())
	{
		CString Str;
		m_BTList.InsertItem(i," ");
		Str.Format("%d",ErrandRS.m_ID);
		m_BTList.SetItemText(i,0,Str);
		m_BTList.SetItemText(i,1,ErrandRS.m_PERSON);
		//start time
		Str=ErrandRS.m_START_TIME.Format("%Y-%m-%d %H:%M:%S");
		m_BTList.SetItemText(i,2,Str);
		// end time
		Str=ErrandRS.m_END_TIME.Format("%Y-%m-%d %H:%M:%S");
		m_BTList.SetItemText(i,3,Str);
        m_BTList.SetItemText(i,4,ErrandRS.m_DESCRIPTION);
		ErrandRS.MoveNext();
		i++;
	}
	ErrandRS.Close();
}
