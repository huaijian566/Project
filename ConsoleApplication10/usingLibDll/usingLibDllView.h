
// usingLibDllView.h : CusingLibDllView 类的接口
//

#pragma once


class CusingLibDllView : public CView
{
protected: // 仅从序列化创建
	CusingLibDllView();
	DECLARE_DYNCREATE(CusingLibDllView)

// 特性
public:
	CusingLibDllDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CusingLibDllView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // usingLibDllView.cpp 中的调试版本
inline CusingLibDllDoc* CusingLibDllView::GetDocument() const
   { return reinterpret_cast<CusingLibDllDoc*>(m_pDocument); }
#endif

