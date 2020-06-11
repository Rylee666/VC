
// DBDBView.h : CDBDBView 类的接口
//

#pragma once
#include "afxwin.h"

class CDBDBSet;

class CDBDBView : public CRecordView
{
protected: // 仅从序列化创建
	CDBDBView();
	DECLARE_DYNCREATE(CDBDBView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_DBDB_FORM };
#endif
	CDBDBSet* m_pSet;

// 特性
public:
	CDBDBDoc* GetDocument() const;
	CRect picRect;

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
	virtual ~CDBDBView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	long ID;
	CString name;
	CString number;
	CString age;
	CString phoneNum;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnPaint();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordPrev();
	afx_msg void OnEnChangeEdit1();
};

#ifndef _DEBUG  // DBDBView.cpp 中的调试版本
inline CDBDBDoc* CDBDBView::GetDocument() const
   { return reinterpret_cast<CDBDBDoc*>(m_pDocument); }
#endif

