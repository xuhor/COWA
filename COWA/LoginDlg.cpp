// LoginDlg.cpp : implementation file
//

#include "stdafx.h"
#include "COWA.h"
#include "LoginDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLoginDlg dialog
//声明外部变量
extern CDatabase Db;

CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLoginDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLoginDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLoginDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialog)
	//{{AFX_MSG_MAP(CLoginDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLoginDlg message handlers

BOOL CLoginDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	((CComboBox *)GetDlgItem(IDC_COMBO1))->AddString("ZX");
	((CComboBox *)GetDlgItem(IDC_COMBO1))->SetCurSel(0);
	SetFont();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CLoginDlg::SetFont()
{
	LOGFONT LogFont;
	GetFont()->GetLogFont(&LogFont);
	LogFont.lfHeight+=LogFont.lfHeight/2;
	LogFont.lfWidth+=LogFont.lfWidth/2;
	//set typeface
	strcpy(LogFont.lfFaceName,"黑体");
	m_Font.CreateFontIndirect(&LogFont);  //
	GetDlgItem(IDC_LOGIN_STATIC)->SetFont(&m_Font);
}

void CLoginDlg::OnOK() 
{
	// TODO: Add extra validation here
	CPersonRS ReS(&Db);
	CString UserName,PassWord;
	CEncryption Encrypt;
	GetDlgItemText(IDC_NAME_EDIT,UserName);
	GetDlgItemText(IDC_PASSWORD_EDIT,PassWord);
	PassWord=Encrypt.Encrypt(PassWord,123);
    ReS.m_strFilter="ID= '" + UserName + "' and PASSWD = '" + PassWord + "' and AUTHORITY = '4'";
	ReS.Open();
	if (ReS.GetRecordCount()==1)
	{
		CDialog::OnOK();
	}
	else
	{
		MessageBox("登陆失败，请重新检查用户名、密码，注意大小写");
	}
}
