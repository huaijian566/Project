#pragma once


// MyDialog2 �Ի���

class MyDialog2 : public CDialogEx
{
	DECLARE_DYNAMIC(MyDialog2)

public:
	MyDialog2(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~MyDialog2();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	long j;
};
