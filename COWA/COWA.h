// COWA.h : main header file for the COWA application
//

#if !defined(AFX_COWA_H__F1F93407_8C6A_4858_86FE_9298AD859593__INCLUDED_)
#define AFX_COWA_H__F1F93407_8C6A_4858_86FE_9298AD859593__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols
#include "LoginDlg.h"

/////////////////////////////////////////////////////////////////////////////
// CCOWAApp:
// See COWA.cpp for the implementation of this class
//

class CCOWAApp : public CWinApp
{
public:
	int ExitInstance( );
	CCOWAApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCOWAApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCOWAApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COWA_H__F1F93407_8C6A_4858_86FE_9298AD859593__INCLUDED_)
