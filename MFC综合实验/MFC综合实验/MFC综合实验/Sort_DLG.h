#pragma once


// Sort_DLG 对话框

class Sort_DLG : public CDialogEx
{
	DECLARE_DYNAMIC(Sort_DLG)

public:
	Sort_DLG(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Sort_DLG();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString sort;
};
