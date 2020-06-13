
// 实验7.2（4）View.cpp : C实验72（4）View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "实验7.2（4）.h"
#endif

#include "实验7.2（4）Doc.h"
#include "实验7.2（4）View.h"
#include "MYDLG.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C实验72（4）View

IMPLEMENT_DYNCREATE(C实验72（4）View, CView)

BEGIN_MESSAGE_MAP(C实验72（4）View, CView)
	ON_COMMAND(ID_POPOUT, &C实验72（4）View::OnPopout)
END_MESSAGE_MAP()

// C实验72（4）View 构造/析构

C实验72（4）View::C实验72（4）View()
{
	// TODO: 在此处添加构造代码

}

C实验72（4）View::~C实验72（4）View()
{
}

BOOL C实验72（4）View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C实验72（4）View 绘制

void C实验72（4）View::OnDraw(CDC* /*pDC*/)
{
	C实验72（4）Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C实验72（4）View 诊断

#ifdef _DEBUG
void C实验72（4）View::AssertValid() const
{
	CView::AssertValid();
}

void C实验72（4）View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C实验72（4）Doc* C实验72（4）View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C实验72（4）Doc)));
	return (C实验72（4）Doc*)m_pDocument;
}
#endif //_DEBUG


// C实验72（4）View 消息处理程序


void C实验72（4）View::OnPopout()
{
	MYDLG dlg;
	int r = dlg.DoModal();
	if (r == IDOK)
	{

	}
	// TODO: 在此添加命令处理程序代码
}
