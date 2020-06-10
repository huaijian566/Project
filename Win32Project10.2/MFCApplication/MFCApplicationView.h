
// MFCApplicationView.h : CMFCApplicationView ��Ľӿ�
//

#pragma once


class CMFCApplicationView : public CView
{
protected: // �������л�����
	CMFCApplicationView();
	DECLARE_DYNCREATE(CMFCApplicationView)

// ����
public:
	CMFCApplicationDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFCApplicationView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFCApplicationView.cpp �еĵ��԰汾
inline CMFCApplicationDoc* CMFCApplicationView::GetDocument() const
   { return reinterpret_cast<CMFCApplicationDoc*>(m_pDocument); }
#endif

