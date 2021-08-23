// InfoDlg.cpp: 实现文件
//

#include "pch.h"
#include "SaleSystem.h"
#include "InfoDlg.h"

#include "InfoFile.h"


// CInfoDlg

IMPLEMENT_DYNCREATE(CInfoDlg, CFormView)

CInfoDlg::CInfoDlg()
	: CFormView(IDD_DIALOG_INFO)
{

}

CInfoDlg::~CInfoDlg()
{
}

void CInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_List);
}

BEGIN_MESSAGE_MAP(CInfoDlg, CFormView)
END_MESSAGE_MAP()


// CInfoDlg 诊断

#ifdef _DEBUG
void CInfoDlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CInfoDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CInfoDlg 消息处理程序


void CInfoDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类

	// 设置扩展风格
	//LVS_EX_FULLROWSELECT 选中整行，LVS_EX_GRIDLINES 网格
	m_List.SetExtendedStyle(m_List.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	// 初始化表头
	CString fields[] = { _T("商品ID"), _T("商品名称"), _T("商品价格"), _T("库存数量") };
	for (int i = 0; i < sizeof(fields) / sizeof(fields[0]); ++i)
	{
		m_List.InsertColumn(i, fields[i], LVCFMT_CENTER, 100);
	}

	CInfoFile file;
	file.ReadDocline(); //读取商品信息

	// 添加数据
	int i = 0;
	CString str;
	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		str.Format(_T("%d"), it->id);
		m_List.InsertItem(i, str);
		int column = 1;
		m_List.SetItemText(i, column++, (CString)it->name.c_str());
		str.Format(_T("%d"), it->price);
		m_List.SetItemText(i, column++, str);
		str.Format(_T("%d"), it->num);
		m_List.SetItemText(i, column++, str);
		i++;
	}

}
