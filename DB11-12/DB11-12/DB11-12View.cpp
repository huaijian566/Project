
// DB11-12View.cpp : CDB1112View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "DB11-12.h"
#endif

#include "DB11-12Set.h"
#include "DB11-12Doc.h"
#include "DB11-12View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDB1112View

IMPLEMENT_DYNCREATE(CDB1112View, CRecordView)

BEGIN_MESSAGE_MAP(CDB1112View, CRecordView)
	ON_COMMAND(ID_RECORD_FIRST, &CDB1112View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CDB1112View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CDB1112View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CDB1112View::OnRecordLast)
	ON_BN_CLICKED(IDC_BUTTON1, &CDB1112View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDB1112View 构造/析构

CDB1112View::CDB1112View()
	: CRecordView(IDD_DB1112_FORM)
	, name(_T(""))
	, number(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码
	a = false;
	s = _T("");
}

CDB1112View::~CDB1112View()
{
}

void CDB1112View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_1);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->m_2);
}

BOOL CDB1112View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CDB1112View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_DB1112Set;
	CRecordView::OnInitialUpdate();

}


// CDB1112View 诊断

#ifdef _DEBUG
void CDB1112View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CDB1112View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CDB1112Doc* CDB1112View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDB1112Doc)));
	return (CDB1112Doc*)m_pDocument;
}
#endif //_DEBUG


// CDB1112View 数据库支持
CRecordset* CDB1112View::OnGetRecordset()
{
	return m_pSet;
}



// CDB1112View 消息处理程序


void CDB1112View::OnRecordFirst()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveFirst();
	UpdateData(false);
	
	m_pSet->GetFieldValue(short(3), s);
	draw_pic(s);
}


void CDB1112View::OnRecordPrev()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
	{
		m_pSet->MoveFirst();
	}
	UpdateData(false);
	m_pSet->GetFieldValue(short(3), s);
	draw_pic(s);
}


void CDB1112View::OnRecordNext()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveNext();
	if (m_pSet->IsEOF())
	{
		m_pSet->MoveLast();
	}
	UpdateData(false);
	m_pSet->GetFieldValue(short(3), s);
	draw_pic(s);
}


void CDB1112View::OnRecordLast()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveLast();
	UpdateData(false);
	m_pSet->GetFieldValue(short(3), s);
	draw_pic(s);

}


void CDB1112View::draw_pic(CString file)
{

	CImage img;
	img.Load(file);
	CDC* pDC = GetDlgItem(IDC_STATIC)->GetDC();
	int w, h, sx, sy;
	CRect rect;
	GetDlgItem(IDC_STATIC)->GetClientRect(&rect);
	float rect_ratio = 1.0*rect.Width() / rect.Height();
	float img_ratio = 1.0*img.GetWidth() / img.GetHeight();

	if (rect_ratio > img_ratio)
	{
		h = rect.Height();
		w = img_ratio*h;
		sx = (rect.Width() - w) / 2;
		sy = 0;
	}
	else
	{
		w = rect.Width();
		h = w / img_ratio;
		sx = 0;
		sy = (rect.Height() - h) / 2;
	}

	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
}

void CDB1112View::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	a = true;
	if (a)
	{
		//draw_pic(s);
	}
}
