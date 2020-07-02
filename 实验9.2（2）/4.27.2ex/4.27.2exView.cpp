
// 4.27.2exView.cpp: CMy4272exView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "4.27.2ex.h"
#endif

#include "4.27.2exDoc.h"
#include "4.27.2exView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy4272exView

IMPLEMENT_DYNCREATE(CMy4272exView, CView)

BEGIN_MESSAGE_MAP(CMy4272exView, CView)
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMy4272exView 构造/析构

CMy4272exView::CMy4272exView() noexcept
{
	// TODO: 在此处添加构造代码

}

CMy4272exView::~CMy4272exView()
{
}

BOOL CMy4272exView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy4272exView 绘图

void CMy4272exView::OnDraw(CDC* pDC)
{
	CMy4272exDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	for (int i = 0; i < pDoc->ca.GetSize(); i++)
	{
		pDC->Ellipse(pDoc->ca[i]);
	}
}


// CMy4272exView 诊断

#ifdef _DEBUG
void CMy4272exView::AssertValid() const
{
	CView::AssertValid();
}

void CMy4272exView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy4272exDoc* CMy4272exView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy4272exDoc)));
	return (CMy4272exDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy4272exView 消息处理程序


void CMy4272exView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnMouseMove(nFlags, point);
	CMy4272exDoc* pDoc = GetDocument();
	if (nFlags)
	{
		rect.left = point.x - 100;
		rect.right = point.x + 100;
		rect.top = point.y - 110;
		rect.bottom = point.y + 100;

		pDoc->ca.Add(rect);
		this->Invalidate();

	}
}
