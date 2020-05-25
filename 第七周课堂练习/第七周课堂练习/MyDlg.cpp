// MyDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "第七周课堂练习.h"
#include "MyDlg.h"
#include "afxdialogex.h"


// MyDlg 对话框

IMPLEMENT_DYNAMIC(MyDlg, CDialogEx)

MyDlg::MyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_edit1(_T(""))
	, m_edit2(_T(""))
{

}

MyDlg::~MyDlg()
{
}

void MyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_edit1);
	DDX_Text(pDX, IDC_EDIT2, m_edit2);
}


BEGIN_MESSAGE_MAP(MyDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &MyDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// MyDlg 消息处理程序

// 2) 实现两个编辑框内字符串的交换并显示
void MyDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码


	//通过Update可以让你编辑控件中的变量获取到当前编辑框中的内容
	UpdateData();

	CString str1;
	CString str2;
	CString str3;

	str1 = m_edit1;
	str2 = m_edit2;

	str3 = str1;
	str1 = str2;
	str2 = str3;

	m_edit1=str1;
	m_edit2 = str2;
	//通过Update可以变量中的内容更新到编辑控件中
	UpdateData(false);

}
