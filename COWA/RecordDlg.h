#if !defined(AFX_RECORDDLG_H__69288AAD_1EBD_4B34_BC78_19A515C1C760__INCLUDED_)
#define AFX_RECORDDLG_H__69288AAD_1EBD_4B34_BC78_19A515C1C760__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RecordDlg.h : header file
//
#include "AttendanceDlg.h"
#include "OvertimeDlg.h"
#include "LeaveDlg.h"
#include "BusTripDlg.h"
/////////////////////////////////////////////////////////////////////////////
// CRecordDlg dialog

class CRecordDlg : public CDialog
{
// Construction
public:
	CRecordDlg(CWnd* pParent = NULL);   // standard constructor

	CAttendanceDlg m_Page1; // ³öÇÚÒ³
	COvertimeDlg m_Page2; // ¼Ó°àÒ³
	CLeaveDlg m_Page3; // Çë¼ÙÒ³
	CBusTripDlg m_Page4; // ³ö²îÒ³
	CPropertySheet m_ProSheet;

// Dialog Data
	//{{AFX_DATA(CRecordDlg)
	enum { IDD = IDD_RECORD_DIG };
	BOOL	m_CheckTime;
	BOOL	m_CheckClerk;
	CTime	m_StartTime;
	CTime	m_EndTime;
	CString	m_ClerkID;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRecordDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CRecordDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnChangeClerkId();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RECORDDLG_H__69288AAD_1EBD_4B34_BC78_19A515C1C760__INCLUDED_)
