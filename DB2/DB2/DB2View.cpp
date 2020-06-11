
// DB2View.cpp : CDB2View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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

// CDB2View 构造/析构

CDB2View::CDB2View()
	: CRecordView(IDD_DB2_FORM)
	, ID(0)
	, name(_T(""))
	, age(_T(""))
	, number(_T(""))
	, phoneNum(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码
	path = _T("C:\\picture\\");

}

CDB2View::~CDB2View()
{
}

void CDB2View::DoDataExchange(CDataExchange* pDX)
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

BOOL CDB2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CDB2View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_DB2Set;
	CRecordView::OnInitialUpdate();

}


// CDB2View 诊断

#ifdef _DEBUG
void CDB2View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CDB2View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CDB2Doc* CDB2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDB2Doc)));
	return (CDB2Doc*)m_pDocument;
}
#endif //_DEBUG


// CDB2View 数据库支持
CRecordset* CDB2View::OnGetRecordset()
{
	return m_pSet;
}



// CDB2View 消息处理程序


void CDB2View::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加专用代码和/或调用基类
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
					   // TODO: 在此处添加消息处理程序代码
	CRecordView::OnPaint();
}
/*void  CDB2View::OnRecordFirst()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveFirst();
	UpdateData(false);
}


void CDB2View::OnRecordPrev()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);

}


void CDB2View::OnRecordNext()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveNext();
	if (m_pSet->IsEOF())
		m_pSet->MoveLast();
	UpdateData(false);

}


//void CDB2View::OnRecordLast()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveLast();
	UpdateData(false);
}
*/

void CDB2View::OnRecordFirst()
{
	m_pSet->MoveFirst();
	UpdateData(false);
	// TODO: 在此添加命令处理程序代码
}


void CDB2View::OnRecordPrev()
{
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
	// TODO: 在此添加命令处理程序代码
}


void CDB2View::OnRecordNext()
{
	m_pSet->MoveNext();
	if (m_pSet->IsEOF())
		m_pSet->MoveLast();
	UpdateData(false);

	// TODO: 在此添加命令处理程序代码
}


void CDB2View::OnRecordLast()
{
	m_pSet->MoveLast();
	UpdateData(false);
	// TODO: 在此添加命令处理程序代码
}
