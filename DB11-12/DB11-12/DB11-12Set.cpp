
// DB11-12Set.cpp : CDB1112Set ���ʵ��
//

#include "stdafx.h"
#include "DB11-12.h"
#include "DB11-12Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDB1112Set ʵ��

// ���������� 2020��5��12��, 19:51

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
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
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
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[�ֶ�1]"), m_1);
	RFX_Double(pFX, _T("[�ֶ�2]"), m_2);
	RFX_Text(pFX, _T("[�ֶ�3]"), m_3);

}
/////////////////////////////////////////////////////////////////////////////
// CDB1112Set ���

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

