
// zongheSet.cpp : CzongheSet ���ʵ��
//

#include "stdafx.h"
#include "zonghe.h"
#include "zongheSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CzongheSet ʵ��

// ���������� 2020��6��26��, 11:05

IMPLEMENT_DYNAMIC(CzongheSet, CRecordset)

CzongheSet::CzongheSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	column1 = L"";
	column2 = L"";
	column3 = L"";
	column4 = L"";
	column5 = L"";
	column6 = L"";
	column7 = L"";
	column8 = L"";
	m_nFields = 9;
	m_nDefaultType = dynaset;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CzongheSet::GetDefaultConnect()
{
	return _T("DBQ=F:\\\x6000\x5065\\Documents\\Database6.mdb;DefaultDir=F:\\\x6000\x5065\\Documents;Driver={Microsoft Access Driver (*.mdb)};DriverId=25;FIL=MS Access;FILEDSN=D:\\Documents\\\x5b66\x751f\x8be6\x7ec6\x4fe1\x606f\x6570\x636e\x6e90.dsn;MaxBufferSize=2048;MaxScanRows=8;PageTimeout=5;SafeTransactions=0;Threads=3;UID=admin;UserCommitSync=Yes;");
}

CString CzongheSet::GetDefaultSQL()
{
	return _T("[ѧ����ϸ��Ϣ]");
}

void CzongheSet::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[����]"), column1);
	RFX_Text(pFX, _T("[ѧ��]"), column2);
	RFX_Text(pFX, _T("[רҵ]"), column3);
	RFX_Text(pFX, _T("[�Ա�]"), column4);
	RFX_Text(pFX, _T("[��������]"), column5);
	RFX_Text(pFX, _T("[�ֻ�����]"), column6);
	RFX_Text(pFX, _T("[��ͥסַ]"), column7);
	RFX_Text(pFX, _T("[��Ƭ]"), column8);

}
/////////////////////////////////////////////////////////////////////////////
// CzongheSet ���

#ifdef _DEBUG
void CzongheSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CzongheSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

