
// DBView.h : CDBView ��Ľӿ�
//

#pragma once

class CDBSet;

class CDBView : public CRecordView
{
protected: // �������л�����
	CDBView();
	DECLARE_DYNCREATE(CDBView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_DB_FORM };
#endif
	CDBSet* m_pSet;

// ����
public:
	CDBDoc* GetDocument() const;

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
	virtual ~CDBView();
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
};

#ifndef _DEBUG  // DBView.cpp �еĵ��԰汾
inline CDBDoc* CDBView::GetDocument() const
   { return reinterpret_cast<CDBDoc*>(m_pDocument); }
#endif

