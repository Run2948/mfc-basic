#pragma once
// MFC 需要包含的头文件
#include <afxwin.h>

// CWinApp 应用程序类
class MyApp : public CWinApp
{
public:
	// MFC 程序入口
	virtual BOOL InitInstance() override;

};

// 窗口框架类
class MyFrame :public CFrameWnd
{
public:
	// 窗口构造函数
	MyFrame();
};
