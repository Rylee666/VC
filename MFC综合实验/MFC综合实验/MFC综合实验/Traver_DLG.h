#pragma once


// Traver_DLG 对话框

class Traver_DLG : public CDialogEx
{
	DECLARE_DYNAMIC(Traver_DLG)

public:
	Traver_DLG(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Traver_DLG();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG6 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString str;
};
