// changeDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "zonghe.h"
#include "changeDialog.h"
#include "afxdialogex.h"


// changeDialog 对话框

IMPLEMENT_DYNAMIC(changeDialog, CDialogEx)

changeDialog::changeDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, xm(_T(""))
	, xh(_T(""))
	, zy(_T(""))
	, xb(_T(""))
	, csny(_T(""))
	, hm(_T(""))
	, zz(_T(""))
	, lj(_T(""))
{

}

changeDialog::~changeDialog()
{
}

void changeDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, xm);
	//DDX_Control(pDX, IDC_EDIT2, xh);
	DDX_Text(pDX, IDC_EDIT2, xh);
	DDX_Text(pDX, IDC_EDIT3, zy);
	DDX_Text(pDX, IDC_EDIT4, xb);
	DDX_Text(pDX, IDC_EDIT5, csny);
	DDX_Text(pDX, IDC_EDIT6, hm);
	DDX_Text(pDX, IDC_EDIT7, zz);
	DDX_Text(pDX, IDC_EDIT8, lj);
}


BEGIN_MESSAGE_MAP(changeDialog, CDialogEx)
END_MESSAGE_MAP()


// changeDialog 消息处理程序
