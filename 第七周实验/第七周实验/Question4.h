#pragma once


// Question4 �Ի���

class Question4 : public CDialogEx
{
	DECLARE_DYNAMIC(Question4)

public:
	Question4(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Question4();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	// �ַ�
	CString m_edit1;
	// ��ֵ
	int m_edit2;
	// ƴ�ӽ��
	CString result;
	afx_msg void OnBnClickedButton1();
};
