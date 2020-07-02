// Enlarge_DLG.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC综合实验.h"
#include "Enlarge_DLG.h"
#include "afxdialogex.h"


// Enlarge_DLG 对话框

IMPLEMENT_DYNAMIC(Enlarge_DLG, CDialogEx)

Enlarge_DLG::Enlarge_DLG(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

Enlarge_DLG::~Enlarge_DLG()
{
}

void Enlarge_DLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Enlarge_DLG, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// Enlarge_DLG 消息处理程序


BOOL Enlarge_DLG::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	GetDlgItem(IDC_STATIC2)->GetClientRect(&picRect);
	InvalidateRect(picRect);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
void Enlarge_DLG::drawPicture(CString filename)
{
	CImage img;
	img.Load(filename);
	CDC* pDC = GetDlgItem(IDC_STATIC2)->GetDC();
	int w, h, sx, sy;
	float rect_radio = 1.0 * picRect.Width() / picRect.Height();
	float image_radio = 1.0 * img.GetWidth() / img.GetHeight();
	if (rect_radio > image_radio)
	{
		h = picRect.Height();
		w = image_radio * h;
		sx = (picRect.Width() - w) / 2;
		sy = 0;
	}
	else {
		w = picRect.Width();
		h = w / image_radio;
		sx = 0;
		sy = (picRect.Height() - h) / 2;
	}
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
}

void Enlarge_DLG::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CDialogEx::OnPaint()
	drawPicture(fil);
}
