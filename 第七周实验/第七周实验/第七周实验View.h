
// ������ʵ��View.h : C������ʵ��View ��Ľӿ�
//

#pragma once


class C������ʵ��View : public CView
{
protected: // �������л�����
	C������ʵ��View();
	DECLARE_DYNCREATE(C������ʵ��View)

// ����
public:
	C������ʵ��Doc* GetDocument() const;
	CRect re;				//��һ��ľ���
	int x, y;				//�������
	bool  mousechoose;		//����������
	bool  mousewaive;		//����������
	bool  timeswitch;		//��ʱ������
	int  circle_x, circle_y;		//Բ������
	bool circle_dirction;			//С����˶�����trueΪ�ң�falseΪ��


// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~C������ʵ��View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
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

#ifndef _DEBUG  // ������ʵ��View.cpp �еĵ��԰汾
inline C������ʵ��Doc* C������ʵ��View::GetDocument() const
   { return reinterpret_cast<C������ʵ��Doc*>(m_pDocument); }
#endif

