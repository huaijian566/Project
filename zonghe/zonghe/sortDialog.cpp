// sortDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "zonghe.h"
#include "sortDialog.h"
#include "afxdialogex.h"


// sortDialog �Ի���

IMPLEMENT_DYNAMIC(sortDialog, CDialogEx)

sortDialog::sortDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG3, pParent)
	, sort(_T(""))
{

}

sortDialog::~sortDialog()
{
}

void sortDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, sort);
}


BEGIN_MESSAGE_MAP(sortDialog, CDialogEx)
END_MESSAGE_MAP()


// sortDialog ��Ϣ�������
