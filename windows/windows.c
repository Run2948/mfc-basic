// 底层实现窗口 的头文件
#include<Windows.h>


//6处理窗口过程

// CALLBACK  代表__stdcall 参数的传递顺序：从右到左依次入栈，并且在函数返回前清空堆栈
LRESULT CALLBACK WindowProc(
	HWND hWnd, //消息所属的窗口句柄
	UINT uMsg, //具体消息名称  WM_XXXX 消息名
	WPARAM wParam, //键盘附加消息
	LPARAM lParam  //鼠标附加消息
)
{
	switch (uMsg)
	{
	case WM_CLOSE:
		//所有xxxWindow为结尾的方法 ，都不会进入到消息队列中，而是直接执行
		DestroyWindow(hWnd); //DestroyWindow 发送另一个消息 WM_DESTROY
		break;
	case  WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_LBUTTONDOWN: //鼠标左键按下
	{
		int xPos = LOWORD(lParam);
		int yPos = HIWORD(lParam);

		char buf[1024];
		wsprintf(buf, TEXT("x = %d,y = %d"), xPos, yPos);

		MessageBox(hWnd, buf, TEXT("鼠标左键按下"), MB_OK);

		break;
	}
	case WM_KEYDOWN: //键盘
		MessageBox(hWnd, TEXT("键盘按下"), TEXT("键盘按下"), MB_OK);
		break;

	case WM_PAINT: //绘图
	{
		PAINTSTRUCT ps; //绘图结构体
		const HDC hdc = BeginPaint(hWnd, &ps);
		TextOut(hdc, 100, 100, TEXT("HELLO"), strlen("HELLO"));
		EndPaint(hWnd, &ps);
	}

	break;
	default: break;
	}

	//返回值用默认处理方式
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}


// 程序入口函数
// WINAPI 代表 __stdcall 参数的传递顺序：从右到左依次入栈，并且在函数返回前清空堆栈

int WINAPI WinMain(
	HINSTANCE hInstance, // 应用程序实例句柄
	HINSTANCE hPrevInstance, // 上一个应用程序句柄，在 Win32 环境下，参数一般为 NULL, 不起作用
	LPSTR lpCmdLine, // 命令行参数 char * argv[]
	int nShowCmd) // 显示命令
{
	// 1.设计窗口
	WNDCLASS wc;
	wc.cbClsExtra = 0; // 类的额外内存
	wc.cbWndExtra = 0; // 窗口额外的内存
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); // 设置背景
	wc.hCursor = LoadCursor(NULL, IDC_HAND); // 设置光标：如果第一个参数为 NULL 表示使用系统光标
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION); // 图标：如果第一个参数为 NULL 表示使用系统图标
	wc.hInstance = hInstance; // 应用程序实例句柄：出入 WinMain 中的形参即可
	wc.lpfnWndProc = WindowProc;  // 回到函数（窗口过程）
	wc.lpszClassName = TEXT("WIN"); // 窗口类名称
	wc.lpszMenuName = NULL; // 菜单名称
	wc.style = 0; // 窗口显示风格：0 代表默认风格

	// 2.注册窗口
	RegisterClass(&wc);

	// 3.创建窗口
	/* 参数列表
	 * lpClassName, 类名
	 * lpWindowName, 标题名
	 * dwStyle,	风格 WS_OVERLAPPEDWINDOW
	 * x, 显示坐标，可以使用默认值 CW_USEDEFAULT
	 * y,
	 * nWidth, 显示宽高，可以使用默认值 CW_USEDEFAULT
	 * nHeight,
	 * hWndParent, 父窗口 NULL
	 * hMenu,   菜单 NULL
	 * hInstance,  实例句柄 hInstance
	 * lpParam  （鼠标）附加值 NULL
	 */
	HWND hWnd = CreateWindow(wc.lpszClassName,
		TEXT("WINDOWS"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);

	// 4.显示和更新
	ShowWindow(hWnd, SW_SHOWDEFAULT);
	UpdateWindow(hWnd);

	// 5.通过循环取消息
	/*
	 * HWND    hwnd;  主窗口
	 * UINT    message; 消息名称
	 * WPARAM  wParam; （键盘）附加消息
	 * LPARAM  lParam; （鼠标）附加消息
	 * DWORD   time;  消息产生的时间
	 * POINT   pt; 附加消息 鼠标 x y 坐标
	 */
	MSG msg;
	while (1)
	{
		/**
		 * LPMSG lpMsg, 消息结构体
		 * HWND hWnd, NULL 捕获所有窗口消息
		 * UINT wMsgFilterMin, 过滤最小消息数量  0 捕获所有消息
		 * UINT wMsgFilterMax  过滤最大消息数量  0 捕获所有消息
		 */
		if (GetMessage(&msg, NULL, 0, 0) == FALSE)
		{
			break;
		}

		// 翻译消息
		TranslateMessage(&msg);

		// 分发消息
		DispatchMessage(&msg);
	}

	// 6.处理消息（窗口过程）

	return 0;
}
