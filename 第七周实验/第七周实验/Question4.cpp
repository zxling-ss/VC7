// Question4.cpp : 实现文件
//

#include "stdafx.h"
#include "第七周实验.h"
#include "Question4.h"
#include "afxdialogex.h"


// Question4 对话框

IMPLEMENT_DYNAMIC(Question4, CDialogEx)

Question4::Question4(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, m_edit1(_T(""))
	, m_edit2(0)
	, result(_T(""))
{

}

Question4::~Question4()
{
}

void Question4::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_edit1);
	DDX_Text(pDX, IDC_EDIT2, m_edit2);
	DDX_Text(pDX, IDC_EDIT3, result);
}


BEGIN_MESSAGE_MAP(Question4, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Question4::OnBnClickedButton1)
END_MESSAGE_MAP()


// Question4 消息处理程序


void Question4::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	CString s;
	s.Format(_T("%d"), m_edit2);
	result = m_edit1 + s;
	UpdateData(false);
}
