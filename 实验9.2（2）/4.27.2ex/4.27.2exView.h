
// 4.27.2exView.h: CMy4272exView 类的接口
//

#pragma once


class CMy4272exView : public CView
{
protected: // 仅从序列化创建
	CMy4272exView() noexcept;
	DECLARE_DYNCREATE(CMy4272exView)

// 特性
public:
	CMy4272exDoc* GetDocument() const;

// 操作
public:
	CRect rect;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMy4272exView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 4.27.2exView.cpp 中的调试版本
inline CMy4272exDoc* CMy4272exView::GetDocument() const
   { return reinterpret_cast<CMy4272exDoc*>(m_pDocument); }
#endif

