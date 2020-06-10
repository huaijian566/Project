
// MFCApplicationView.cpp : CMFCApplicationView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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

// CMFCApplicationView 构造/析构

CMFCApplicationView::CMFCApplicationView()
{
	// TODO: 在此处添加构造代码

}

CMFCApplicationView::~CMFCApplicationView()
{
}

BOOL CMFCApplicationView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplicationView 绘制

void CMFCApplicationView::OnDraw(CDC* pDC)
{
	CMFCApplicationDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	
	
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


// CMFCApplicationView 诊断

#ifdef _DEBUG
void CMFCApplicationView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplicationView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplicationDoc* CMFCApplicationView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplicationDoc)));
	return (CMFCApplicationDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplicationView 消息处理程序
