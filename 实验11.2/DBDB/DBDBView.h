
// DBDBView.h : CDBDBView ��Ľӿ�
//

#pragma once
#include "afxwin.h"

class CDBDBSet;

class CDBDBView : public CRecordView
{
protected: // �������л�����
	CDBDBView();
	DECLARE_DYNCREATE(CDBDBView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_DBDB_FORM };
#endif
	CDBDBSet* m_pSet;

// ����
public:
	CDBDBDoc* GetDocument() const;
	CRect picRect;

// ����
public:

// ��д
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CDBDBView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
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

#ifndef _DEBUG  // DBDBView.cpp �еĵ��԰汾
inline CDBDBDoc* CDBDBView::GetDocument() const
   { return reinterpret_cast<CDBDBDoc*>(m_pDocument); }
#endif

