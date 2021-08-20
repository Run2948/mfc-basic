
// 03 EditCtrlDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "03 EditCtrl.h"
#include "03 EditCtrlDlg.h"
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


// CMy03EditCtrlDlg 对话框



CMy03EditCtrlDlg::CMy03EditCtrlDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MY03_EDITCTRL_DIALOG, pParent)
	, m_Edit3(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy03EditCtrlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_Edit1);
	DDX_Control(pDX, IDC_EDIT2, m_Edit2);
	DDX_Text(pDX, IDC_EDIT3, m_Edit3);
}

BEGIN_MESSAGE_MAP(CMy03EditCtrlDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMy03EditCtrlDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMy03EditCtrlDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMy03EditCtrlDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMy03EditCtrlDlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CMy03EditCtrlDlg 消息处理程序

BOOL CMy03EditCtrlDlg::OnInitDialog()
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
	m_Edit1.SetWindowTextW(TEXT("C++学院"));

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMy03EditCtrlDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy03EditCtrlDlg::OnPaint()
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
HCURSOR CMy03EditCtrlDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMy03EditCtrlDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	// 点击复制 将 Edit1 中的内容复制粘贴到 Edit2 中
	CString str;
	m_Edit1.GetWindowTextW(str);
	m_Edit2.SetWindowTextW(str);
}


void CMy03EditCtrlDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码

	// 点击关闭 退出当前对话框

	// 退出程序
	// exit(0);

	// 退出对话框可以 取消 也可以 确定，根据具体需求选择即可
	// CDialogEx::OnOK();
	CDialogEx::OnCancel();
}


void CMy03EditCtrlDlg::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类
	// 按回车，默认对话框的关联 OnOK 方法
	// CDialogEx::OnOK();
}


void CMy03EditCtrlDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码

	// 设置 Edit3 内容
	m_Edit3 = TEXT("哈哈哈");
	// 将变量 同步到控件上
	UpdateData(FALSE);
}


void CMy03EditCtrlDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码

	// 将空间上的内容 同步到变量上
	UpdateData(TRUE);

	// 获取 Edit3 内容
	MessageBox(m_Edit3);
}
