
// MFCApplicationView.h : CMFCApplicationView 类的接口
//

#pragma once


class CMFCApplicationView : public CView
{
protected: // 仅从序列化创建
	CMFCApplicationView();
	DECLARE_DYNCREATE(CMFCApplicationView)

// 特性
public:
	CMFCApplicationDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCApplicationView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFCApplicationView.cpp 中的调试版本
inline CMFCApplicationDoc* CMFCApplicationView::GetDocument() const
   { return reinterpret_cast<CMFCApplicationDoc*>(m_pDocument); }
#endif

