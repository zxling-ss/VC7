
// MFC7View.h : CMFC7View ��Ľӿ�
//

#pragma once


class CMFC7View : public CView
{
protected: // �������л�����
	CMFC7View();
	DECLARE_DYNCREATE(CMFC7View)

// ����
public:
	CMFC7Doc* GetDocument() const;

// ����
public:
	int a;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC7View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPopout();
};

#ifndef _DEBUG  // MFC7View.cpp �еĵ��԰汾
inline CMFC7Doc* CMFC7View::GetDocument() const
   { return reinterpret_cast<CMFC7Doc*>(m_pDocument); }
#endif

