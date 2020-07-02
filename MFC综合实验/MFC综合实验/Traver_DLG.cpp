// Traver_DLG.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC综合实验.h"
#include "Traver_DLG.h"
#include "afxdialogex.h"


// Traver_DLG 对话框

IMPLEMENT_DYNAMIC(Traver_DLG, CDialogEx)

Traver_DLG::Traver_DLG(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG6, pParent)
	, str(_T(""))
{

}

Traver_DLG::~Traver_DLG()
{
}

void Traver_DLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, str);
}


BEGIN_MESSAGE_MAP(Traver_DLG, CDialogEx)
END_MESSAGE_MAP()


// Traver_DLG 消息处理程序
