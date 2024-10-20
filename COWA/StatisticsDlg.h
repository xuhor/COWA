#if !defined(AFX_STATISTICSDLG_H__74365360_F060_4590_A719_067E53F94472__INCLUDED_)
#define AFX_STATISTICSDLG_H__74365360_F060_4590_A719_067E53F94472__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// StatisticsDlg.h : header file
//
#include "StatisticsRS.h"
#include "counterRS.h"
/////////////////////////////////////////////////////////////////////////////
// CStatisticsDlg dialog

class CStatisticsDlg : public CDialog
{
// Construction
public:
	CStatisticsDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CStatisticsDlg)
	enum { IDD = IDD_STATISTICS };
	CListCtrl	m_S_List;
	BOOL	m_SCCheck;
	BOOL	m_SYMCheck;
	CString	m_strTime;
	CTime	m_ETime;
	CTime	m_STime;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStatisticsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CStatisticsDlg)
	afx_msg void OnSCheck();
	virtual BOOL OnInitDialog();
	afx_msg void OnChangeSClerkId();
	afx_msg void OnBeginToStat();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void ShowSRecord();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STATISTICSDLG_H__74365360_F060_4590_A719_067E53F94472__INCLUDED_)
