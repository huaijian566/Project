
// zongheView.cpp : CzongheView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "zonghe.h"
#endif

#include "zongheSet.h"
#include "zongheDoc.h"
#include "zongheView.h"
#include "MyDialog.h"
#include "changeDialog.h"
#include "sortDialog.h"
#include "checkDialog.h"
#include "seeDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CzongheView

IMPLEMENT_DYNCREATE(CzongheView, CRecordView)

BEGIN_MESSAGE_MAP(CzongheView, CRecordView)
	ON_COMMAND(ID_RECORD_FIRST, &CzongheView::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CzongheView::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CzongheView::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CzongheView::OnRecordLast)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON1, &CzongheView::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CzongheView::add)
	ON_BN_CLICKED(IDC_BUTTON3, &CzongheView::ondelete)
	ON_BN_CLICKED(IDC_BUTTON4, &CzongheView::Onchange)
	ON_COMMAND(ID_sort, &CzongheView::Onsort)
	ON_COMMAND(ID_check, &CzongheView::Oncheck)
	ON_COMMAND(ID_see, &CzongheView::Onsee)
	ON_BN_CLICKED(IDC_BUTTON5, &CzongheView::OnBnClickedButton5)
END_MESSAGE_MAP()

// CzongheView 构造/析构

CzongheView::CzongheView()
	: CRecordView(IDD_ZONGHE_FORM)
	, name(_T(""))
	, snumber(_T(""))
	, professional(_T(""))
	, sex(_T(""))
	, tnumber(_T(""))
	, address(_T(""))
	, picture(_T(""))
	, agee(_T(""))
	//, xh(0)
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码

}

CzongheView::~CzongheView()
{
}

void CzongheView::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->column1);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->column2);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->column3);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->column4);
	//DDX_Control(pDX, IDC_EDIT5, m_pSet->column1);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->column5);
	DDX_Text(pDX, IDC_EDIT6, m_pSet->column6);
	DDX_Text(pDX, IDC_EDIT7, m_pSet->column7);
	DDX_Text(pDX, IDC_EDIT8, m_pSet->column8);

	//DDX_Text(pDX, IDC_EDIT2, xh);
}

BOOL CzongheView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CzongheView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_zongheSet;
	CRecordView::OnInitialUpdate();

}


// CzongheView 诊断

#ifdef _DEBUG
void CzongheView::AssertValid() const
{
	CRecordView::AssertValid();
}

void CzongheView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CzongheDoc* CzongheView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CzongheDoc)));
	return (CzongheDoc*)m_pDocument;
}
#endif //_DEBUG


// CzongheView 数据库支持
CRecordset* CzongheView::OnGetRecordset()
{
	return m_pSet;
}



// CzongheView 消息处理程序


void CzongheView::OnRecordFirst()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveFirst();
	UpdateData(false);
	Invalidate();
}


void CzongheView::OnRecordPrev()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
	{
		m_pSet->MoveFirst();
	}
	UpdateData(false);
	Invalidate();
}


void CzongheView::OnRecordNext()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveNext();
	if (m_pSet->IsEOF())
	{
		m_pSet->MoveLast();
	}
	UpdateData(false);
	Invalidate();
}


void CzongheView::OnRecordLast()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveLast();
	UpdateData(false);
	Invalidate();
}


void CzongheView::draw_pic(CString file)
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

void CzongheView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CRecordView::OnPaint()
	CzongheDoc* pDoc = GetDocument();
	GetDlgItemText(IDC_EDIT8, pDoc->name);
	draw_pic(pDoc->name);
}


void CzongheView::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CzongheDoc* pDoc = GetDocument();
	MyDialog dlg;
	dlg.picname = pDoc->name;
	int t = dlg.DoModal();

	if (t == IDOK)
	{

	}
}


void CzongheView::add()
{
	// TODO: 在此添加控件通知处理程序代码
	changeDialog dlg;
	if (dlg.DoModal() == IDOK)
	{
		CString xm, xh, xb, zy, hm, zz, lj, csny;
		xm = dlg.xm;
		xh = dlg.xh;
		xb = dlg.xb;
		zy = dlg.zy;
		hm = dlg.hm;
		zz = dlg.zz;
		lj = dlg.lj;
		csny = dlg.csny;

		m_pSet->AddNew();
		m_pSet->column1 = xm;
		m_pSet->column2 = xh;
		m_pSet->column3 = zy;
		m_pSet->column4 = xb;
		m_pSet->column5 = csny;
		m_pSet->column6 = hm;
		m_pSet->column7 = zz;
		m_pSet->column8 = lj;
		m_pSet->Update();
		UpdateData(false);
	}
}


void CzongheView::ondelete()
{
	// TODO: 在此添加控件通知处理程序代码
	m_pSet->Delete();
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
}


void CzongheView::Onchange()
{
	// TODO: 在此添加控件通知处理程序代码

	changeDialog dlg2;
	dlg2.xm = m_pSet->column1;
	dlg2.xh = m_pSet->column2;
	dlg2.xb = m_pSet->column4;
	dlg2.zy = m_pSet->column3;
	dlg2.hm = m_pSet->column6;
	dlg2.zz = m_pSet->column7;
	dlg2.lj = m_pSet->column8;
	dlg2.csny = m_pSet->column5;
	UpdateData(false);
	if (dlg2.DoModal() == IDOK)
	{

		m_pSet->Edit();
		m_pSet->column1 = dlg2.xm;
		m_pSet->column2 = dlg2.xh;
		m_pSet->column3 = dlg2.zy;
		m_pSet->column4 = dlg2.xb;
		m_pSet->column5 = dlg2.csny;
		m_pSet->column6 = dlg2.hm;
		m_pSet->column7 = dlg2.zz;
		m_pSet->column8 = dlg2.lj;
		m_pSet->Update();
		UpdateData(false);
		Invalidate();
	}
}


void CzongheView::Onsort()
{
	// TODO: 在此添加命令处理程序代码
	sortDialog l;
	if (l.DoModal() == IDOK)
	{
		m_pSet->m_strSort = l.sort;
		m_pSet->Requery();
		UpdateData(false);
	}
}


void CzongheView::Oncheck()
{
	// TODO: 在此添加命令处理程序代码
	checkDialog c;
	if (c.DoModal() == IDOK)
	{
		m_pSet->m_strFilter = c.check;
		m_pSet->Requery();
		UpdateData(false);
	}
}


void CzongheView::Onsee()
{
	// TODO: 在此添加命令处理程序代码


	seeDialog j;
	int n = m_pSet->GetODBCFieldCount();
	CString ss;
	m_pSet->MoveFirst();

	int d = 0;
	while (!(m_pSet->IsEOF()))
	{

		for (int i = 1; i <n; i++)
		{
			CString str;
			m_pSet->GetFieldValue(short(i), str);
			ss = ss + _T(" ; ") + str;
		}


		j.s.Add(ss);
		ss = _T("");
		d = d + 1;
		m_pSet->MoveNext();
	}
	if (j.DoModal() == IDOK)
	{

	}

	
}


void CzongheView::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	m_pSet->m_strFilter = _T("");
	m_pSet->Requery();
	UpdateData(false);
}
