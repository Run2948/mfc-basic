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

// 消息映射的 分界宏
BEGIN_MESSAGE_MAP(MyFrame, CFrameWnd)
	// 鼠标左键按下 宏
	ON_WM_LBUTTONDOWN()
	// 键盘按键 宏
	ON_WM_CHAR()
	// 绘图 宏
	ON_WM_PAINT()

END_MESSAGE_MAP();

MyFrame::MyFrame()
{
	Create(NULL, TEXT("MFC WINDOW"));
}

// 鼠标左键按下事件函数 实现
void MyFrame::OnLButtonDown(UINT nFlags, CPoint point)
{
	{
		// TCHAR buf[1024];
		// wsprintf(buf, TEXT("x = %d, y = %d"), point.x, point.y);
		// MessageBox(buf);
	}

	// MFC 中的字符串
	CString str;
	str.Format(TEXT("x = %d, y = %d"), point.x, point.y);
	MessageBox(str);
}

// 键盘按键按下事件函数 实现
void MyFrame::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	{
		// TCHAR buf[1024];
		// wsprintf(buf, TEXT("您按下了 %c 键"), nChar);
		// MessageBox(buf);
	}

	// MFC 中的字符串
	CString str;
	str.Format(TEXT("您按下了 %c 键"), nChar);
	MessageBox(str);
}

// 绘图事件函数 实现
void MyFrame::OnPaint()
{
	// 画家 画到当前窗口中
	CPaintDC dc(this);
	// 画文字
	dc.TextOutW(100, 100, TEXT("Hello MFC"));
	// 画图形
	dc.Ellipse(10, 10, 100, 100);
}

// Windows 字符集
// ANSI            多字节：1字节/字符
// 中文 韩文...    宽字节：1个字符对应多个字节 Unicode utf8 3字节/字符 gbk 2字节/字符

// 多字节 转 宽字节 的几种方式
// MessageBox(L"aaaaaaa");
// MessageBox(TEXT("aaaaaa")); // TEXT、TCHAR 自动编码转换

// 统计宽字节字符串的长度
// char* p = "aaaa";
// int n = 0;
// n = strlen(p);
//
// wchar_t * p2 = L"bbbbb";
// n = wcslen(p2);

// string与char* char[]之间的转换 https://www.cnblogs.com/cs0915/p/13060525.html

// CString 与 char* 之间的转换
// char* p3 = "aa";
// CString str = CString(p3);
//
// CString str2 = TEXT("abc");
// CStringA tmp;
// tmp = str2;
// char* pp = tmp.GetBuffer();
// MessageBox(CString(pp));
