#if !defined(AFX_OVERTIMEDLG_H__90F9EF96_0DAB_444D_90B2_68475B811593__INCLUDED_)
#define AFX_OVERTIMEDLG_H__90F9EF96_0DAB_444D_90B2_68475B811593__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OvertimeDlg.h : header file
//
#include "DepartmentRS.h"
#include "OvertimeRS.h"
#include "counterRS.h"
/////////////////////////////////////////////////////////////////////////////
// COvertimeDlg dialog

class COvertimeDlg : public CPropertyPage
{
	DECLARE_DYNCREATE(COvertimeDlg)

// Construction
public:
	COvertimeDlg();
	~COvertimeDlg();

// Dialog Data
	//{{AFX_DATA(COvertimeDlg)
	enum { IDD = IDD_OVERTIME_PAGE2 };
	CListCtrl	m_OvertimeList;
	CTime	m_CurTime;
	int		m_OvertimeHours;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(COvertimeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(COvertimeDlg)
	afx_msg void OnChangeClerkId();
	virtual BOOL OnInitDialog();
	afx_msg void OnAddOvertimeR();
	afx_msg void OnDeleteOvertimR();
	afx_msg void OnOvertimrSearch();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	void ShowList();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OVERTIMEDLG_H__90F9EF96_0DAB_444D_90B2_68475B811593__INCLUDED_)
