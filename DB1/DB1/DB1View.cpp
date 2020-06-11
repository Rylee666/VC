
// DB1View.cpp : CDB1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "DB1.h"
#endif

#include "DB1Set.h"
#include "DB1Doc.h"
#include "DB1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDB1View

IMPLEMENT_DYNCREATE(CDB1View, CRecordView)

BEGIN_MESSAGE_MAP(CDB1View, CRecordView)
END_MESSAGE_MAP()

// CDB1View ����/����

CDB1View::CDB1View()
	: CRecordView(IDD_DB1_FORM)
	, ID(0)
	, name(_T(""))
	, number(_T(""))
	, age(_T(""))
	, phoneNum(_T(""))
	, photo(_T(""))
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������

}

CDB1View::~CDB1View()
{
}

void CDB1View::DoDataExchange(CDataExchange* pDX)
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
	DDX_Text(pDX, IDC_EDIT6, m_pSet->m_5);
}

BOOL CDB1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CDB1View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_DB1Set;
	CRecordView::OnInitialUpdate();

}


// CDB1View ���

#ifdef _DEBUG
void CDB1View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CDB1View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CDB1Doc* CDB1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDB1Doc)));
	return (CDB1Doc*)m_pDocument;
}
#endif //_DEBUG


// CDB1View ���ݿ�֧��
CRecordset* CDB1View::OnGetRecordset()
{
	return m_pSet;
}



// CDB1View ��Ϣ�������
