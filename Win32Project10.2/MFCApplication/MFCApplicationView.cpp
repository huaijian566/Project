
// MFCApplicationView.cpp : CMFCApplicationView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCApplication.h"
#endif

#include "MFCApplicationDoc.h"
#include "MFCApplicationView.h"
#include"w32.h"
#include"Win32D.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplicationView

IMPLEMENT_DYNCREATE(CMFCApplicationView, CView)

BEGIN_MESSAGE_MAP(CMFCApplicationView, CView)
END_MESSAGE_MAP()

// CMFCApplicationView ����/����

CMFCApplicationView::CMFCApplicationView()
{
	// TODO: �ڴ˴���ӹ������

}

CMFCApplicationView::~CMFCApplicationView()
{
}

BOOL CMFCApplicationView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCApplicationView ����

void CMFCApplicationView::OnDraw(CDC* pDC)
{
	CMFCApplicationDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	
	
	CString l;
	l.Format(_T("%d"), factorial(5));
	pDC->TextOutW(200, 100, l);

	CString s;
	FAC d;
	s.Format(_T("%f"), d.convert(30.0));
	pDC->TextOutW(200, 200, s);
	

	CString ss;
	ss.Format(_T("%d"), GetInt(5));
	pDC->TextOutW(300, 100, ss);

	CWin32D g;
	CString s2;
	s2.Format(_T("%f"), g.conver(30.0));
	pDC->TextOutW(300, 200, s2);

}


// CMFCApplicationView ���

#ifdef _DEBUG
void CMFCApplicationView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplicationView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplicationDoc* CMFCApplicationView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplicationDoc)));
	return (CMFCApplicationDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplicationView ��Ϣ�������
