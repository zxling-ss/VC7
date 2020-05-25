#pragma once


// ADDdition 对话框

class ADDdition : public CDialogEx
{
	DECLARE_DYNAMIC(ADDdition)

public:
	ADDdition(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ADDdition();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	// 加数一
	int m_edit1;
	// 加法二
	int m_edit2;
	// 加法结果
	int m_result;
	afx_msg void OnBnClickedButton1();
};
