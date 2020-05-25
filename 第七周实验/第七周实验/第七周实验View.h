
// 第七周实验View.h : C第七周实验View 类的接口
//

#pragma once


class C第七周实验View : public CView
{
protected: // 仅从序列化创建
	C第七周实验View();
	DECLARE_DYNCREATE(C第七周实验View)

// 特性
public:
	C第七周实验Doc* GetDocument() const;
	CRect re;				//第一题的矩形
	int x, y;				//鼠标坐标
	bool  mousechoose;		//鼠标拿起矩形
	bool  mousewaive;		//鼠标放弃矩形
	bool  timeswitch;		//定时器开关
	int  circle_x, circle_y;		//圆的坐标
	bool circle_dirction;			//小球的运动方向，true为右，false为左


// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~C第七周实验View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnMButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMButtonUp(UINT nFlags, CPoint point);
	afx_msg void On32771();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void On32772();
};

#ifndef _DEBUG  // 第七周实验View.cpp 中的调试版本
inline C第七周实验Doc* C第七周实验View::GetDocument() const
   { return reinterpret_cast<C第七周实验Doc*>(m_pDocument); }
#endif

