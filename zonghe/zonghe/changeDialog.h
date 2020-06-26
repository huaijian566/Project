#pragma once
#include "afxwin.h"


// changeDialog 对话框

class changeDialog : public CDialogEx
{
	DECLARE_DYNAMIC(changeDialog)

public:
	changeDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~changeDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	
public:
	CString xm;
	CString xh;
	CString zy;
	CString xb;
	CString csny;
	CString hm;
	CString zz;
	CString lj;
};
