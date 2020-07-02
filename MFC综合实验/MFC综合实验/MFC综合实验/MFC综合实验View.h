
// MFC综合实验View.h : CMFC综合实验View 类的接口
//

#pragma once

class CMFC综合实验Set;

class CMFC综合实验View : public CRecordView
{
protected: // 仅从序列化创建
	CMFC综合实验View();
	DECLARE_DYNCREATE(CMFC综合实验View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFC_FORM };
#endif
	CMFC综合实验Set* m_pSet;

// 特性
public:
	CMFC综合实验Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CMFC综合实验View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	CString name;
	CString number;
	CString major;
	CString sex;
	CString birth;
	double phone;
	CString home;
	CString pic_add;
	CString file;
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
	afx_msg void OnBnClickedEnlarge();
	virtual void drawPicture(CString filename);
	virtual void OnDraw(CDC* /*pDC*/);
	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedDelete();
	afx_msg void OnBnClickedEdit();
	afx_msg void OnBnClickedSortButton();
	afx_msg void OnBnClickedSearch();
	afx_msg void OnBnClickedTraversal();
	afx_msg void OnBnClickedRecover();
};

#ifndef _DEBUG  // MFC综合实验View.cpp 中的调试版本
inline CMFC综合实验Doc* CMFC综合实验View::GetDocument() const
   { return reinterpret_cast<CMFC综合实验Doc*>(m_pDocument); }
#endif

