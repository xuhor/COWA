#if !defined(AFX_OVERTIMERS_H__5DFE4DB3_2080_4804_8BA0_67B1C87BE6B1__INCLUDED_)
#define AFX_OVERTIMERS_H__5DFE4DB3_2080_4804_8BA0_67B1C87BE6B1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OvertimeRS.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// COvertimeRS recordset

class COvertimeRS : public CRecordset
{
public:
	COvertimeRS(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(COvertimeRS)

// Field/Param Data
	//{{AFX_FIELD(COvertimeRS, CRecordset)
	int		m_ID;
	CString	m_PERSON;
	BYTE	m_WORK_HOURS;
	CTime	m_WORK_DATE;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COvertimeRS)
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

#endif // !defined(AFX_OVERTIMERS_H__5DFE4DB3_2080_4804_8BA0_67B1C87BE6B1__INCLUDED_)
