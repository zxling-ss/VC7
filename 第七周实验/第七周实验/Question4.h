#pragma once


// Question4 对话框

class Question4 : public CDialogEx
{
	DECLARE_DYNAMIC(Question4)

public:
	Question4(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Question4();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	// 字符
	CString m_edit1;
	// 数值
	int m_edit2;
	// 拼接结果
	CString result;
	afx_msg void OnBnClickedButton1();
};
