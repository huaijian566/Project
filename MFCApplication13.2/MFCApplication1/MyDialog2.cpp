// MyDialog2.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MyDialog2.h"
#include "afxdialogex.h"


// MyDialog2 对话框

IMPLEMENT_DYNAMIC(MyDialog2, CDialogEx)

MyDialog2::MyDialog2(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, j(0)
{

}

MyDialog2::~MyDialog2()
{
}

void MyDialog2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, j);
}


BEGIN_MESSAGE_MAP(MyDialog2, CDialogEx)
END_MESSAGE_MAP()


// MyDialog2 消息处理程序
