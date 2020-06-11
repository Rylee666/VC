
// DBDBView.cpp : CDBDBView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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

// CDBDBView 构造/析构

CDBDBView::CDBDBView()
	: CRecordView(IDD_DBDB_FORM)
	, ID(0)
	, name(_T(""))
	, number(_T(""))
	, phoneNum(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码

}

CDBDBView::~CDBDBView()
{
}

void CDBDBView::DoDataExchange(CDataExchange* pDX)
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

BOOL CDBDBView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CDBDBView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_DBDBSet;
	CRecordView::OnInitialUpdate();

}


// CDBDBView 诊断

#ifdef _DEBUG
void CDBDBView::AssertValid() const
{
	CRecordView::AssertValid();
}

void CDBDBView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CDBDBDoc* CDBDBView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDBDBDoc)));
	return (CDBDBDoc*)m_pDocument;
}
#endif //_DEBUG


// CDBDBView 数据库支持
CRecordset* CDBDBView::OnGetRecordset()
{
	return m_pSet;
}



// CDBDBView 消息处理程序


void CDBDBView::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString s;
	m_pSet->GetFieldValue(short(4), s);
	CImage img;
	img.Load(s);
	CDC*pDC = GetDlgItem(IDC_STATIC)->GetDC();
	img.Draw(pDC->m_hDC, 0, 0, img.GetWidth(), img.GetHeight());
}


void CDBDBView::OnPaint()//用按钮显示照片
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CRecordView::OnPaint()
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
	// TODO: 在此添加命令处理程序代码
}


void CDBDBView::OnRecordPrev()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MovePrev();
	UpdateData(false);
	if (m_pSet->IsBOF()) {
		m_pSet->MoveFirst();
	}
	InvalidateRect(&picRect);
}


void CDBDBView::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CRecordView::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
