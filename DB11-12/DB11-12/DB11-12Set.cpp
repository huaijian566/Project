
// DB11-12Set.cpp : CDB1112Set 类的实现
//

#include "stdafx.h"
#include "DB11-12.h"
#include "DB11-12Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDB1112Set 实现

// 代码生成在 2020年5月12日, 19:51

IMPLEMENT_DYNAMIC(CDB1112Set, CRecordset)

CDB1112Set::CDB1112Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_1 = L"";
	m_2 = 0.0;
	m_3 = L"";
	m_nFields = 4;
	m_nDefaultType = dynaset;
}
//#error 安全问题: 连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
CString CDB1112Set::GetDefaultConnect()
{
	return _T("DBQ=F:\\\x6000\x5065\\DOCUMENTS\\Database2.mdb;DefaultDir=F:\\\x6000\x5065\\DOCUMENTS;Driver={Microsoft Access Driver (*.mdb)};DriverId=25;FIL=MS Access;FILEDSN=D:\\Documents\\\x6570\x636e\x6e90_\x5b66\x751f\x4fe1\x606f.dsn;MaxBufferSize=2048;MaxScanRows=8;PageTimeout=5;SafeTransactions=0;Threads=3;UID=admin;UserCommitSync=Yes;");
}

CString CDB1112Set::GetDefaultSQL()
{
	return _T("[database2]");
}

void CDB1112Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[字段1]"), m_1);
	RFX_Double(pFX, _T("[字段2]"), m_2);
	RFX_Text(pFX, _T("[字段3]"), m_3);

}
/////////////////////////////////////////////////////////////////////////////
// CDB1112Set 诊断

#ifdef _DEBUG
void CDB1112Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CDB1112Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

