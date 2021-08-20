
// 02 StaticTextDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "02 StaticText.h"
#include "02 StaticTextDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMy02StaticTextDlg 对话框



CMy02StaticTextDlg::CMy02StaticTextDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MY02_STATICTEXT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy02StaticTextDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TEXT, m_Text);
	DDX_Control(pDX, IDC_TEXT, m_Text);
	DDX_Control(pDX, IDC_IMAGE, m_Image);
	DDX_Control(pDX, IDC_BUTTON3, m_Btn);
}

BEGIN_MESSAGE_MAP(CMy02StaticTextDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMy02StaticTextDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMy02StaticTextDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CMy02StaticTextDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMy02StaticTextDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMy02StaticTextDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CMy02StaticTextDlg 消息处理程序

BOOL CMy02StaticTextDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	// 在 StaticText 中展示图片
	/*
	 * SS_BITMAP 位图
	 * SS_CENTERIMAGE 居中显示
	 */
	m_Image.ModifyStyle(0xf, SS_BITMAP | SS_CENTERIMAGE);
# define HBMP(filePath,width,height) (HBITMAP)LoadImage(AfxGetInstanceHandle(),filePath,IMAGE_BITMAP,width,height,LR_LOADFROMFILE | LR_CREATEDIBSECTION)
	CRect rect;
	m_Image.GetWindowRect(rect);
	m_Image.SetBitmap(HBMP(TEXT("./res/1.bmp"), rect.Width(), rect.Height()));

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMy02StaticTextDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMy02StaticTextDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMy02StaticTextDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMy02StaticTextDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	// 点击设置按钮，设置为文本 呵呵
	m_Text.SetWindowTextW(TEXT("呵呵"));
}


void CMy02StaticTextDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str;
	m_Text.GetWindowTextW(str);
	MessageBox(str);

	m_Text.SetWindowTextW(TEXT("哈哈"));
}

void CMy02StaticTextDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	// 获取 当前按钮的文本

	CString str;
	m_Btn.GetWindowTextW(str);

	// 设置 当前按钮的文本
	m_Btn.SetWindowTextW(TEXT("(〃'▽'〃)"));

	// 禁用 当前按钮
	m_Btn.EnableWindow(FALSE);
}
