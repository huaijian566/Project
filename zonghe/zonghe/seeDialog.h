#pragma once
#include "afxwin.h"


// seeDialog 对话框

class seeDialog : public CDialogEx
{
	DECLARE_DYNAMIC(seeDialog)

public:
	seeDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~seeDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG5 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListBox pl;
	CStringArray s;
	virtual BOOL OnInitDialog();
};
