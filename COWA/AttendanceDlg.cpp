// AttendanceDlg.cpp : implementation file
//

#include "stdafx.h"
#include "COWA.h"
#include "AttendanceDlg.h"
#include "RecordDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAttendanceDlg property page

IMPLEMENT_DYNCREATE(CAttendanceDlg, CPropertyPage)

extern CDatabase Db;

CAttendanceDlg::CAttendanceDlg() : CPropertyPage(CAttendanceDlg::IDD)
{
	//{{AFX_DATA_INIT(CAttendanceDlg)
	m_InOrOut = 1;
	m_AddClerkType = 2;
	m_InOutTime = _T("");
	//}}AFX_DATA_INIT
}

CAttendanceDlg::~CAttendanceDlg()
{
}

void CAttendanceDlg::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAttendanceDlg)
	DDX_Control(pDX, IDC_LIST1, m_AttendanceList);                   ////???
	DDX_Radio(pDX, IDC_OUT, m_InOrOut);
	DDX_Radio(pDX, IDC_ALL_CLERK, m_AddClerkType);
	DDX_Text(pDX, IDC_IN_OUT_TIME, m_InOutTime);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAttendanceDlg, CPropertyPage)
	//{{AFX_MSG_MAP(CAttendanceDlg)
	ON_EN_CHANGE(IDC_DEPART_ID, OnChangeDepartId)
	ON_EN_CHANGE(IDC_CLERK_NUM, OnChangeClerkNum)
	ON_BN_CLICKED(IDC_ADD_RECORD, OnAddRecord)
	ON_BN_CLICKED(IDC_DELETE_RECORD, OnDeleteRecord)
	ON_BN_CLICKED(IDC_CHECK_BY_C, OnCheckByC)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAttendanceDlg message handlers

BOOL CAttendanceDlg::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_AttendanceList.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	m_AttendanceList.InsertColumn(0,"ID",LVCFMT_LEFT,90);
	m_AttendanceList.InsertColumn(1,"PERSON",LVCFMT_LEFT,110);
	m_AttendanceList.InsertColumn(2,"IN_OUT",LVCFMT_LEFT,90);
	m_AttendanceList.InsertColumn(3,"IO_TIME",LVCFMT_LEFT,160);
	//invoke ShowRecordset to show data
	ShowRecordset();
    ShowIOTime(); 

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CAttendanceDlg::ShowRecordset()
{
	int i=0;
	CString str1;
	CAttendanceRS Re1(&Db);
	Re1.Open();
	m_AttendanceList.DeleteAllItems();
	while (!Re1.IsEOF())
	{
		str1.Format("%d",Re1.m_ID);
		m_AttendanceList.InsertItem(i," ");
		m_AttendanceList.SetItemText(i,0,str1);
		m_AttendanceList.SetItemText(i,1,Re1.m_PERSON);
		m_AttendanceList.SetItemText(i,2,Re1.m_IN_OUT);
		str1=Re1.m_IO_TIME.Format("%Y-%m-%d %H:%M:%S");
		m_AttendanceList.SetItemText(i,3,str1);
		Re1.MoveNext();
		i++;
	}
	Re1.Close();
}

void CAttendanceDlg::OnChangeDepartId() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CPropertyPage::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	CString DepartID;
	CDepartmentRS DepartRS(&Db);
	GetDlgItemText(IDC_DEPART_ID,DepartID);
	DepartRS.m_strFilter="ID = '"+DepartID + "'";
	DepartRS.Open();
	if (DepartRS.GetRecordCount()==1)
	{
		SetDlgItemText(IDC_DEPART_NAME,DepartRS.m_NAME);
	}
	else
	{
		SetDlgItemText(IDC_DEPART_NAME,"");
	}
	DepartRS.Close();
	// TODO: Add your control notification handler code here
	
}

void CAttendanceDlg::OnChangeClerkNum() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CPropertyPage::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	CString Name;
	CPersonRS PersonRS(&Db);
	GetDlgItemText(IDC_CLERK_NUM,Name);
	PersonRS.m_strFilter="ID = '"+Name + "'";
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

void CAttendanceDlg::ShowIOTime()
{
	CTime Time=CTime::GetCurrentTime();
	m_InOutTime=Time.Format("%Y-%m-%d %H:%M:%S");
	UpdateData(FALSE);
//	GetDlgItem(IDC_IN_OUT_TIME)->SetWindowText(m_InOutTime);
	
}

void CAttendanceDlg::OnAddRecord() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	switch (m_AddClerkType)
	{
		//添加所有员工考勤记录
	case 0:
		{
			CPersonRS AllPeRS(&Db);
			AllPeRS.m_strFilter="STATE = 'T'";
			AllPeRS.Open();
			while (!AllPeRS.IsEOF())
			{
				//ClerkID=AllPeRS.m_ID;
				AddSingleRecord(AllPeRS.m_ID);
				AllPeRS.MoveNext();
			}
			AllPeRS.Close();
			ShowRecordset(); //重新显示列表
			MessageBox("所有员工考勤记录添加成功","提示",MB_OK | MB_ICONINFORMATION);
		}
		break;
		//添加部门员工考勤记录
	case 1:
		{
			if (GetDlgItem(IDC_DEPART_NAME)->GetWindowTextLength()==0)
			{
				MessageBox("请输入部门信息","提示",MB_OK | MB_ICONINFORMATION);
				break;
			}
			CPersonRS PersonRS(&Db);
			CString DepartName,ClerkID;
			GetDlgItemText(IDC_DEPART_ID,DepartName);
			PersonRS.m_strFilter="DEPARTMENT = '" + DepartName + "'";
			PersonRS.Open();
			while (!PersonRS.IsEOF())
			{
				ClerkID=PersonRS.m_ID;
				AddSingleRecord(ClerkID);
				PersonRS.MoveNext();
			}
			PersonRS.Close();
			ShowRecordset();//重新显示列表
			MessageBox("部门员工考勤记录添加成功","提示",MB_OK | MB_ICONINFORMATION);
		}
		break;
		///////////////添加单个员工考勤记录
	case 2:
		{
			if (GetDlgItem(IDC_CLERK_NAME)->GetWindowTextLength()==0)
			{
				MessageBox("请先输入员工信息","提示",MB_OK | MB_ICONINFORMATION);
				break;
			}
			CString ClerkID;
			GetDlgItemText(IDC_CLERK_NUM,ClerkID);
			AddSingleRecord(ClerkID);//add record
			ShowRecordset();//重新显示列表
			MessageBox("员工考勤记录添加成功","提示",MB_OK | MB_ICONINFORMATION);
		}
		break;
	default:
		{
			break;
		}
	}
}

void CAttendanceDlg::AddSingleRecord(CString personID)
{
	int CounterA;            //考勤计数保存，后面添加考勤记录时赋值给类CRecordset的派生类的成员函数m_ID
	CcounterRS CounterRS(&Db); 
	CounterRS.m_strFilter = "ID='A'"; 
	CounterRS.Open(); 
	CounterRS.Edit(); 
	CounterRS.m_COUNTER_VALUE++; 
	CounterA=CounterRS.m_COUNTER_VALUE;
	CounterRS.Update(); 
	CounterRS.Close(); 
	//
	UpdateData(FALSE);
	CAttendanceRS AttRS(&Db);
	AttRS.Open();
	AttRS.AddNew();
	CString IO; 
	//add ID
	AttRS.m_ID=CounterA;
	//add person
    AttRS.m_PERSON=personID;
	//add IN_OUT
	CString StrIO; 
	if (m_InOrOut==0)
	{
		AttRS.m_IN_OUT="O";
	}
	else
	{
		AttRS.m_IN_OUT="I";
	}
	//add IO_TIME
	int Year,Month,Day,Hour,Minute,Second; 
	sscanf(m_InOutTime.Left(4), "%d", &Year); 
	sscanf(m_InOutTime.Mid(5,2), "%d", &Month); 
	sscanf(m_InOutTime.Mid(8,2), "%d", &Day); 
	sscanf(m_InOutTime.Mid(11,2), "%d", &Hour); 
	sscanf(m_InOutTime.Mid(14,2), "%d", &Minute); 
	sscanf(m_InOutTime.Mid(14,2), "%d", &Second); 
	CTime IO_Time(Year,Month,Day,Hour,Minute,Second);
	AttRS.m_IO_TIME=IO_Time;
	AttRS.Update();
	AttRS.Close();
}

void CAttendanceDlg::OnDeleteRecord() 
{
	// TODO: Add your control notification handler code here
	int Index;
	CString Sql;
	POSITION pos=m_AttendanceList.GetFirstSelectedItemPosition();
	if (pos==NULL)
	{
		return;
	}
	Index=m_AttendanceList.GetNextSelectedItem(pos);
	Sql="delete * from ATTENDANCE where ID="+m_AttendanceList.GetItemText(Index,0);
	Db.ExecuteSQL(Sql);
	m_AttendanceList.DeleteAllItems();
	ShowRecordset();
}

void CAttendanceDlg::OnCheckByC() 
{
	// TODO: Add your control notification handler code here
	CRecordDlg *PDlg=(CRecordDlg *)(GetParent()->GetParent());
	PDlg->UpdateData();
	//时间和员工检索条件都为假
	if (PDlg->m_CheckClerk==FALSE && PDlg->m_CheckTime==FALSE)
	{
		MessageBox("请选择检索条件","提示",MB_OK | MB_ICONINFORMATION);
		return;
	}
    //
	CAttendanceRS AttRS(&Db);
	CString StartTime,EndTime;
	StartTime=PDlg->m_StartTime.Format("%Y-%m-%d");
	EndTime=PDlg->m_EndTime.Format("%Y-%m-%d");
	//时间和员工检索条件都为真
	if (PDlg->m_CheckClerk==TRUE && PDlg->m_CheckTime==TRUE)
	{
		AttRS.m_strFilter="PERSON = '" + PDlg->m_ClerkID + "' and IO_TIME >= #" +StartTime + "# and IO_TIME <= #" + EndTime + "#";  
	}
	//时间检索条件为真，员工检索条件为假
	else if (PDlg->m_CheckTime==TRUE && PDlg->m_CheckClerk==FALSE)
	{
		AttRS.m_strFilter="IO_TIME >= #" +StartTime + "# and IO_TIME <= #" + EndTime + "#";
	}
	//时间检索条件为假，员工检索条件为真
	else
	{
		AttRS.m_strFilter="PERSON = '" + PDlg->m_ClerkID + "'";
	}
	//显示
	int i=0;
	CString Str;
    AttRS.Open();
	m_AttendanceList.DeleteAllItems();
	while (!AttRS.IsEOF())
	{
		Str.Format("%d",AttRS.m_ID);
		m_AttendanceList.InsertItem(i," ");
		m_AttendanceList.SetItemText(i,0,Str);
		m_AttendanceList.SetItemText(i,1,AttRS.m_PERSON);
		m_AttendanceList.SetItemText(i,2,AttRS.m_IN_OUT);
		Str=AttRS.m_IO_TIME.Format("%Y-%m-%d %H:%M:%S");
		m_AttendanceList.SetItemText(i,3,Str);
		AttRS.MoveNext();
		i++;
	}
	AttRS.Close();
// 	CString str="2005-3-23 20:50:00";
// 	CAttendanceRS rs(&Db);
// 	rs.m_strFilter="IO_TIME< #" + str + "#";
// 	rs.Open();
//     while (!rs.IsEOF())
// 	{
// 		MessageBox(rs.m_PERSON);
// 		rs.MoveNext();
// 	}
// 	rs.Close();

	
}
