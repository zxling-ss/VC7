
// ������ʵ��View.cpp : C������ʵ��View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "������ʵ��.h"
#endif

#include "������ʵ��Doc.h"
#include "������ʵ��View.h"
#include "ADDdition.h"
#include "Question4.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C������ʵ��View

IMPLEMENT_DYNCREATE(C������ʵ��View, CView)

BEGIN_MESSAGE_MAP(C������ʵ��View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_MOUSEMOVE()
	ON_WM_MBUTTONDOWN()
	ON_WM_MBUTTONUP()
	ON_COMMAND(ID_32771, &C������ʵ��View::On32771)
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_32772, &C������ʵ��View::On32772)
END_MESSAGE_MAP()

// C������ʵ��View ����/����

C������ʵ��View::C������ʵ��View()
{
	// TODO: �ڴ˴���ӹ������
	re.top = 100;
	re.left = 100;
	re.right = 300;
	re.bottom = 300;
	mousechoose = false;
	mousewaive = false;
	timeswitch = false;
	circle_x = 400;
	circle_y = 400;
	circle_dirction = true;
}

C������ʵ��View::~C������ʵ��View()
{
}

BOOL C������ʵ��View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C������ʵ��View ����

void C������ʵ��View::OnDraw(CDC* pDC)
{
	C������ʵ��Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	//1.    ���������һ�������Ƶ�ĳһλ�ã�����----��ס����м�����ѡ��
	if (mousechoose) {
		//���α�ѡ��-�������ƶ�
		pDC->Rectangle(x - 100, y - 100, x + 100, y + 100);
	}
	else if (mousewaive) {
		//���δ�ѡ�б�������
		pDC->Rectangle(x - 100, y - 100, x + 100, y + 100);
	}
	else  {
		//����û�б�ѡ��
		pDC->Rectangle(re);
	}
	

	//��ʱ����̣�һ��СԲ����ʼʱ����ʾ�ڿͻ�������м�λ�ã�������������СԲ��ʼ�����ƶ��������ͻ����ұ��������ƶ���˫������������СԲ��ͣ��������������
	if (timeswitch) {
		//���ö�ʱ��
		SetTimer(0, 1, NULL);
		timeswitch = false;
	}
	
	pDC->Ellipse(circle_x-10, circle_y-10,circle_x+10, circle_y+10);
	

}


// C������ʵ��View ��ӡ

BOOL C������ʵ��View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C������ʵ��View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C������ʵ��View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C������ʵ��View ���

#ifdef _DEBUG
void C������ʵ��View::AssertValid() const
{
	CView::AssertValid();
}

void C������ʵ��View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C������ʵ��Doc* C������ʵ��View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C������ʵ��Doc)));
	return (C������ʵ��Doc*)m_pDocument;
}
#endif //_DEBUG


// C������ʵ��View ��Ϣ�������

//1.    ���������һ�������Ƶ�ĳһλ�ã�����
void C������ʵ��View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//��������ѡ�еľ��ε�ʱ��ͼ���ٸ���
	if (!mousewaive)
	{
		x = point.x;
		y = point.y;
		Invalidate();
	}
	
	//��������ѡ�еľ��ε�ʱ��ͼ���ٸ���
	/*if(!mousewaive)
		Invalidate();*/

	CView::OnMouseMove(nFlags, point);
}

//���ѡ�о���
void C������ʵ��View::OnMButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	mousechoose = true;
	mousewaive = false;

	CView::OnMButtonDown(nFlags, point);
}


void C������ʵ��View::OnMButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	x = point.x;
	y = point.y;
	
	mousechoose = false;
	mousewaive = true;

	CView::OnMButtonUp(nFlags, point);
}


void C������ʵ��View::On32771()
{
	// TODO: �ڴ���������������
	ADDdition ADD;
	int r = ADD.DoModal();
	if (r == IDOK) {

	}
}


void C������ʵ��View::OnTimer(UINT_PTR nIDEvent)
{

	/*��ʱ����̣�һ��СԲ����ʼʱ����ʾ�ڿͻ�������м�λ�ã�������������СԲ��ʼ�����ƶ��������ͻ����ұ��������ƶ���˫������������СԲ��ͣ��������������*/
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	CRect re;

	//��ȡ���ͻ����Ĳ���
	GetClientRect(&re);

	if (circle_dirction) {
		//��СԲ�������˶�
		circle_x += 1;

		
		//�ж�С���Ƿ������߽�
		if (circle_x + 10 >= re.right) {
			circle_x = re.right - 10;
			//��С�����������˶�
			circle_dirction = false;
		}
	}
	else {
		//��С�������˶�
		circle_x -= 1;

		//�ж�С���Ƿ���ײ���߽�
		if (circle_x - 10 <= re.left) {
			circle_x = re.left - 10;
			//��С�����������˶�
			
			circle_dirction = true;
		}
	}
	




	Invalidate();
	CView::OnTimer(nIDEvent);
}


void C������ʵ��View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	timeswitch = true;

	CView::OnLButtonDown(nFlags, point);
}


void C������ʵ��View::On32772()
{
	// TODO: �ڴ���������������
	Question4 q4;
	int r = q4.DoModal();
	if (r == IDOK) {

	}
}
