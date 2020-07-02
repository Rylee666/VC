
// MFC综合实验View.cpp : CMFC综合实验View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC综合实验.h"
#endif

#include "MFC综合实验Set.h"
#include "MFC综合实验Doc.h"
#include "MFC综合实验View.h"
#include"Enlarge_DLG.h"
#include"ADD_DLG.h"
#include"Edit_DLG.h"
#include"Sort_DLG.h"
#include"Search.h"
#include"Traver_DLG.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC综合实验View

IMPLEMENT_DYNCREATE(CMFC综合实验View, CRecordView)

BEGIN_MESSAGE_MAP(CMFC综合实验View, CRecordView)
	ON_COMMAND(ID_RECORD_FIRST, &CMFC综合实验View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CMFC综合实验View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CMFC综合实验View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CMFC综合实验View::OnRecordLast)
	ON_BN_CLICKED(IDC_Enlarge, &CMFC综合实验View::OnBnClickedEnlarge)
	ON_BN_CLICKED(IDC_ADD, &CMFC综合实验View::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_Delete, &CMFC综合实验View::OnBnClickedDelete)
	ON_BN_CLICKED(IDC_Edit, &CMFC综合实验View::OnBnClickedEdit)
	ON_BN_CLICKED(IDC_Sort_Button, &CMFC综合实验View::OnBnClickedSortButton)
	ON_BN_CLICKED(IDC_Search, &CMFC综合实验View::OnBnClickedSearch)
	ON_BN_CLICKED(IDC_Traversal, &CMFC综合实验View::OnBnClickedTraversal)
	ON_BN_CLICKED(IDC_Recover, &CMFC综合实验View::OnBnClickedRecover)
END_MESSAGE_MAP()

// CMFC综合实验View 构造/析构

CMFC综合实验View::CMFC综合实验View()
	: CRecordView(IDD_MFC_FORM)
	, name(_T(""))
	, number(_T(""))
	, major(_T(""))
	, sex(_T(""))
	, birth(_T(""))
	, phone(0)
	, home(_T(""))
	, pic_add(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码

}

CMFC综合实验View::~CMFC综合实验View()
{
}

void CMFC综合实验View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->column1);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->column2);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->column3);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->column4);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->column5);
	DDX_Text(pDX, IDC_EDIT6, m_pSet->column6);
	DDX_Text(pDX, IDC_EDIT7, m_pSet->column7);
	DDX_Text(pDX, IDC_EDIT8, m_pSet->column8);
	Invalidate();
}

BOOL CMFC综合实验View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CMFC综合实验View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFC综合实验Set;
	CRecordView::OnInitialUpdate();

}


// CMFC综合实验View 诊断

#ifdef _DEBUG
void CMFC综合实验View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFC综合实验View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFC综合实验Doc* CMFC综合实验View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC综合实验Doc)));
	return (CMFC综合实验Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC综合实验View 数据库支持
CRecordset* CMFC综合实验View::OnGetRecordset()
{
	return m_pSet;
}



// CMFC综合实验View 消息处理程序


void CMFC综合实验View::OnRecordFirst()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveFirst();
	UpdateData(false);
}


void CMFC综合实验View::OnRecordPrev()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
}


void CMFC综合实验View::OnRecordNext()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveNext();
	if (m_pSet->IsEOF())
		m_pSet->MoveLast();
	UpdateData(false);
}


void CMFC综合实验View::OnRecordLast()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveLast();
	UpdateData(false);
}

void  CMFC综合实验View::drawPicture(CString filename)
{
	CImage img;
	img.Load(filename);
	CDC* pDC = GetDlgItem(IDC_STATIC)->GetDC();
	int w, h, sx, sy;
	CRect rect;
	GetDlgItem(IDC_STATIC)->GetClientRect(&rect);

	float rect_radio = 1.0 * rect.Width() / rect.Height();
	float image_radio = 1.0 * img.GetWidth() / img.GetHeight();

	if (rect_radio > image_radio)
	{
		h = rect.Height();
		w = image_radio * h;
		sx = (rect.Width() - w) / 2;
		sy = 0;
	}
	else {
		w = rect.Width();
		h = w / image_radio;
		sx = 0;
		sy = (rect.Height() - h) / 2;
	}
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
}

void CMFC综合实验View::OnBnClickedEnlarge()
{
	// TODO: 在此添加控件通知处理程序代码
	Enlarge_DLG dlg;
	dlg.fil = m_pSet->column8;
	dlg.DoModal();
}


void CMFC综合实验View::OnDraw(CDC* /*pDC*/)
{
	// TODO: 在此添加专用代码和/或调用基类
	file = m_pSet->column8;
	drawPicture(file);
}


void CMFC综合实验View::OnBnClickedAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	ADD_DLG dlg;
	int t=dlg.DoModal();


	if (t == IDOK)
	{
		m_pSet->AddNew();
		m_pSet->column1 = dlg.name1;
		m_pSet->column2 = dlg.number1;;
		m_pSet->column3 =  dlg.major1;
		m_pSet->column4 = dlg.sex1;;
		m_pSet->column5 = dlg.birth;
		m_pSet->column6 = dlg.phone1;;
		m_pSet->column7 = dlg.home1;
		m_pSet->column8 = dlg.pic1;
		m_pSet->Update();
	    UpdateData(false);
	}
	
}


void CMFC综合实验View::OnBnClickedDelete()
{
	// TODO: 在此添加控件通知处理程序代码
	m_pSet->Delete();
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
}


void CMFC综合实验View::OnBnClickedEdit()
{
	// TODO: 在此添加控件通知处理程序代码
	Edit_DLG dlg;
	
	  dlg.name = m_pSet->column1 ;
	  dlg.number= m_pSet->column2;
	  dlg.major= m_pSet->column3;
	 dlg.sex =m_pSet->column4;
	  dlg.birth=m_pSet->column5;
	  dlg.phone=m_pSet->column6;
	 dlg.home=m_pSet->column7 ;
	  dlg.pic=m_pSet->column8;
	  int t = dlg.DoModal();
	if(t==IDOK)
	{
		m_pSet->Edit();
		m_pSet->column1 = dlg.name;
		m_pSet->column2 = dlg.number;
		m_pSet->column3 = dlg.major;
		m_pSet->column4 = dlg.sex;;
		m_pSet->column5 = dlg.birth;
		m_pSet->column6 = dlg.phone;
		m_pSet->column7 = dlg.home;
		m_pSet->column8 = dlg.pic;
		m_pSet->Update();
		UpdateData(false);

	}
}


void CMFC综合实验View::OnBnClickedSortButton()
{
	// TODO: 在此添加控件通知处理程序代码
	Sort_DLG sort_dlg;
	int t = sort_dlg.DoModal();
	if (t == IDOK)
	{
		m_pSet->m_strSort.Format(_T("%s"), sort_dlg.sort);
		m_pSet->Requery();
		UpdateData(false);
	}

}


void CMFC综合实验View::OnBnClickedSearch()
{
	// TODO: 在此添加控件通知处理程序代码
	Search re_dlg;
	int t = re_dlg.DoModal();
	if (t == IDOK)
	{

		m_pSet->m_strFilter.Format(_T("%s"), re_dlg.search);
		m_pSet->Requery();
		UpdateData(false);
	}
}


void CMFC综合实验View::OnBnClickedTraversal()
{
	// TODO: 在此添加控件通知处理程序代码
	Traver_DLG dlg;
	int n, i;
	CString st, s;

	m_pSet->MoveFirst();
	while (!m_pSet->IsEOF())

	{
		n = m_pSet->GetODBCFieldCount();


		for (i = 1; i < n; i++)
		{
			m_pSet->GetFieldValue((short)i, st);
			s += _T(" ") + st;
		}
		s += _T("\r\n");
		dlg.str = s;
		UpdateData(false);
		m_pSet->MoveNext();
	}
	if (dlg.DoModal() == IDOK)
	{

	}
}


void CMFC综合实验View::OnBnClickedRecover()
{
	// TODO: 在此添加控件通知处理程序代码
	m_pSet->m_strFilter.Format(_T(""));
	m_pSet->m_strSort.Format(_T(""));
	m_pSet->Requery();
	UpdateData(false);
}
