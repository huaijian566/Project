#pragma once
#include "afxwin.h"


// changeDialog �Ի���

class changeDialog : public CDialogEx
{
	DECLARE_DYNAMIC(changeDialog)

public:
	changeDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~changeDialog();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
