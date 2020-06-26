
// zongheView.h : CzongheView ��Ľӿ�
//

#pragma once
#include "afxwin.h"

class CzongheSet;

class CzongheView : public CRecordView
{
protected: // �������л�����
	CzongheView();
	DECLARE_DYNCREATE(CzongheView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_ZONGHE_FORM };
#endif
	CzongheSet* m_pSet;

// ����
public:
	CzongheDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CzongheView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	CString name;
	CString snumber;
	CString professional;
	CString sex;
	CEdit age;
	CString tnumber;
	CString address;
	CString picture;
	CString agee;
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
	afx_msg void OnPaint();
	afx_msg void OnBnClickedButton1();
	afx_msg void draw_pic(CString file);
	afx_msg void add();
	afx_msg void ondelete();
	afx_msg void Onchange();
	afx_msg void Onsort();
	afx_msg void Oncheck();
	afx_msg void Onsee();
	afx_msg void OnBnClickedButton5();
	//long xh;
};

#ifndef _DEBUG  // zongheView.cpp �еĵ��԰汾
inline CzongheDoc* CzongheView::GetDocument() const
   { return reinterpret_cast<CzongheDoc*>(m_pDocument); }
#endif

