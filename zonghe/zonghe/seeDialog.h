#pragma once
#include "afxwin.h"


// seeDialog �Ի���

class seeDialog : public CDialogEx
{
	DECLARE_DYNAMIC(seeDialog)

public:
	seeDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~seeDialog();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG5 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListBox pl;
	CStringArray s;
	virtual BOOL OnInitDialog();
};
