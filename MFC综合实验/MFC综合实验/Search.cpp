// Search.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC综合实验.h"
#include "Search.h"
#include "afxdialogex.h"


// Search 对话框

IMPLEMENT_DYNAMIC(Search, CDialogEx)

Search::Search(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG5, pParent)
	, search(_T(""))
{

}

Search::~Search()
{
}

void Search::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, search);
}


BEGIN_MESSAGE_MAP(Search, CDialogEx)
END_MESSAGE_MAP()


// Search 消息处理程序
