// RecordDlg.cpp : implementation file
//

#include "stdafx.h"
#include "COWA.h"
#include "RecordDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRecordDlg dialog
extern CDatabase Db;

CRecordDlg::CRecordDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRecordDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRecordDlg)
	m_CheckTime = FALSE;
	m_CheckClerk = FALSE;
	m_StartTime = 0;
	m_EndTime = 0;
	m_ClerkID = _T("");
	//}}AFX_DATA_INIT
}


void CRecordDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRecordDlg)
	DDX_Check(pDX, IDC_CHECK_TIME, m_CheckTime);
	DDX_Check(pDX, IDC_CHECK_CLERK, m_CheckClerk);
	DDX_DateTimeCtrl(pDX, IDC_START_TIME, m_StartTime);
	DDX_DateTimeCtrl(pDX, IDC_END_TIME, m_EndTime);
	DDX_Text(pDX, IDC_CLERK_ID, m_ClerkID);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRecordDlg, CDialog)
	//{{AFX_MSG_MAP(CRecordDlg)
	ON_EN_CHANGE(IDC_CLERK_ID, OnChangeClerkId)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRecordDlg message handlers

BOOL CRecordDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_ProSheet.AddPage(&m_Page1); 
	m_ProSheet.AddPage(&m_Page2); 
	m_ProSheet.AddPage(&m_Page3); 
	m_ProSheet.AddPage(&m_Page4); 
	
	m_ProSheet.Create(this, WS_CHILD | WS_VISIBLE, WS_EX_CONTROLPARENT); // 创建窗口
	m_ProSheet.ModifyStyle( 0, WS_TABSTOP ); // 修改风格
	
	// 设置窗口位置
	m_ProSheet.SetWindowPos( NULL, 0, 110, 5, 0, SWP_NOZORDER | SWP_NOSIZE | SWP_NOACTIVATE );
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CRecordDlg::OnChangeClerkId() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	CString Name;
	CPersonRS PersonRS(&Db);
	GetDlgItemText(IDC_CLERK_ID,Name);
	PersonRS.m_strFilter="ID = '"+Name + "'";
	PersonRS.Open();
	if (PersonRS.GetRecordCount()==1)
	{
		SetDlgItemText(IDC_CLERKNAME,PersonRS.m_NAME);
	}
	else
	{
		SetDlgItemText(IDC_CLERKNAME,"");
	}
	PersonRS.Close();
	// TODO: Add your control notification handler code here
	
}
