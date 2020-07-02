#pragma once


// Enlarge_DLG 对话框

class Enlarge_DLG : public CDialogEx
{
	DECLARE_DYNAMIC(Enlarge_DLG)

public:
	Enlarge_DLG(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Enlarge_DLG();
	CString fil;
	CRect picRect;
	virtual void drawPicture(CString filename);
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
};
