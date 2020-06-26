#pragma once


// sortDialog 对话框

class sortDialog : public CDialogEx
{
	DECLARE_DYNAMIC(sortDialog)

public:
	sortDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~sortDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString sort;
};
