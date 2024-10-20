// SetTimeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "COWA.h"
#include "SetTimeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSetTimeDlg dialog


CSetTimeDlg::CSetTimeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSetTimeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSetTimeDlg)
	m_AM_On = 0;
	m_AM_Off = 0;
	m_PM_Off = 0;
	m_PM_On = 0;
	//}}AFX_DATA_INIT
}


void CSetTimeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSetTimeDlg)
	DDX_DateTimeCtrl(pDX, IDC_AM_ON, m_AM_On);
	DDX_DateTimeCtrl(pDX, IDC_AM_OFF, m_AM_Off);
	DDX_DateTimeCtrl(pDX, IDC_PM_OFF, m_PM_Off);
	DDX_DateTimeCtrl(pDX, IDC_PM_ON, m_PM_On);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSetTimeDlg, CDialog)
	//{{AFX_MSG_MAP(CSetTimeDlg)
	ON_BN_CLICKED(IDC_CHANGE, OnChange)
	ON_BN_CLICKED(IDC_RESET, OnReset)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetTimeDlg message handlers

BOOL CSetTimeDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	InitTime();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CSetTimeDlg::InitTime()                       //判断?????????????
{
	int Hour,Minute,Second;
	char WorkTime1[4][9];
	CString WorkTime[4];
	CString FilePath=".\\WorkTime.ini";
	GetPrivateProfileString("WorkTime", "Time1", "08:00:00", WorkTime1[0], 9, FilePath);
	GetPrivateProfileString("WorkTime", "Time2", "12:00:00", WorkTime1[1], 9, FilePath);
	GetPrivateProfileString("WorkTime", "Time3", "14:00:00", WorkTime1[2], 9, FilePath);
	GetPrivateProfileString("WorkTime", "Time4", "18:00:00", WorkTime1[3], 9, FilePath);
    //将char *类型的值转为CString类型的值
	for (int i=0;i<4;i++)
	{
		WorkTime[i]=WorkTime1[i];
	}
	//	
	sscanf(WorkTime[0].Left(2), "%d", &Hour);		
	sscanf(WorkTime[0].Mid(3,2), "%d", &Minute);	
	sscanf(WorkTime[0].Mid(6,2), "%d", &Second);	
	CTime AM_On(2013,4,1,Hour,Minute,Second);	
	//
	sscanf(WorkTime[1].Left(2), "%d", &Hour);		
	sscanf(WorkTime[1].Mid(3,2), "%d", &Minute);	
	sscanf(WorkTime[1].Mid(6,2), "%d", &Second);	
	CTime AM_Off(2013,4,1,Hour,Minute,Second);
	//
	sscanf(WorkTime[2].Left(2), "%d", &Hour);		
	sscanf(WorkTime[2].Mid(3,2), "%d", &Minute);	
	sscanf(WorkTime[2].Mid(6,2), "%d", &Second);	
	CTime PM_On(2013,4,1,Hour,Minute,Second);
	//
	sscanf(WorkTime[3].Left(2), "%d", &Hour);		
	sscanf(WorkTime[3].Mid(3,2), "%d", &Minute);	
	sscanf(WorkTime[3].Mid(6,2), "%d", &Second);	
	CTime PM_Off(2013,4,1,Hour,Minute,Second);
	//
	m_AM_On=AM_On;
	m_AM_Off=AM_Off;
	m_PM_On=PM_On;
	m_PM_Off=PM_Off;
	UpdateData(FALSE);
}

void CSetTimeDlg::OnChange() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	CString AM_On=m_AM_On.Format("%H:%M:%S");
	CString AM_Off=m_AM_Off.Format("%H:%M:%S");
	CString PM_On=m_PM_On.Format("%H:%M:%S");
	CString PM_Off=m_PM_Off.Format("%H:%M:%S");
	//
	CString FilePath=".\\WorkTime.ini";

	WritePrivateProfileString("WorkTime", "Time1",AM_On, FilePath);
	WritePrivateProfileString("WorkTime", "Time2",AM_Off, FilePath);
	WritePrivateProfileString("WorkTime", "Time3",PM_On, FilePath);
	WritePrivateProfileString("WorkTime", "Time4",PM_Off, FilePath);
}

void CSetTimeDlg::OnReset() 
{
	// TODO: Add your control notification handler code here
	CString FilePath=".\\WorkTime.ini";
	WritePrivateProfileString("WorkTime", "Time1","08:00:00", FilePath);
	WritePrivateProfileString("WorkTime", "Time2","12:00:00", FilePath);
	WritePrivateProfileString("WorkTime", "Time3","14:00:00", FilePath);
	WritePrivateProfileString("WorkTime", "Time4","18:00:00", FilePath);
	InitTime();
}
