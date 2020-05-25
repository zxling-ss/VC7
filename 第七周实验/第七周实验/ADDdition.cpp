// ADDdition.cpp : 实现文件
//

#include "stdafx.h"
#include "第七周实验.h"
#include "ADDdition.h"
#include "afxdialogex.h"


// ADDdition 对话框

IMPLEMENT_DYNAMIC(ADDdition, CDialogEx)

ADDdition::ADDdition(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_edit1(0)
	, m_edit2(0)
	, m_result(0)
{

}

ADDdition::~ADDdition()
{
}

void ADDdition::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_edit1);
	DDX_Text(pDX, IDC_EDIT2, m_edit2);
	DDX_Text(pDX, IDC_EDIT3, m_result);
}


BEGIN_MESSAGE_MAP(ADDdition, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &ADDdition::OnBnClickedButton1)
END_MESSAGE_MAP()


// ADDdition 消息处理程序


void ADDdition::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	//获取编辑控件中的内容
	m_result = m_edit1 + m_edit2;

	UpdateData(false);
}
