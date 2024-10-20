#if !defined(AFX_ATTENDANCEDLG_H__9E7E094A_99F0_4FF7_BC33_D40860AAE775__INCLUDED_)
#define AFX_ATTENDANCEDLG_H__9E7E094A_99F0_4FF7_BC33_D40860AAE775__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AttendanceDlg.h : header file
//
#include "AttendanceRS.h"
#include "DepartmentRS.h"
#include "PersonRS.h"
#include "counterRS.h"
/////////////////////////////////////////////////////////////////////////////
// CAttendanceDlg dialog

class CAttendanceDlg : public CPropertyPage
{
	DECLARE_DYNCREATE(CAttendanceDlg)

// Construction
public:
	void AddSingleRecord(CString personID);
	CAttendanceDlg();
	~CAttendanceDlg();

// Dialog Data
	//{{AFX_DATA(CAttendanceDlg)
	enum { IDD = IDD_ATTANDENCE_PAGE1 };
	CListCtrl	m_AttendanceList;
	int		m_InOrOut;
	int		m_AddClerkType;
	CString	m_InOutTime;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CAttendanceDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CAttendanceDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnChangeDepartId();
	afx_msg void OnChangeClerkNum();
	afx_msg void OnAddRecord();
	afx_msg void OnDeleteRecord();
	afx_msg void OnCheckByC();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	void ShowIOTime();
	void ShowRecordset();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ATTENDANCEDLG_H__9E7E094A_99F0_4FF7_BC33_D40860AAE775__INCLUDED_)
