// CDlgShow.cpp: 实现文件
//

#include "pch.h"
#include "01 Dialog.h"
#include "CDlgShow.h"
#include "afxdialogex.h"


// CDlgShow 对话框

IMPLEMENT_DYNAMIC(CDlgShow, CDialogEx)

CDlgShow::CDlgShow(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SHOW, pParent)
{

}

CDlgShow::~CDlgShow()
{
}

void CDlgShow::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgShow, CDialogEx)
END_MESSAGE_MAP()


// CDlgShow 消息处理程序
