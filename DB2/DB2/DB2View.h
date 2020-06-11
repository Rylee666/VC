
// DB2View.h : CDB2View ��Ľӿ�
//

#pragma once

class CDB2Set;

class CDB2View : public CRecordView
{
protected: // �������л�����
	CDB2View();
	DECLARE_DYNCREATE(CDB2View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_DB2_FORM };
#endif
	CDB2Set* m_pSet;

// ����
public:
	CDB2Doc* GetDocument() const;

// ����
public:
	CString path, filename;
	CRect rect;
	int n = 0;
// ��д
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CDB2View();
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
	CString age;
	CString number;
	CString phoneNum;
	afx_msg void OnBnClickedButton1();
	virtual void foo(CImage&img, int&sx, int&sy, int&w, int&h);
	virtual void OnDraw(CDC* /*pDC*/);
	afx_msg void OnPaint();
	//afx_msg void OnRecordFirst();
	//afx_msg void OnRecordPrev();
	//afx_msg void OnRecordNext();
	//afx_msg void OnRecordLast();
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
};

#ifndef _DEBUG  // DB2View.cpp �еĵ��԰汾
inline CDB2Doc* CDB2View::GetDocument() const
   { return reinterpret_cast<CDB2Doc*>(m_pDocument); }
#endif

