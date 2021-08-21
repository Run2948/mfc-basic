
// SaleSystemView.h: CSaleSystemView 类的接口
//

#pragma once


class CSaleSystemView : public CView
{
protected: // 仅从序列化创建
	CSaleSystemView() noexcept;
	DECLARE_DYNCREATE(CSaleSystemView)

// 特性
public:
	CSaleSystemDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CSaleSystemView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // SaleSystemView.cpp 中的调试版本
inline CSaleSystemDoc* CSaleSystemView::GetDocument() const
   { return reinterpret_cast<CSaleSystemDoc*>(m_pDocument); }
#endif

