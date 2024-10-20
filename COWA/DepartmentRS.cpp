// DepartmentRS.cpp : implementation file
//

#include "stdafx.h"
#include "COWA.h"
#include "DepartmentRS.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDepartmentRS

IMPLEMENT_DYNAMIC(CDepartmentRS, CRecordset)

CDepartmentRS::CDepartmentRS(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CDepartmentRS)
// 	m_ID = 0;
// 	m_PERSON = _T("");
// 	m_IN_OUT = _T("");
	m_ID = _T("");
	m_NAME = _T("");
	m_MANAGER = _T("");
	m_INTRO = _T("");
	m_nFields = 4;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CDepartmentRS::GetDefaultConnect()
{
	return _T("ODBC;DSN=zx");
}

CString CDepartmentRS::GetDefaultSQL()
{
	return _T("[DEPARTMENT]");
}

void CDepartmentRS::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CDepartmentRS)
	pFX->SetFieldType(CFieldExchange::outputColumn);
// 	RFX_Int(pFX, _T("[ATTENDANCE].[ID]"), m_ID);
// 	RFX_Text(pFX, _T("[PERSON]"), m_PERSON);
// 	RFX_Text(pFX, _T("[IN_OUT]"), m_IN_OUT);
// 	RFX_Date(pFX, _T("[IO_TIME]"), m_IO_TIME);
	RFX_Text(pFX, _T("[DEPARTMENT].[ID]"), m_ID);
	RFX_Text(pFX, _T("[NAME]"), m_NAME);
	RFX_Text(pFX, _T("[MANAGER]"), m_MANAGER);
	RFX_Text(pFX, _T("[INTRO]"), m_INTRO);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CDepartmentRS diagnostics

#ifdef _DEBUG
void CDepartmentRS::AssertValid() const
{
	CRecordset::AssertValid();
}

void CDepartmentRS::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
