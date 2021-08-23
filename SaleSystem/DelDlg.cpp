// DelDlg.cpp: 实现文件
//

#include "pch.h"
#include "SaleSystem.h"
#include "DelDlg.h"

#include "InfoFile.h"


// CDelDlg

IMPLEMENT_DYNCREATE(CDelDlg, CFormView)

CDelDlg::CDelDlg()
	: CFormView(IDD_DIALOG_DEL)
	, m_price(0)
	, m_num(0)
{

}

CDelDlg::~CDelDlg()
{
}

void CDelDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_Combox);
	DDX_Text(pDX, IDC_EDIT1, m_price);
	DDX_Text(pDX, IDC_EDIT2, m_num);
}

BEGIN_MESSAGE_MAP(CDelDlg, CFormView)
	ON_BN_CLICKED(IDC_BUTTON3, &CDelDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CDelDlg::OnBnClickedButton4)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CDelDlg::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()


// CDelDlg 诊断

#ifdef _DEBUG
void CDelDlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CDelDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CDelDlg 消息处理程序


void CDelDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码

	// 获取控件上的内容，更新到对应关联的变量中
	UpdateData(TRUE);

	if (m_num == 0)
	{
		MessageBox(TEXT("商品个数不能为0"));
		return;
	}

	CString type;
	// 获取当前选中项
	int index = m_Combox.GetCurSel();
	// 获取组合框当前内容
	m_Combox.GetLBText(index, type);

	CString str;
	str.Format(_T("删除商品：%s \r\n单价：%d \r\n个数：%d "), type, m_price, m_num);
	MessageBox(str);


	// 需要包含 #include "InfoFile.h"
	CInfoFile file;
	// 读取商品信息
	file.ReadDocline();
	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		if (type == it->name.c_str())
		{
			it->num = it->num - m_num;
		}
	}
	// 更新文件内容
	file.WirteDocline();
	m_num = 0;
	// 更新到对应的控件
	UpdateData(FALSE);
}


void CDelDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	// 选择第0项目
	m_Combox.SetCurSel(0);
	m_num = 0;
	OnCbnSelchangeCombo1();
}


void CDelDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	// 读取文件，获取商品名，给组合框添加字符串
	// 需要包含 #include "InfoFile.h"
	CInfoFile file;
	file.ReadDocline(); //读取商品信息
	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		m_Combox.AddString((CString)it->name.c_str());
	}

	// 将第一个商品名设为默认选中项
	m_Combox.SetCurSel(0);
	OnCbnSelchangeCombo1();
}


void CDelDlg::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码

	CString text;
	// 获取当前选中项
	int index = m_Combox.GetCurSel();
	// 获取当前内容
	m_Combox.GetLBText(index, text);

	// 需要包含 #include "InfoFile.h"
	CInfoFile file;
	// 读取商品信息
	file.ReadDocline();
	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		if (text == it->name.c_str())
		{
			m_price = it->price;
			m_num = 0;
			// 内容更新到对应的控件
			UpdateData(FALSE);
		}
	}
}
