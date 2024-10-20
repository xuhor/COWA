// counterRS.cpp : implementation file
//

#include "stdafx.h"
#include "COWA.h"
#include "counterRS.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CcounterRS

IMPLEMENT_DYNAMIC(CcounterRS, CRecordset)

CcounterRS::CcounterRS(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CcounterRS)
	m_ID = _T("");
	m_COUNTER_VALUE = 0;
	m_DESCRIPTION = _T("");
	m_nFields = 3;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CcounterRS::GetDefaultConnect()
{
	return _T("ODBC;DSN=zx");
}

CString CcounterRS::GetDefaultSQL()
{
	return _T("[COUNTER]");
}

void CcounterRS::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CcounterRS)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[ID]"), m_ID);
	RFX_Int(pFX, _T("[COUNTER_VALUE]"), m_COUNTER_VALUE);
	RFX_Text(pFX, _T("[DESCRIPTION]"), m_DESCRIPTION);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CcounterRS diagnostics

#ifdef _DEBUG
void CcounterRS::AssertValid() const
{
	CRecordset::AssertValid();
}

void CcounterRS::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
