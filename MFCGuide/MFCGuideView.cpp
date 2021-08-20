
// MFCGuideView.cpp: CMFCGuideView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCGuide.h"
#endif

#include "MFCGuideDoc.h"
#include "MFCGuideView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCGuideView

IMPLEMENT_DYNCREATE(CMFCGuideView, CView)

BEGIN_MESSAGE_MAP(CMFCGuideView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CMFCGuideView 构造/析构

CMFCGuideView::CMFCGuideView() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCGuideView::~CMFCGuideView()
{
}

BOOL CMFCGuideView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCGuideView 绘图

void CMFCGuideView::OnDraw(CDC* pDC)
{
	CMFCGuideDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->TextOutW(100,100,TEXT("Hello MFC OnDraw"));
}


// CMFCGuideView 打印

BOOL CMFCGuideView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCGuideView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCGuideView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFCGuideView 诊断

#ifdef _DEBUG
void CMFCGuideView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCGuideView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCGuideDoc* CMFCGuideView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCGuideDoc)));
	return (CMFCGuideDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCGuideView 消息处理程序


void CMFCGuideView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CString str;
	str.Format(TEXT("x = %d, y = %d"), point.x, point.y);
	MessageBox(str);

	CView::OnLButtonDown(nFlags, point);
}


void CMFCGuideView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CView::OnPaint()
	dc.TextOutW(100,100,TEXT("Hello MFC OnPaint"));
}
