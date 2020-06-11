
// DBDBView.cpp : CDBDBView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "DBDB.h"
#endif

#include "DBDBSet.h"
#include "DBDBDoc.h"
#include "DBDBView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDBDBView

IMPLEMENT_DYNCREATE(CDBDBView, CRecordView)

BEGIN_MESSAGE_MAP(CDBDBView, CRecordView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDBDBView::OnBnClickedButton1)
	ON_WM_PAINT()
	ON_COMMAND(ID_RECORD_NEXT, &CDBDBView::OnRecordNext)
	ON_COMMAND(ID_RECORD_PREV, &CDBDBView::OnRecordPrev)
	ON_EN_CHANGE(IDC_EDIT1, &CDBDBView::OnEnChangeEdit1)
END_MESSAGE_MAP()

// CDBDBView ����/����

CDBDBView::CDBDBView()
	: CRecordView(IDD_DBDB_FORM)
	, ID(0)
	, name(_T(""))
	, number(_T(""))
	, phoneNum(_T(""))
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������

}

CDBDBView::~CDBDBView()
{
}

void CDBDBView::DoDataExchange(CDataExchange* pDX)
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

BOOL CDBDBView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CDBDBView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_DBDBSet;
	CRecordView::OnInitialUpdate();

}


// CDBDBView ���

#ifdef _DEBUG
void CDBDBView::AssertValid() const
{
	CRecordView::AssertValid();
}

void CDBDBView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CDBDBDoc* CDBDBView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDBDBDoc)));
	return (CDBDBDoc*)m_pDocument;
}
#endif //_DEBUG


// CDBDBView ���ݿ�֧��
CRecordset* CDBDBView::OnGetRecordset()
{
	return m_pSet;
}



// CDBDBView ��Ϣ�������


void CDBDBView::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString s;
	m_pSet->GetFieldValue(short(4), s);
	CImage img;
	img.Load(s);
	CDC*pDC = GetDlgItem(IDC_STATIC)->GetDC();
	img.Draw(pDC->m_hDC, 0, 0, img.GetWidth(), img.GetHeight());
}


void CDBDBView::OnPaint()//�ð�ť��ʾ��Ƭ
{
	CPaintDC dc(this); // device context for painting
					   // TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CRecordView::OnPaint()
					   	CString s;
	m_pSet->GetFieldValue(short(4), s);
	CImage img; img.Load(s);
	picRect.left = 0; picRect.top = 0;
	picRect.right = img.GetWidth(); picRect.bottom = img.GetHeight();
	CDC*pDC = GetDlgItem(IDC_STATIC)->GetDC();
	img.Draw(pDC->m_hDC, 0, 0, img.GetWidth(), img.GetHeight());
}


void CDBDBView::OnRecordNext()
{
	m_pSet->MoveNext();
	UpdateData(false);
	if (m_pSet->IsEOF()) {
		m_pSet->MoveLast();
	}
	InvalidateRect(&picRect);
	// TODO: �ڴ���������������
}


void CDBDBView::OnRecordPrev()
{
	// TODO: �ڴ���������������
	m_pSet->MovePrev();
	UpdateData(false);
	if (m_pSet->IsBOF()) {
		m_pSet->MoveFirst();
	}
	InvalidateRect(&picRect);
}


void CDBDBView::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CRecordView::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
