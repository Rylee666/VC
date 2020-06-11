
// DB1View.h : CDB1View ��Ľӿ�
//

#pragma once

class CDB1Set;

class CDB1View : public CRecordView
{
protected: // �������л�����
	CDB1View();
	DECLARE_DYNCREATE(CDB1View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_DB1_FORM };
#endif
	CDB1Set* m_pSet;

// ����
public:
	CDB1Doc* GetDocument() const;

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
	virtual ~CDB1View();
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
	CString photo;
};

#ifndef _DEBUG  // DB1View.cpp �еĵ��԰汾
inline CDB1Doc* CDB1View::GetDocument() const
   { return reinterpret_cast<CDB1Doc*>(m_pDocument); }
#endif

