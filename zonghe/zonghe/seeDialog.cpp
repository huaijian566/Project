// seeDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "zonghe.h"
#include "seeDialog.h"
#include "afxdialogex.h"


// seeDialog �Ի���

IMPLEMENT_DYNAMIC(seeDialog, CDialogEx)

seeDialog::seeDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG5, pParent)
{

}

seeDialog::~seeDialog()
{
}

void seeDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, pl);
}


BEGIN_MESSAGE_MAP(seeDialog, CDialogEx)
END_MESSAGE_MAP()


// seeDialog ��Ϣ�������


BOOL seeDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	for (int i = 0; i<s.GetSize(); i++)
		pl.AddString(s[i]);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}