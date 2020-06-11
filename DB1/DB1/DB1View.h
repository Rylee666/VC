
// DB1View.h : CDB1View 类的接口
//

#pragma once

class CDB1Set;

class CDB1View : public CRecordView
{
protected: // 仅从序列化创建
	CDB1View();
	DECLARE_DYNCREATE(CDB1View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_DB1_FORM };
#endif
	CDB1Set* m_pSet;

// 特性
public:
	CDB1Doc* GetDocument() const;

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
	virtual ~CDB1View();
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
	CString photo;
};

#ifndef _DEBUG  // DB1View.cpp 中的调试版本
inline CDB1Doc* CDB1View::GetDocument() const
   { return reinterpret_cast<CDB1Doc*>(m_pDocument); }
#endif

