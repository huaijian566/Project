#pragma once


// sortDialog �Ի���

class sortDialog : public CDialogEx
{
	DECLARE_DYNAMIC(sortDialog)

public:
	sortDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~sortDialog();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString sort;
};
