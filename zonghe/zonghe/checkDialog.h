#pragma once


// checkDialog �Ի���

class checkDialog : public CDialogEx
{
	DECLARE_DYNAMIC(checkDialog)

public:
	checkDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~checkDialog();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString check;
};
