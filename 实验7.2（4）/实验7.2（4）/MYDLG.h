#pragma once


// MYDLG 对话框

class MYDLG : public CDialogEx
{
	DECLARE_DYNAMIC(MYDLG)

public:
	MYDLG(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~MYDLG();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString x;
	int y;
	CString z;
	afx_msg void OnBnClickedButton1();
};
