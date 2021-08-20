#pragma once
// MFC 需要包含的头文件
#include <afxwin.h>

// CWinApp 应用程序类
class MyApp : public CWinApp
{
public:
	// MFC 程序入口
	virtual BOOL InitInstance();

};

// 窗口框架类
class MyFrame :public CFrameWnd
{
public:
	// 窗口构造函数
	MyFrame();

	// 声明消息映射
	DECLARE_MESSAGE_MAP()

	// 声明鼠标左击的处理函数
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);

	// 声明键盘按键的处理函数
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);

	// 声明绘图的处理函数
	afx_msg void OnPaint();
};
