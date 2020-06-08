
// DBView.h : CDBView 类的接口
//

#pragma once

class CDBSet;

class CDBView : public CRecordView
{
protected: // 仅从序列化创建
	CDBView();
	DECLARE_DYNCREATE(CDBView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_DB_FORM };
#endif
	CDBSet* m_pSet;

// 特性
public:
	CDBDoc* GetDocument() const;

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
	virtual ~CDBView();
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
};

#ifndef _DEBUG  // DBView.cpp 中的调试版本
inline CDBDoc* CDBView::GetDocument() const
   { return reinterpret_cast<CDBDoc*>(m_pDocument); }
#endif

