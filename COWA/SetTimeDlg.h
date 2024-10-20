#if !defined(AFX_SETTIMEDLG_H__9CA0499A_B691_4512_99E0_EC30EADC49A7__INCLUDED_)
#define AFX_SETTIMEDLG_H__9CA0499A_B691_4512_99E0_EC30EADC49A7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SetTimeDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSetTimeDlg dialog

class CSetTimeDlg : public CDialog
{
// Construction
public:
	CSetTimeDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSetTimeDlg)
	enum { IDD = IDD_SET_DIALOG };
	CTime	m_AM_On;
	CTime	m_AM_Off;
	CTime	m_PM_Off;
	CTime	m_PM_On;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSetTimeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSetTimeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnChange();
	afx_msg void OnReset();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void InitTime();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETTIMEDLG_H__9CA0499A_B691_4512_99E0_EC30EADC49A7__INCLUDED_)
