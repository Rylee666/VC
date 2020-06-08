
// DBView.cpp : CDBView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "DB.h"
#endif

#include "DBSet.h"
#include "DBDoc.h"
#include "DBView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDBView

IMPLEMENT_DYNCREATE(CDBView, CRecordView)

BEGIN_MESSAGE_MAP(CDBView, CRecordView)
END_MESSAGE_MAP()

// CDBView ����/����

CDBView::CDBView()
	: CRecordView(IDD_DB_FORM)
	, ID(0)
	, name(_T(""))
	, number(_T(""))
	, age(_T(""))
	, phoneNum(_T(""))
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������

}

CDBView::~CDBView()
{
}

void CDBView::DoDataExchange(CDataExchange* pDX)
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

BOOL CDBView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CDBView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_DBSet;
	CRecordView::OnInitialUpdate();

}


// CDBView ���

#ifdef _DEBUG
void CDBView::AssertValid() const
{
	CRecordView::AssertValid();
}

void CDBView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CDBDoc* CDBView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDBDoc)));
	return (CDBDoc*)m_pDocument;
}
#endif //_DEBUG


// CDBView ���ݿ�֧��
CRecordset* CDBView::OnGetRecordset()
{
	return m_pSet;
}



// CDBView ��Ϣ�������
