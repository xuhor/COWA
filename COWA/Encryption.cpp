// Encryption.cpp : implementation file
//

#include "stdafx.h"
#include "Encryption.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEncryption

CEncryption::CEncryption()
{
}

CEncryption::~CEncryption()
{
}

CString CEncryption::Encrypt(CString S, WORD Key)
{
	CString Result,str;
	int i,j;
	
	Result=S; // 初始化结果字符串
	for(i=0; i<S.GetLength(); i++) // 依次对字符串中各字符进行操作
	{
		Result.SetAt(i, S.GetAt(i)^(Key>>8)); // 将密钥移位后与字符异或
		Key = ((BYTE)Result.GetAt(i)+Key)*C1+C2; // 产生下一个密钥
	}
	S=Result; // 保存结果
	Result.Empty(); // 清除结果
	for(i=0; i<S.GetLength(); i++) // 对加密结果进行转换
	{
		j=(BYTE)S.GetAt(i); // 提取字符
		// 将字符转换为两个字母保存
		str="12"; // 设置str长度为2
		str.SetAt(0, 65+j/26);
		str.SetAt(1, 65+j%26);
		Result += str;
	}
	return Result;
}

CString CEncryption::Decrypt(CString S, WORD Key)
{
	CString Result,str;
	int i,j;
	
	Result.Empty(); // 清楚结果
	for(i=0; i < S.GetLength()/2; i++) // 将字符串两个字母一组进行处理
	{
		j = ((BYTE)S.GetAt(2*i)-65)*26;
		j += (BYTE)S.GetAt(2*i+1)-65;
		str="1"; // 设置str长度为1
		str.SetAt(0, j);
		Result+=str; // 追加字符，还原字符串
	}
	S=Result; // 保存中间结果
	for(i=0; i<S.GetLength(); i++) // 依次对字符串中各字符进行操作
	{
		Result.SetAt(i, (BYTE)S.GetAt(i)^(Key>>8)); // 将密钥移位后与字符异或
		Key = ((BYTE)S.GetAt(i)+Key)*C1+C2; // 产生下一个密钥
	}
	return Result;
}
