#if !defined(AFX_COUNTERRS_H__4588682F_15AD_4964_BD42_81BAD77E520E__INCLUDED_)
#define AFX_COUNTERRS_H__4588682F_15AD_4964_BD42_81BAD77E520E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// counterRS.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CcounterRS recordset

class CcounterRS : public CRecordset
{
public:
	CcounterRS(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CcounterRS)

// Field/Param Data
	//{{AFX_FIELD(CcounterRS, CRecordset)
	CString	m_ID;
	int		m_COUNTER_VALUE;
	CString	m_DESCRIPTION;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CcounterRS)
	public:
	virtual CString GetDefaultConnect();    // Default connection string
	virtual CString GetDefaultSQL();    // Default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);  // RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COUNTERRS_H__4588682F_15AD_4964_BD42_81BAD77E520E__INCLUDED_)
