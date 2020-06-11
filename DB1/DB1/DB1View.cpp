
// DB1View.cpp : CDB1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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

// CDB1View 构造/析构

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
	// TODO: 在此处添加构造代码

}

CDB1View::~CDB1View()
{
}

void CDB1View::DoDataExchange(CDataExchange* pDX)
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
	DDX_Text(pDX, IDC_EDIT6, m_pSet->m_5);
}

BOOL CDB1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CDB1View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_DB1Set;
	CRecordView::OnInitialUpdate();

}


// CDB1View 诊断

#ifdef _DEBUG
void CDB1View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CDB1View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CDB1Doc* CDB1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDB1Doc)));
	return (CDB1Doc*)m_pDocument;
}
#endif //_DEBUG


// CDB1View 数据库支持
CRecordset* CDB1View::OnGetRecordset()
{
	return m_pSet;
}



// CDB1View 消息处理程序
