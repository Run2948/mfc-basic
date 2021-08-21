
// SaleSystemView.cpp: CSaleSystemView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "SaleSystem.h"
#endif

#include "SaleSystemDoc.h"
#include "SaleSystemView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSaleSystemView

IMPLEMENT_DYNCREATE(CSaleSystemView, CView)

BEGIN_MESSAGE_MAP(CSaleSystemView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CSaleSystemView 构造/析构

CSaleSystemView::CSaleSystemView() noexcept
{
	// TODO: 在此处添加构造代码

}

CSaleSystemView::~CSaleSystemView()
{
}

BOOL CSaleSystemView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CSaleSystemView 绘图

void CSaleSystemView::OnDraw(CDC* /*pDC*/)
{
	CSaleSystemDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CSaleSystemView 打印

BOOL CSaleSystemView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CSaleSystemView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CSaleSystemView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CSaleSystemView 诊断

#ifdef _DEBUG
void CSaleSystemView::AssertValid() const
{
	CView::AssertValid();
}

void CSaleSystemView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSaleSystemDoc* CSaleSystemView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSaleSystemDoc)));
	return (CSaleSystemDoc*)m_pDocument;
}
#endif //_DEBUG


// CSaleSystemView 消息处理程序
