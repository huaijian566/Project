
// DB11-12View.h : CDB1112View 类的接口
//

#pragma once

class CDB1112Set;

class CDB1112View : public CRecordView
{
protected: // 仅从序列化创建
	CDB1112View();
	DECLARE_DYNCREATE(CDB1112View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_DB1112_FORM };
#endif
	CDB1112Set* m_pSet;

// 特性
public:
	CDB1112Doc* GetDocument() const;
	void draw_pic(CString file);
// 操作
public:
	bool a;
	CString s;
// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CDB1112View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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

#ifndef _DEBUG  // DB11-12View.cpp 中的调试版本
inline CDB1112Doc* CDB1112View::GetDocument() const
   { return reinterpret_cast<CDB1112Doc*>(m_pDocument); }
#endif

