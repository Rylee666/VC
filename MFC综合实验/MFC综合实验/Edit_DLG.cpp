// Edit_DLG.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC综合实验.h"
#include "Edit_DLG.h"
#include "afxdialogex.h"


// Edit_DLG 对话框

IMPLEMENT_DYNAMIC(Edit_DLG, CDialogEx)

Edit_DLG::Edit_DLG(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG3, pParent)
	, name(_T(""))
	, number(_T(""))
	, major(_T(""))
	, sex(_T(""))
	, birth(_T(""))
	, phone(0)
	, home(_T(""))
	, pic(_T(""))
{

}

Edit_DLG::~Edit_DLG()
{
}

void Edit_DLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, name);
	DDX_Text(pDX, IDC_EDIT2, number);
	DDX_Text(pDX, IDC_EDIT3, major);
	DDX_Text(pDX, IDC_EDIT4, sex);
	DDX_Text(pDX, IDC_EDIT7, birth);
	DDX_Text(pDX, IDC_EDIT8, phone);
	DDX_Text(pDX, IDC_EDIT5, home);
	DDX_Text(pDX, IDC_EDIT6, pic);
}


BEGIN_MESSAGE_MAP(Edit_DLG, CDialogEx)
END_MESSAGE_MAP()


// Edit_DLG 消息处理程序


BOOL Edit_DLG::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
