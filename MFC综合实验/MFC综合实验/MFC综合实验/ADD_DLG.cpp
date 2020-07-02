// ADD_DLG.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC综合实验.h"
#include "ADD_DLG.h"
#include "afxdialogex.h"


// ADD_DLG 对话框

IMPLEMENT_DYNAMIC(ADD_DLG, CDialogEx)

ADD_DLG::ADD_DLG(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, name1(_T(""))
	, number1(_T(""))
	, major1(_T(""))
	, sex1(_T(""))
	, birth(_T(""))
	, phone1(0)
	, home1(_T(""))
	, pic1(_T(""))
{

}

ADD_DLG::~ADD_DLG()
{
}

void ADD_DLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, name1);
	DDX_Text(pDX, IDC_EDIT2, number1);
	DDX_Text(pDX, IDC_EDIT3, major1);
	DDX_Text(pDX, IDC_EDIT4, sex1);
	DDX_Text(pDX, IDC_EDIT5, birth);
	DDX_Text(pDX, IDC_EDIT6, phone1);
	DDX_Text(pDX, IDC_EDIT7, home1);
	DDX_Text(pDX, IDC_EDIT8, pic1);
}


BEGIN_MESSAGE_MAP(ADD_DLG, CDialogEx)
END_MESSAGE_MAP()


// ADD_DLG 消息处理程序
