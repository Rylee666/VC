
// 实验1.2课外实验.h : 实验1.2课外实验 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// C实验12课外实验App:
// 有关此类的实现，请参阅 实验1.2课外实验.cpp
//

class C实验12课外实验App : public CWinApp
{
public:
	C实验12课外实验App();


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C实验12课外实验App theApp;
