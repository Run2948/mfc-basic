
// MainFrm.cpp: CMainFrame 类的实现
//

#include "pch.h"
#include "framework.h"
#include "SaleSystem.h"

#include "MainFrm.h"

#include "AddDlg.h"
#include "SelectView.h"
#include "DisplayView.h"
#include "InfoDlg.h"
#include "SellDlg.h"
#include "UserDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()

	//ON_MESSAGE响应的是自定义消息
	//产生NM_X消息，自动调用OnMyChange函数
	ON_MESSAGE(NM_A, OnMyChange)
	ON_MESSAGE(NM_B, OnMyChange)
	ON_MESSAGE(NM_C, OnMyChange)
	ON_MESSAGE(NM_D, OnMyChange)
	ON_MESSAGE(NM_E, OnMyChange)

END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // 状态行指示器
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame 构造/析构

CMainFrame::CMainFrame() noexcept
{
	// TODO: 在此添加成员初始化代码
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("未能创建状态栏\n");
		return -1;      // 未能创建
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators) / sizeof(UINT));

	// 修改项目图标
	SetClassLong(m_hWnd, GCL_HICON, (LONG)AfxGetApp()->LoadIconW(IDI_ICON_WIN));

	// 修改标题（右侧）
	SetTitle(TEXT("SaleSystem"));

	// 修改主窗口大小
	MoveWindow(0, 0, 800, 500);

	// 居中显示
	CenterWindow();

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if (!CFrameWnd::PreCreateWindow(cs))
		return FALSE;
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return TRUE;
}

// CMainFrame 诊断

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame 消息处理程序



BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	// TODO: 在此添加专用代码和/或调用基类

	// 创建静态窗口  拆分
	m_Splitter.CreateStatic(this, 1, 2);
	// 左侧窗口
	m_Splitter.CreateView(0, 0, RUNTIME_CLASS(CSelectView), CSize(200, 500), pContext);
	// 右侧窗口
	m_Splitter.CreateView(0, 1, RUNTIME_CLASS(CDisplayView), CSize(600, 500), pContext);

	// return CFrameWnd::OnCreateClient(lpcs, pContext);
	return TRUE; //  用户自定义拆分
}

LRESULT CMainFrame::OnMyChange(WPARAM wParam, LPARAM lParam)
{
	CCreateContext  Context;
	switch (wParam)
	{
	case NM_A:
		// MessageBox(_T("NM_A"));
	{
		// CUserDlg类需要包含头文件#include "UserDlg.h"
		Context.m_pNewViewClass = RUNTIME_CLASS(CUserDlg);
		Context.m_pCurrentFrame = this;
		Context.m_pLastView = (CFormView*)m_Splitter.GetPane(0, 1);
		m_Splitter.DeleteView(0, 1);
		m_Splitter.CreateView(0, 1, RUNTIME_CLASS(CUserDlg), CSize(600, 500), &Context);
		CUserDlg* pNewView = (CUserDlg*)m_Splitter.GetPane(0, 1);
		m_Splitter.RecalcLayout();
		pNewView->OnInitialUpdate();
		m_Splitter.SetActivePane(0, 1);
	}
	break;
	case NM_B:
		// MessageBox(_T("NM_B"));
	{
		// CSellDlg类需要包含头文件#include "SellDlg.h"
		Context.m_pNewViewClass = RUNTIME_CLASS(CSellDlg);
		Context.m_pCurrentFrame = this;
		Context.m_pLastView = (CFormView*)m_Splitter.GetPane(0, 1);
		m_Splitter.DeleteView(0, 1);
		m_Splitter.CreateView(0, 1, RUNTIME_CLASS(CSellDlg), CSize(600, 500), &Context);
		CSellDlg* pNewView = (CSellDlg*)m_Splitter.GetPane(0, 1);
		m_Splitter.RecalcLayout();
		pNewView->OnInitialUpdate();
		m_Splitter.SetActivePane(0, 1);
	}
	break;
	case NM_C:
		// MessageBox(_T("NM_C"));
	{
		// CInfoDlg类需要包含头文件#include "InfoDlg.h"
		Context.m_pNewViewClass = RUNTIME_CLASS(CInfoDlg);
		Context.m_pCurrentFrame = this;
		Context.m_pLastView = (CFormView*)m_Splitter.GetPane(0, 1);
		m_Splitter.DeleteView(0, 1);
		m_Splitter.CreateView(0, 1, RUNTIME_CLASS(CInfoDlg), CSize(600, 500), &Context);
		CInfoDlg* pNewView = (CInfoDlg*)m_Splitter.GetPane(0, 1);
		m_Splitter.RecalcLayout();
		pNewView->OnInitialUpdate();
		m_Splitter.SetActivePane(0, 1);
	}
	break;
	case NM_D:
		// MessageBox(_T("NM_D"));
	{
		// CInfoDlg类需要包含头文件#include "AddDlg.h"
		Context.m_pNewViewClass = RUNTIME_CLASS(CAddDlg);
		Context.m_pCurrentFrame = this;
		Context.m_pLastView = (CFormView*)m_Splitter.GetPane(0, 1);
		m_Splitter.DeleteView(0, 1);
		m_Splitter.CreateView(0, 1, RUNTIME_CLASS(CAddDlg), CSize(600, 500), &Context);
		CAddDlg* pNewView = (CAddDlg*)m_Splitter.GetPane(0, 1);
		m_Splitter.RecalcLayout();
		pNewView->OnInitialUpdate();
		m_Splitter.SetActivePane(0, 1);
	}
	break;
	case NM_E:
		MessageBox(_T("NM_E"));
		break;
	default:
		MessageBox(_T("error"));
	}

	return 0;
}
