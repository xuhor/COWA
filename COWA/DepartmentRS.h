#if !defined(AFX_DEPARTMENTRS_H__2491C9FF_28C4_4FD7_902F_03C7A62B9FE8__INCLUDED_)
#define AFX_DEPARTMENTRS_H__2491C9FF_28C4_4FD7_902F_03C7A62B9FE8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DepartmentRS.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDepartmentRS recordset

class CDepartmentRS : public CRecordset
{
public:
	CDepartmentRS(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CDepartmentRS)

// Field/Param Data
	//{{AFX_FIELD(CDepartmentRS, CRecordset)
// 	int		m_ID;
// 	CString	m_PERSON;
// 	CString	m_IN_OUT;
// 	CTime	m_IO_TIME;
	CString	m_ID;
	CString	m_NAME;
	CString	m_MANAGER;
	CString	m_INTRO;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDepartmentRS)
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

#endif // !defined(AFX_DEPARTMENTRS_H__2491C9FF_28C4_4FD7_902F_03C7A62B9FE8__INCLUDED_)
