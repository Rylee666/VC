#pragma once


// Edit_DLG 对话框

class Edit_DLG : public CDialogEx
{
	DECLARE_DYNAMIC(Edit_DLG)

public:
	Edit_DLG(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Edit_DLG();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString name;
	CString number;
	CString major;
	CString sex;
	CString birth;
	double phone;
	CString home;
	CString pic;
	virtual BOOL OnInitDialog();
};
