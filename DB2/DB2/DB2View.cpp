
// DB2View.cpp : CDB2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "DB2.h"
#endif

#include "DB2Set.h"
#include "DB2Doc.h"
#include "DB2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDB2View

IMPLEMENT_DYNCREATE(CDB2View, CRecordView)

BEGIN_MESSAGE_MAP(CDB2View, CRecordView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDB2View::OnBnClickedButton1)
	ON_WM_PAINT()
	ON_COMMAND(ID_RECORD_FIRST, &CDB2View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CDB2View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CDB2View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CDB2View::OnRecordLast)
END_MESSAGE_MAP()

// CDB2View ����/����

CDB2View::CDB2View()
	: CRecordView(IDD_DB2_FORM)
	, ID(0)
	, name(_T(""))
	, age(_T(""))
	, number(_T(""))
	, phoneNum(_T(""))
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������
	path = _T("C:\\picture\\");

}

CDB2View::~CDB2View()
{
}

void CDB2View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_ID);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->m_1);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->m_2);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->m_3);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->m_4);
}

BOOL CDB2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CDB2View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_DB2Set;
	CRecordView::OnInitialUpdate();

}


// CDB2View ���

#ifdef _DEBUG
void CDB2View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CDB2View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CDB2Doc* CDB2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDB2Doc)));
	return (CDB2Doc*)m_pDocument;
}
#endif //_DEBUG


// CDB2View ���ݿ�֧��
CRecordset* CDB2View::OnGetRecordset()
{
	return m_pSet;
}



// CDB2View ��Ϣ�������


void CDB2View::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CImage img;
	n = 1;
	CDC *pDC = GetDC();
}
void CDB2View::foo(CImage&img, int&sx, int&sy, int&w, int&h)
{
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
	else {
		w = rect.Width();
		h = w / img_ratio;
		sy = (rect.Height() - h) / 2;
		sx = 0;
	}
}
void CDB2View::OnDraw(CDC* pDC)
{
	// TODO: �ڴ����ר�ô����/����û���
	if (n == 1)
	{

		CImage img;
		CString s = m_pSet->m_5;
		filename = path + s;
		img.Load(filename);
		pDC = GetDlgItem(IDC_STATIC)->GetDC();
		pDC->SetStretchBltMode(HALFTONE);
		int sx, sy, w, h;
		foo(img, sx, sy, w, h);
		img.Draw(pDC->m_hDC, sx, sy, w, h);
		ReleaseDC(pDC);
	}

}

void CDB2View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: �ڴ˴������Ϣ����������
	CRecordView::OnPaint();
}
/*void  CDB2View::OnRecordFirst()
{
	// TODO: �ڴ���������������
	m_pSet->MoveFirst();
	UpdateData(false);
}


void CDB2View::OnRecordPrev()
{
	// TODO: �ڴ���������������
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);

}


void CDB2View::OnRecordNext()
{
	// TODO: �ڴ���������������
	m_pSet->MoveNext();
	if (m_pSet->IsEOF())
		m_pSet->MoveLast();
	UpdateData(false);

}


//void CDB2View::OnRecordLast()
{
	// TODO: �ڴ���������������
	m_pSet->MoveLast();
	UpdateData(false);
}
*/

void CDB2View::OnRecordFirst()
{
	m_pSet->MoveFirst();
	UpdateData(false);
	// TODO: �ڴ���������������
}


void CDB2View::OnRecordPrev()
{
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
	// TODO: �ڴ���������������
}


void CDB2View::OnRecordNext()
{
	m_pSet->MoveNext();
	if (m_pSet->IsEOF())
		m_pSet->MoveLast();
	UpdateData(false);

	// TODO: �ڴ���������������
}


void CDB2View::OnRecordLast()
{
	m_pSet->MoveLast();
	UpdateData(false);
	// TODO: �ڴ���������������
}
