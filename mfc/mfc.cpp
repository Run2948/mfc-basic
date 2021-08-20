#include "mfc.h"

// 应用程序对象（有且仅有一个）
MyApp app;

BOOL MyApp::InitInstance()
{
	{
		// // 创建窗口
		// MyFrame* frame = new MyFrame;
		//
		// // 显示 和 更新
		// frame->ShowWindow(SW_SHOWNORMAL);
		// frame->UpdateWindow();
		//
		// // 保存执行应用程序的主窗口的指针
		// m_pMainWnd = frame;
	}

	// 创建窗口
	m_pMainWnd = new MyFrame;
	// 显示 和 更新
	m_pMainWnd->ShowWindow(SW_SHOWNORMAL);
	m_pMainWnd->UpdateWindow();

	// 返回正常初始化
	return TRUE;
}

MyFrame::MyFrame()
{
	Create(NULL, TEXT("MFC WINDOW"));
}
