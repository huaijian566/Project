// seeDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "zonghe.h"
#include "seeDialog.h"
#include "afxdialogex.h"


// seeDialog 对话框

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


// seeDialog 消息处理程序


BOOL seeDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	for (int i = 0; i<s.GetSize(); i++)
		pl.AddString(s[i]);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}