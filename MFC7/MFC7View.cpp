
// MFC7View.cpp : CMFC7View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC7.h"
#endif

#include "MFC7Doc.h"
#include "MFC7View.h"
#include "MyDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC7View

IMPLEMENT_DYNCREATE(CMFC7View, CView)

BEGIN_MESSAGE_MAP(CMFC7View, CView)
	ON_COMMAND(ID_POPOUT, &CMFC7View::OnPopout)
END_MESSAGE_MAP()

// CMFC7View ����/����

CMFC7View::CMFC7View()
{
	// TODO: �ڴ˴���ӹ������
	a = 0;
}

CMFC7View::~CMFC7View()
{
}

BOOL CMFC7View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC7View ����

void CMFC7View::OnDraw(CDC* pDC)
{
	CMFC7Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CString s=_T("�����˳��Ի���");
	if (a) {
		pDC->TextOutW(100, 100, s);
	}
}


// CMFC7View ���

#ifdef _DEBUG
void CMFC7View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC7View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC7Doc* CMFC7View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC7Doc)));
	return (CMFC7Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC7View ��Ϣ�������


void CMFC7View::OnPopout()
{
	// TODO: �ڴ���������������
	MyDlg dlg;
	int t = dlg.DoModal();
	a = 1;
	Invalidate();

}
