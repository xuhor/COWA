// COWADlg.h : header file
//

#if !defined(AFX_COWADLG_H__DE7DDA40_97BB_4281_86C3_018DA15DA35A__INCLUDED_)
#define AFX_COWADLG_H__DE7DDA40_97BB_4281_86C3_018DA15DA35A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "LoginDlg.h"
#include "SetTimeDlg.h"
#include "RecordDlg.h"
#include "StatisticsDlg.h"
/////////////////////////////////////////////////////////////////////////////
// CCOWADlg dialog

class CCOWADlg : public CDialog
{
// Construction
public:
	CCOWADlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCOWADlg)
	enum { IDD = IDD_COWA_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCOWADlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCOWADlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnRelogin();
	virtual void OnOK( );
	virtual void OnCancel();
	afx_msg void OnSetTime();
	afx_msg void OnCOWA();
	afx_msg void OnStatistics();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CFont m_Font;
	void SetFont();
public:
	~CCOWADlg();
	CRecordDlg *m_RecordDlg;
	CStatisticsDlg *m_StatDlg;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COWADLG_H__DE7DDA40_97BB_4281_86C3_018DA15DA35A__INCLUDED_)
