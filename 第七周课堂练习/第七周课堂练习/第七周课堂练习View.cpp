
// �����ܿ�����ϰView.cpp : C�����ܿ�����ϰView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "�����ܿ�����ϰ.h"
#endif

#include "�����ܿ�����ϰDoc.h"
#include "�����ܿ�����ϰView.h"
#include "MyDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�����ܿ�����ϰView

IMPLEMENT_DYNCREATE(C�����ܿ�����ϰView, CView)

BEGIN_MESSAGE_MAP(C�����ܿ�����ϰView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_BUTTON1, &C�����ܿ�����ϰView::OnBnClickedButton1)
END_MESSAGE_MAP()

// C�����ܿ�����ϰView ����/����

C�����ܿ�����ϰView::C�����ܿ�����ϰView()
{
	// TODO: �ڴ˴���ӹ������

}

C�����ܿ�����ϰView::~C�����ܿ�����ϰView()
{
}

BOOL C�����ܿ�����ϰView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C�����ܿ�����ϰView ����

void C�����ܿ�����ϰView::OnDraw(CDC* pDC)
{
	C�����ܿ�����ϰDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	

}


// C�����ܿ�����ϰView ��ӡ

BOOL C�����ܿ�����ϰView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C�����ܿ�����ϰView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C�����ܿ�����ϰView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C�����ܿ�����ϰView ���

#ifdef _DEBUG
void C�����ܿ�����ϰView::AssertValid() const
{
	CView::AssertValid();
}

void C�����ܿ�����ϰView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C�����ܿ�����ϰDoc* C�����ܿ�����ϰView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�����ܿ�����ϰDoc)));
	return (C�����ܿ�����ϰDoc*)m_pDocument;
}
#endif //_DEBUG


// C�����ܿ�����ϰView ��Ϣ�������

// 1) �˳��Ի�����ڿͻ�����ʾ���������˳��Ի���
void C�����ܿ�����ϰView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);

	CString s;
	s.Format(_T("�������˳��Ի���"));

	MyDlg dlg;
	int r = dlg.DoModal();


	if (r == IDOK) {
		dc.TextOutW(100, 100, s);

	}
	CView::OnLButtonDown(nFlags, point);
}

// 2) ʵ�������༭�����ַ����Ľ�������ʾ-----�˴���Ч��������MyDlg�ļ���
void C�����ܿ�����ϰView::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
