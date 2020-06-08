
// DBView.cpp : CDBView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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

// CDBView 构造/析构

CDBView::CDBView()
	: CRecordView(IDD_DB_FORM)
	, ID(0)
	, name(_T(""))
	, number(_T(""))
	, age(_T(""))
	, phoneNum(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码

}

CDBView::~CDBView()
{
}

void CDBView::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_ID);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->m_1);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->m_2);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->m_3);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->m_4);
}

BOOL CDBView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CDBView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_DBSet;
	CRecordView::OnInitialUpdate();

}


// CDBView 诊断

#ifdef _DEBUG
void CDBView::AssertValid() const
{
	CRecordView::AssertValid();
}

void CDBView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CDBDoc* CDBView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDBDoc)));
	return (CDBDoc*)m_pDocument;
}
#endif //_DEBUG


// CDBView 数据库支持
CRecordset* CDBView::OnGetRecordset()
{
	return m_pSet;
}



// CDBView 消息处理程序
