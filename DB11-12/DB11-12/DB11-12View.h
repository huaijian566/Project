
// DB11-12View.h : CDB1112View ��Ľӿ�
//

#pragma once

class CDB1112Set;

class CDB1112View : public CRecordView
{
protected: // �������л�����
	CDB1112View();
	DECLARE_DYNCREATE(CDB1112View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_DB1112_FORM };
#endif
	CDB1112Set* m_pSet;

// ����
public:
	CDB1112Doc* GetDocument() const;
	void draw_pic(CString file);
// ����
public:
	bool a;
	CString s;
// ��д
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CDB1112View();
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
	CString number;
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
	afx_msg void OnBnClickedButton1();
};

#ifndef _DEBUG  // DB11-12View.cpp �еĵ��԰汾
inline CDB1112Doc* CDB1112View::GetDocument() const
   { return reinterpret_cast<CDB1112Doc*>(m_pDocument); }
#endif

