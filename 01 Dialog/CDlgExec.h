#pragma once


// CDlgExec 对话框

class CDlgExec : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgExec)

public:
	CDlgExec(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDlgExec();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EXEC };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
