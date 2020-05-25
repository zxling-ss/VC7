
// 第七周课堂练习View.cpp : C第七周课堂练习View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "第七周课堂练习.h"
#endif

#include "第七周课堂练习Doc.h"
#include "第七周课堂练习View.h"
#include "MyDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C第七周课堂练习View

IMPLEMENT_DYNCREATE(C第七周课堂练习View, CView)

BEGIN_MESSAGE_MAP(C第七周课堂练习View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_BUTTON1, &C第七周课堂练习View::OnBnClickedButton1)
END_MESSAGE_MAP()

// C第七周课堂练习View 构造/析构

C第七周课堂练习View::C第七周课堂练习View()
{
	// TODO: 在此处添加构造代码

}

C第七周课堂练习View::~C第七周课堂练习View()
{
}

BOOL C第七周课堂练习View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C第七周课堂练习View 绘制

void C第七周课堂练习View::OnDraw(CDC* pDC)
{
	C第七周课堂练习Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	

}


// C第七周课堂练习View 打印

BOOL C第七周课堂练习View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C第七周课堂练习View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C第七周课堂练习View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C第七周课堂练习View 诊断

#ifdef _DEBUG
void C第七周课堂练习View::AssertValid() const
{
	CView::AssertValid();
}

void C第七周课堂练习View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C第七周课堂练习Doc* C第七周课堂练习View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C第七周课堂练习Doc)));
	return (C第七周课堂练习Doc*)m_pDocument;
}
#endif //_DEBUG


// C第七周课堂练习View 消息处理程序

// 1) 退出对话框后，在客户区显示：“你已退出对话框”
void C第七周课堂练习View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);

	CString s;
	s.Format(_T("“你已退出对话框”"));

	MyDlg dlg;
	int r = dlg.DoModal();


	if (r == IDOK) {
		dc.TextOutW(100, 100, s);

	}
	CView::OnLButtonDown(nFlags, point);
}

// 2) 实现两个编辑框内字符串的交换并显示-----此处无效，具体再MyDlg文件中
void C第七周课堂练习View::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	/*CClientDC dc(this);

	MyDlg dlg;
	int r = dlg.DoModal();
	CString str1;
	CString str2;
	CString str3;

	str1 = dlg.m_edit1;
	str2 = dlg.m_edit2;

	str3 = str1;
	str1 = str2;
	str2 = str3;

	dlg.m_edit1=str1;
	dlg.m_edit2=str2;


	dc.TextOutW(200, 200, dlg.m_edit1);*/
}
