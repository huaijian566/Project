
// DB11-12View.cpp : CDB1112View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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

// CDB1112View ����/����

CDB1112View::CDB1112View()
	: CRecordView(IDD_DB1112_FORM)
	, name(_T(""))
	, number(_T(""))
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������
	a = false;
	s = _T("");
}

CDB1112View::~CDB1112View()
{
}

void CDB1112View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_1);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->m_2);
}

BOOL CDB1112View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CDB1112View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_DB1112Set;
	CRecordView::OnInitialUpdate();

}


// CDB1112View ���

#ifdef _DEBUG
void CDB1112View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CDB1112View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CDB1112Doc* CDB1112View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDB1112Doc)));
	return (CDB1112Doc*)m_pDocument;
}
#endif //_DEBUG


// CDB1112View ���ݿ�֧��
CRecordset* CDB1112View::OnGetRecordset()
{
	return m_pSet;
}



// CDB1112View ��Ϣ�������


void CDB1112View::OnRecordFirst()
{
	// TODO: �ڴ���������������
	m_pSet->MoveFirst();
	UpdateData(false);
	
	m_pSet->GetFieldValue(short(3), s);
	draw_pic(s);
}


void CDB1112View::OnRecordPrev()
{
	// TODO: �ڴ���������������
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
	// TODO: �ڴ���������������
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
	// TODO: �ڴ���������������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	a = true;
	if (a)
	{
		//draw_pic(s);
	}
}
