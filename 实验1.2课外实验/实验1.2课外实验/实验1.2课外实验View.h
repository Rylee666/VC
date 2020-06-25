
// 实验1.2课外实验View.h : C实验12课外实验View 类的接口
//

#pragma once


class C实验12课外实验View : public CView
{
protected: // 仅从序列化创建
	C实验12课外实验View();
	DECLARE_DYNCREATE(C实验12课外实验View)

// 特性
public:
	C实验12课外实验Doc* GetDocument() const;

// 操作
public:
	CString name2;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~C实验12课外实验View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 实验1.2课外实验View.cpp 中的调试版本
inline C实验12课外实验Doc* C实验12课外实验View::GetDocument() const
   { return reinterpret_cast<C实验12课外实验Doc*>(m_pDocument); }
#endif

