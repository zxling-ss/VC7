// MyDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�����ܿ�����ϰ.h"
#include "MyDlg.h"
#include "afxdialogex.h"


// MyDlg �Ի���

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


// MyDlg ��Ϣ�������

// 2) ʵ�������༭�����ַ����Ľ�������ʾ
void MyDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������


	//ͨ��Update��������༭�ؼ��еı�����ȡ����ǰ�༭���е�����
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
	//ͨ��Update���Ա����е����ݸ��µ��༭�ؼ���
	UpdateData(false);

}
