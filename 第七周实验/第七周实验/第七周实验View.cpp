
// 第七周实验View.cpp : C第七周实验View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "第七周实验.h"
#endif

#include "第七周实验Doc.h"
#include "第七周实验View.h"
#include "ADDdition.h"
#include "Question4.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C第七周实验View

IMPLEMENT_DYNCREATE(C第七周实验View, CView)

BEGIN_MESSAGE_MAP(C第七周实验View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_MOUSEMOVE()
	ON_WM_MBUTTONDOWN()
	ON_WM_MBUTTONUP()
	ON_COMMAND(ID_32771, &C第七周实验View::On32771)
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_32772, &C第七周实验View::On32772)
END_MESSAGE_MAP()

// C第七周实验View 构造/析构

C第七周实验View::C第七周实验View()
{
	// TODO: 在此处添加构造代码
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

C第七周实验View::~C第七周实验View()
{
}

BOOL C第七周实验View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C第七周实验View 绘制

void C第七周实验View::OnDraw(CDC* pDC)
{
	C第七周实验Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	//1.    用鼠标拿起一个矩形移到某一位置，放下----按住鼠标中键可以选中
	if (mousechoose) {
		//矩形被选中-并随其移动
		pDC->Rectangle(x - 100, y - 100, x + 100, y + 100);
	}
	else if (mousewaive) {
		//矩形从选中被放弃，
		pDC->Rectangle(x - 100, y - 100, x + 100, y + 100);
	}
	else  {
		//矩形没有被选中
		pDC->Rectangle(re);
	}
	

	//定时器编程：一个小圆，开始时，显示在客户区左边中间位置，单击鼠标左键，小圆开始向右移动，遇到客户区右边则向左移动。双击鼠标左键可让小圆暂停，单击再启动。
	if (timeswitch) {
		//设置定时器
		SetTimer(0, 1, NULL);
		timeswitch = false;
	}
	
	pDC->Ellipse(circle_x-10, circle_y-10,circle_x+10, circle_y+10);
	

}


// C第七周实验View 打印

BOOL C第七周实验View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C第七周实验View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C第七周实验View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C第七周实验View 诊断

#ifdef _DEBUG
void C第七周实验View::AssertValid() const
{
	CView::AssertValid();
}

void C第七周实验View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C第七周实验Doc* C第七周实验View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C第七周实验Doc)));
	return (C第七周实验Doc*)m_pDocument;
}
#endif //_DEBUG


// C第七周实验View 消息处理程序

//1.    用鼠标拿起一个矩形移到某一位置，放下
void C第七周实验View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//当鼠标放弃选中的矩形的时候图像不再更新
	if (!mousewaive)
	{
		x = point.x;
		y = point.y;
		Invalidate();
	}
	
	//当鼠标放弃选中的矩形的时候图像不再更新
	/*if(!mousewaive)
		Invalidate();*/

	CView::OnMouseMove(nFlags, point);
}

//鼠标选中矩形
void C第七周实验View::OnMButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	mousechoose = true;
	mousewaive = false;

	CView::OnMButtonDown(nFlags, point);
}


void C第七周实验View::OnMButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	x = point.x;
	y = point.y;
	
	mousechoose = false;
	mousewaive = true;

	CView::OnMButtonUp(nFlags, point);
}


void C第七周实验View::On32771()
{
	// TODO: 在此添加命令处理程序代码
	ADDdition ADD;
	int r = ADD.DoModal();
	if (r == IDOK) {

	}
}


void C第七周实验View::OnTimer(UINT_PTR nIDEvent)
{

	/*定时器编程：一个小圆，开始时，显示在客户区左边中间位置，单击鼠标左键，小圆开始向右移动，遇到客户区右边则向左移动。双击鼠标左键可让小圆暂停，单击再启动。*/
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	CRect re;

	//获取到客户区的参数
	GetClientRect(&re);

	if (circle_dirction) {
		//让小圆球往左运动
		circle_x += 1;

		
		//判断小球是否碰到边界
		if (circle_x + 10 >= re.right) {
			circle_x = re.right - 10;
			//让小球往反方向运动
			circle_dirction = false;
		}
	}
	else {
		//让小球往右运动
		circle_x -= 1;

		//判断小球是否碰撞到边界
		if (circle_x - 10 <= re.left) {
			circle_x = re.left - 10;
			//让小球往反方向运动
			
			circle_dirction = true;
		}
	}
	




	Invalidate();
	CView::OnTimer(nIDEvent);
}


void C第七周实验View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	timeswitch = true;

	CView::OnLButtonDown(nFlags, point);
}


void C第七周实验View::On32772()
{
	// TODO: 在此添加命令处理程序代码
	Question4 q4;
	int r = q4.DoModal();
	if (r == IDOK) {

	}
}
