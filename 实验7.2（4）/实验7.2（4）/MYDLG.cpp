// MYDLG.cpp : 实现文件
//

#include "stdafx.h"
#include "实验7.2（4）.h"
#include "MYDLG.h"
#include "afxdialogex.h"


// MYDLG 对话框

IMPLEMENT_DYNAMIC(MYDLG, CDialogEx)

MYDLG::MYDLG(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, x(_T(""))
	, y(0)
	, z(_T(""))
{

}

MYDLG::~MYDLG()
{
}

void MYDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, x);
	DDX_Text(pDX, IDC_EDIT2, y);
	DDX_Text(pDX, IDC_EDIT3, z);
}


BEGIN_MESSAGE_MAP(MYDLG, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &MYDLG::OnBnClickedButton1)
END_MESSAGE_MAP()


// MYDLG 消息处理程序


void MYDLG::OnBnClickedButton1()
{
	this->UpdateData(true);
	CString s;
	s.Format(_T("%d"), y);
	z = x + s;
	UpdateData(false);
	// TODO: 在此添加控件通知处理程序代码
}
