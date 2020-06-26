#pragma once


// checkDialog 对话框

class checkDialog : public CDialogEx
{
	DECLARE_DYNAMIC(checkDialog)

public:
	checkDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~checkDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString check;
};
