// ADDdition.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "������ʵ��.h"
#include "ADDdition.h"
#include "afxdialogex.h"


// ADDdition �Ի���

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


// ADDdition ��Ϣ�������


void ADDdition::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData();
	//��ȡ�༭�ؼ��е�����
	m_result = m_edit1 + m_edit2;

	UpdateData(false);
}
