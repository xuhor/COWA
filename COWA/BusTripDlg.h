#if !defined(AFX_BUSTRIPDLG_H__6EA694F0_2754_4C03_BFB4_01219DF5B886__INCLUDED_)
#define AFX_BUSTRIPDLG_H__6EA694F0_2754_4C03_BFB4_01219DF5B886__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BusTripDlg.h : header file
//
#include "counterRS.h"
#include "ErrandRS.h"
/////////////////////////////////////////////////////////////////////////////
// CBusTripDlg dialog

class CBusTripDlg : public CPropertyPage
{
	DECLARE_DYNCREATE(CBusTripDlg)

// Construction
public:
	CBusTripDlg();
	~CBusTripDlg();

// Dialog Data
	//{{AFX_DATA(CBusTripDlg)
	enum { IDD = IDD_BUS_TRIP_PAGE4 };
	CListCtrl	m_BTList;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CBusTripDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CBusTripDlg)
	afx_msg void OnChangeBTClerkId();
	afx_msg void OnAddBTRecord();
	virtual BOOL OnInitDialog();
	afx_msg void OnDeleteBTRecord();
	afx_msg void OnBTCheck();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	void ShowBTRecord();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BUSTRIPDLG_H__6EA694F0_2754_4C03_BFB4_01219DF5B886__INCLUDED_)
