// LeaveDlg.cpp : implementation file
//

#include "stdafx.h"
#include "COWA.h"
#include "LeaveDlg.h"
#include "RecordDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLeaveDlg property page
extern CDatabase Db;

IMPLEMENT_DYNCREATE(CLeaveDlg, CPropertyPage)

CLeaveDlg::CLeaveDlg() : CPropertyPage(CLeaveDlg::IDD)
{
	//{{AFX_DATA_INIT(CLeaveDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CLeaveDlg::~CLeaveDlg()
{
}

void CLeaveDlg::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLeaveDlg)
	DDX_Control(pDX, IDC_LEAVE_LIST, m_LeaveList);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLeaveDlg, CPropertyPage)
	//{{AFX_MSG_MAP(CLeaveDlg)
	ON_EN_CHANGE(IDC_L_CLERK_ID, OnChangeLClerkId)
	ON_BN_CLICKED(IDC_ADD_L_RECORD, OnAddLRecord)
	ON_BN_CLICKED(IDC_DELETE_L_RECORD, OnDeleteLRecord)
	ON_BN_CLICKED(IDC_LEAVE_CHECK, OnLeaveCheck)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLeaveDlg message handlers

void CLeaveDlg::OnChangeLClerkId() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CPropertyPage::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	CString PersonD;
	CPersonRS PersonRS(&Db);
	GetDlgItemText(IDC_L_CLERK_ID,PersonD);
	PersonRS.m_strFilter="ID = '"+PersonD + "'";
	PersonRS.Open();
	if (PersonRS.GetRecordCount()==1)
	{
		SetDlgItemText(IDC_L_CLERK_NAME,PersonRS.m_NAME);
	}
	else
	{
		SetDlgItemText(IDC_L_CLERK_NAME,"");
	}
	PersonRS.Close();
	// TODO: Add your control notification handler code here
	
}

BOOL CLeaveDlg::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_LeaveList.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	m_LeaveList.InsertColumn(0,"ID",LVCFMT_LEFT,60);
	m_LeaveList.InsertColumn(1,"PERSON",LVCFMT_LEFT,70);
	m_LeaveList.InsertColumn(2,"START_TIME",LVCFMT_LEFT,110);
	m_LeaveList.InsertColumn(3,"END_TIME",LVCFMT_LEFT,110);
	m_LeaveList.InsertColumn(4,"REASON",LVCFMT_LEFT,110);
	//��ʼ���ؼ�IDC_L_START_TIME��IDC_L_END_TIME��ʾʱ��
	CTime CurTime;
	CurTime=CTime::GetCurrentTime();
	CString Time=CurTime.Format("%Y-%m-%d %H:%M:%S");
	GetDlgItem(IDC_L_START_TIME)->SetWindowText(Time);
	GetDlgItem(IDC_L_END_TIME)->SetWindowText(Time);
	//show list
	ShowLRecord();


	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CLeaveDlg::ShowLRecord()
{
	int i=0;
	CLeaveRS LeaveRS(&Db);
	LeaveRS.Open();
	m_LeaveList.DeleteAllItems();
	while (!LeaveRS.IsEOF())
	{
		CString Str;
		m_LeaveList.InsertItem(i," ");
		Str.Format("%d",LeaveRS.m_ID);
		m_LeaveList.SetItemText(i,0,Str);
		m_LeaveList.SetItemText(i,1,LeaveRS.m_PERSON);
		//start time
		Str=LeaveRS.m_START_TIME.Format("%Y-%m-%d %H:%M:%S");
		m_LeaveList.SetItemText(i,2,Str);
		// end time
		Str=LeaveRS.m_END_TIME.Format("%Y-%m-%d %H:%M:%S");
		m_LeaveList.SetItemText(i,3,Str);
        m_LeaveList.SetItemText(i,4,LeaveRS.m_REASON);
		LeaveRS.MoveNext();
		i++;
	}
	LeaveRS.Close();
}

void CLeaveDlg::OnAddLRecord() 
{
	// TODO: Add your control notification handler code here
	//�����Ϣ�Ƿ������ж�����
	//���COUNTER����
	int CounterA;            //���ڼ������棬������ӿ��ڼ�¼ʱ��ֵ����CRecordset��������ĳ�Ա����m_ID
	CcounterRS CounterRS(&Db); 
	CounterRS.m_strFilter = "ID='O'"; 
	CounterRS.Open(); 
	CounterRS.Edit(); 
	CounterRS.m_COUNTER_VALUE++; 
	CounterA=CounterRS.m_COUNTER_VALUE;
	CounterRS.Update(); 
	CounterRS.Close(); 
	//���LEAVE��¼
	CLeaveRS LeaveRS(&Db);
	LeaveRS.Open();
	LeaveRS.AddNew();
	//get ID
	LeaveRS.m_ID=CounterA;
	//get PERSON
	CString Temp;
	GetDlgItem(IDC_L_CLERK_ID)->GetWindowText(Temp);
	LeaveRS.m_PERSON=Temp;
	//��ȡʱ��
	CString StartTime,EndTime;
	int Year,Month,Day,Hour,Minute,Second;
	//��ȡ�����ʼʱ��
	GetDlgItem(IDC_L_START_TIME)->GetWindowText(StartTime);
	sscanf(StartTime.Left(4), "%d", &Year); // �õ���
	sscanf(StartTime.Mid(5,2), "%d", &Month); // �õ���
	sscanf(StartTime.Mid(8,2), "%d", &Day); // �õ���
	sscanf(StartTime.Mid(11,2), "%d", &Hour); // �õ�ʱ
	sscanf(StartTime.Mid(14,2), "%d", &Minute); // �õ���
	sscanf(StartTime.Mid(17,2), "%d", &Second); // �õ���
	CTime STime(Year,Month,Day,Hour,Minute,Second);
	LeaveRS.m_START_TIME=STime;
	//��ȡ��ٽ���ʱ��
	GetDlgItem(IDC_L_END_TIME)->GetWindowText(StartTime);
	sscanf(StartTime.Left(4), "%d", &Year); // �õ���
	sscanf(StartTime.Mid(5,2), "%d", &Month); // �õ���
	sscanf(StartTime.Mid(8,2), "%d", &Day); // �õ���
	sscanf(StartTime.Mid(11,2), "%d", &Hour); // �õ�ʱ
	sscanf(StartTime.Mid(14,2), "%d", &Minute); // �õ���
	sscanf(StartTime.Mid(17,2), "%d", &Second); // �õ���
	CTime ETime(Year,Month,Day,Hour,Minute,Second);
	LeaveRS.m_END_TIME=ETime;
	//get REASON
    GetDlgItem(IDC_LEAVE_REASON)->GetWindowText(Temp);
	LeaveRS.m_REASON=Temp;
	LeaveRS.Update();
	//show list
	ShowLRecord();
}

void CLeaveDlg::OnDeleteLRecord() 
{
	// TODO: Add your control notification handler code here
	int Index;
	CString Sql;
	POSITION pos=m_LeaveList.GetFirstSelectedItemPosition();
	if (pos==NULL)
	{
		return;
	}
	Index=m_LeaveList.GetNextSelectedItem(pos);
	Sql="delete * from LEAVE where ID="+m_LeaveList.GetItemText(Index,0);
	Db.ExecuteSQL(Sql);
	m_LeaveList.DeleteAllItems();
	ShowLRecord();
}

void CLeaveDlg::OnLeaveCheck() 
{
	// TODO: Add your control notification handler code here
	CRecordDlg *PDlg=(CRecordDlg *)(GetParent()->GetParent());
	//���ݸ�ֵ
	PDlg->UpdateData();
	//ʱ���Ա������������Ϊ��
	if (PDlg->m_CheckClerk==FALSE && PDlg->m_CheckTime==FALSE)
	{
		MessageBox("��ѡ���������","��ʾ",MB_OK | MB_ICONINFORMATION);
		return;
	}
    //
	CLeaveRS LeaveRS(&Db);
	CString StartTime,EndTime;
	StartTime=PDlg->m_StartTime.Format("%Y-%m-%d");
	EndTime=PDlg->m_EndTime.Format("%Y-%m-%d");
	//ʱ���Ա������������Ϊ��
	if (PDlg->m_CheckClerk==TRUE && PDlg->m_CheckTime==TRUE)
	{
		LeaveRS.m_strFilter="PERSON = '" + PDlg->m_ClerkID + "' and START_TIME >= #" +StartTime + "# and END_TIME <= #" + EndTime + "#";  
	}
	//ʱ���������Ϊ�棬Ա����������Ϊ��
	else if (PDlg->m_CheckTime==TRUE && PDlg->m_CheckClerk==FALSE)
	{
		LeaveRS.m_strFilter="START_TIME >= #" +StartTime + "# and END_TIME <= #" + EndTime + "#";
	}
	//ʱ���������Ϊ�٣�Ա����������Ϊ��
	else
	{
		LeaveRS.m_strFilter="PERSON = '" + PDlg->m_ClerkID + "'";
	}
	//��ʾ
	int i=0;
	CString Str;
    LeaveRS.Open();
	m_LeaveList.DeleteAllItems();
	while (!LeaveRS.IsEOF())
	{
		CString Str;
		m_LeaveList.InsertItem(i," ");
		Str.Format("%d",LeaveRS.m_ID);
		m_LeaveList.SetItemText(i,0,Str);
		m_LeaveList.SetItemText(i,1,LeaveRS.m_PERSON);
		//start time
		Str=LeaveRS.m_START_TIME.Format("%Y-%m-%d %H:%M:%S");
		m_LeaveList.SetItemText(i,2,Str);
		// end time
		Str=LeaveRS.m_END_TIME.Format("%Y-%m-%d %H:%M:%S");
		m_LeaveList.SetItemText(i,3,Str);
        m_LeaveList.SetItemText(i,4,LeaveRS.m_REASON);
		LeaveRS.MoveNext();
		i++;
	}
	LeaveRS.Close();
}
