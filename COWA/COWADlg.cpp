// COWADlg.cpp : implementation file
//

#include "stdafx.h"
#include "COWA.h"
#include "COWADlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCOWADlg dialog

CCOWADlg::CCOWADlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCOWADlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCOWADlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	//
	m_RecordDlg=NULL;//将指向CRecordDlg类的指针设为空
	m_StatDlg=NULL;//将指向CStatisticsDlg类的指针设为空
}

void CCOWADlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCOWADlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCOWADlg, CDialog)
	//{{AFX_MSG_MAP(CCOWADlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RELOGIN, OnRelogin)
	ON_BN_CLICKED(IDC_SetTime, OnSetTime)
	ON_BN_CLICKED(IDC_C_O_W_A, OnCOWA)
	ON_BN_CLICKED(IDC_STATISTICS, OnStatistics)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCOWADlg message handlers

BOOL CCOWADlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	SetFont();
	GetDlgItem(IDC_BITMAP)->SetFocus();
	
	return FALSE;  // return TRUE  unless you set the focus to a control
}

void CCOWADlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCOWADlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCOWADlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CCOWADlg::SetFont()
{
	LOGFONT LogFont;
	GetFont()->GetLogFont(&LogFont);
	LogFont.lfHeight+=LogFont.lfHeight;
	LogFont.lfWidth+=LogFont.lfWidth;
	//set typeface
	strcpy(LogFont.lfFaceName,"黑体");
	m_Font.CreateFontIndirect(&LogFont);  //
	GetDlgItem(IDC_COWA_STATIC)->SetFont(&m_Font);
}

void CCOWADlg::OnRelogin()
{
	ShowWindow(SW_HIDE);
	CLoginDlg LoginDlg;
	if (LoginDlg.DoModal()==IDOK)
	{
		ShowWindow(SW_SHOW);
	}
	else
	{
		CDialog::OnOK();
	}
}

void CCOWADlg::OnOK()
{
	return;
}


void CCOWADlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

void CCOWADlg::OnSetTime() 
{
	// TODO: Add your control notification handler code here
	CSetTimeDlg Dlg;
	Dlg.DoModal();
}

void CCOWADlg::OnCOWA()  // check on work attendance
{
	// TODO: Add your control notification handler code here
	if (m_RecordDlg==NULL)
	{
		m_RecordDlg=new CRecordDlg;
		m_RecordDlg->Create(IDD_RECORD_DIG,this);
		m_RecordDlg->ShowWindow(SW_SHOW);
	}
	else
	{
		m_RecordDlg->ShowWindow(SW_SHOW);
	}
	
}

void CCOWADlg::OnStatistics() 
{
	// TODO: Add your control notification handler code here
	if (m_StatDlg==NULL)
	{
		m_StatDlg=new CStatisticsDlg;
		m_StatDlg->Create(IDD_STATISTICS,this);
		m_StatDlg->ShowWindow(SW_SHOW);
	}
	else
	{
		m_StatDlg->ShowWindow(SW_SHOW);
	}
}

CCOWADlg::~CCOWADlg()
{
	if (!m_RecordDlg==NULL)
	{
		delete m_RecordDlg;
	}
	if (!m_StatDlg==NULL)
	{
		delete m_StatDlg;
	}
}