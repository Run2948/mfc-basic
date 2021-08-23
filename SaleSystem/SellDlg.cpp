// SellDlg.cpp: 实现文件
//

#include "pch.h"
#include "SaleSystem.h"
#include "SellDlg.h"

#include "InfoFile.h"


// CSellDlg

IMPLEMENT_DYNCREATE(CSellDlg, CFormView)

CSellDlg::CSellDlg()
	: CFormView(IDD_DIALOG_SELL)
	, m_stock(0)
	, m_price(0)
	, m_num(0)
	, m_sellInfo(_T(""))
{

}

CSellDlg::~CSellDlg()
{
}

void CSellDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_Combox);
	DDX_Text(pDX, IDC_EDIT1, m_stock);
	DDX_Text(pDX, IDC_EDIT2, m_price);
	DDX_Text(pDX, IDC_EDIT3, m_num);
	DDX_Text(pDX, IDC_EDIT4, m_sellInfo);
}

BEGIN_MESSAGE_MAP(CSellDlg, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CSellDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CSellDlg::OnBnClickedButton3)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CSellDlg::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()


// CSellDlg 诊断

#ifdef _DEBUG
void CSellDlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CSellDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CSellDlg 消息处理程序


void CSellDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类

	// 初始化销售管理数据
	// 初始化商品下拉框
	CInfoFile file;
	file.ReadDocline();

	// file.ls 包含了所有商品信息
	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		m_Combox.AddString(CString(it->name.c_str()));
	}

	// 设置下拉框默认商品，并且调用切换方法
	m_Combox.SetCurSel(0);
	OnCbnSelchangeCombo1();
}


void CSellDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	// 购买商品 按钮点击
	UpdateData(TRUE);

	if (m_num < 1)
	{
		MessageBox(TEXT("购买商品个数必须大于0"));
		return;
	}

	if (m_stock < m_num)
	{
		MessageBox(TEXT("购买商品的库存不足"));
		return;
	}

	// 开始购买
	int index = m_Combox.GetCurSel();
	CString str;
	m_Combox.GetLBText(index, str);

	CInfoFile file;
	file.ReadDocline();

	// file.ls 包含了所有商品信息
	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		if (CString(it->name.c_str()) == str)
		{
			it->num -= m_num;
			m_stock = it->num;

			// 右侧信息提示
			CString info;
			info.Format(_T("商品：%s \r\n单价：%d \r\n个数：%d \r\n总价：%d"), str, m_price, m_num, m_price * m_num);
			m_sellInfo = info; //销售信息
			// 重新购买
			m_num = 0;
			UpdateData(FALSE);

			MessageBox(_T("购买成功！"));
		}
	}

	// 购买内容清空
	m_sellInfo.Empty();
	// 将剩余库存数据写入到文件中
	file.WirteDocline();

	UpdateData(FALSE);
}


void CSellDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码

	// 取消按钮 事件

	m_num = 0;
	UpdateData(FALSE);

	m_Combox.SetCurSel(0);
	OnCbnSelchangeCombo1();
}


void CSellDlg::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码

	// 商品切换触发的事件

	int index = m_Combox.GetCurSel();
	CString str;
	m_Combox.GetLBText(index, str);

	// 根据商品名称 获取这个商品的库存和单价，显示到窗口中

	CInfoFile file;
	file.ReadDocline();

	// file.ls 包含了所有商品信息
	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		if (CString(it->name.c_str()) == str)
		{
			m_stock = it->num;
			m_price = it->price;
			UpdateData(FALSE);
		}
	}
}
