#pragma once


// ADDdition �Ի���

class ADDdition : public CDialogEx
{
	DECLARE_DYNAMIC(ADDdition)

public:
	ADDdition(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ADDdition();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	// ����һ
	int m_edit1;
	// �ӷ���
	int m_edit2;
	// �ӷ����
	int m_result;
	afx_msg void OnBnClickedButton1();
};
