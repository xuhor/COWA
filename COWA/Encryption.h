#if !defined(AFX_ENCRYPTION_H__D308E7DC_27EE_45AF_9C40_3C30A61FC1FB__INCLUDED_)
#define AFX_ENCRYPTION_H__D308E7DC_27EE_45AF_9C40_3C30A61FC1FB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Encryption.h : header file
//
//C1、C2加密、解密使用
#define C1 52845
#define C2 22719
/////////////////////////////////////////////////////////////////////////////
// CEncryption window

class CEncryption 
{
// Construction
public:
	CEncryption();

// Attributes
public:
	CString Encrypt(CString S, WORD Key); // 加密
	CString Decrypt(CString S, WORD Key); // 解密

public:
	virtual ~CEncryption();

	// Generated message map functions
protected:


};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ENCRYPTION_H__D308E7DC_27EE_45AF_9C40_3C30A61FC1FB__INCLUDED_)
