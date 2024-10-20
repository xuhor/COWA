#if !defined(AFX_LEAVEDLG_H__81B32605_4C33_4D6B_B2EA_97AFAAD0F8FE__INCLUDED_)
#define AFX_LEAVEDLG_H__81B32605_4C33_4D6B_B2EA_97AFAAD0F8FE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LeaveDlg.h : header file
//
#include "LeaveRS.h"
#include "counterRS.h"
/////////////////////////////////////////////////////////////////////////////
// CLeaveDlg dialog

class CLeaveDlg : public CPropertyPage
{
	DECLARE_DYNCREATE(CLeaveDlg)

// Construction
public:
	CLeaveDlg();
	~CLeaveDlg();

// Dialog Data
	//{{AFX_DATA(CLeaveDlg)
	enum { IDD = IDD_LEAVE_PAGE3 };
	CListCtrl	m_LeaveList;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CLeaveDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CLeaveDlg)
	afx_msg void OnChangeLClerkId();
	virtual BOOL OnInitDialog();
	afx_msg void OnAddLRecord();
	afx_msg void OnDeleteLRecord();
	afx_msg void OnLeaveCheck();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	void ShowLRecord();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LEAVEDLG_H__81B32605_4C33_4D6B_B2EA_97AFAAD0F8FE__INCLUDED_)
