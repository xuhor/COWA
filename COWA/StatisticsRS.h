#if !defined(AFX_STATISTICSRS_H__321E666D_6931_403E_AB64_C245D0A1EBD2__INCLUDED_)
#define AFX_STATISTICSRS_H__321E666D_6931_403E_AB64_C245D0A1EBD2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// StatisticsRS.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CStatisticsRS recordset

class CStatisticsRS : public CRecordset
{
public:
	CStatisticsRS(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CStatisticsRS)

// Field/Param Data
	//{{AFX_FIELD(CStatisticsRS, CRecordset)
	int		m_ID;
	CString	m_YEAR_MONTH;
	CString	m_PERSON;
	int		m_WORK_HOUR;
	long	m_OVER_HOUR;
	int		m_LEAVE_HDAY;
	int		m_ERRAND_HDAY;
	BYTE	m_LATE_TIMES;
	BYTE	m_EARLY_TIMES;
	BYTE	m_ABSENT_TIMES;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStatisticsRS)
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

#endif // !defined(AFX_STATISTICSRS_H__321E666D_6931_403E_AB64_C245D0A1EBD2__INCLUDED_)
