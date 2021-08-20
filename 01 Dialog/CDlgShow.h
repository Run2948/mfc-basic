#pragma once


// CDlgShow 对话框

class CDlgShow : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgShow)

public:
	CDlgShow(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDlgShow();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHOW };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
