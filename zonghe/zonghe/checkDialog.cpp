// checkDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "zonghe.h"
#include "checkDialog.h"
#include "afxdialogex.h"


// checkDialog 对话框

IMPLEMENT_DYNAMIC(checkDialog, CDialogEx)

checkDialog::checkDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG4, pParent)
	, check(_T(""))
{

}

checkDialog::~checkDialog()
{
}

void checkDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, check);
}


BEGIN_MESSAGE_MAP(checkDialog, CDialogEx)
END_MESSAGE_MAP()


// checkDialog 消息处理程序
