
// MFC_DrawView.h: CMFCDrawView 类的接口
//

#pragma once


class CMFCDrawView : public CView
{
protected: // 仅从序列化创建
	CMFCDrawView() noexcept;
	DECLARE_DYNCREATE(CMFCDrawView)

// 特性
public:
	CMFCDrawDoc* GetDocument() const;
	
	bool nClick;
	// 绘图类型
	int flag;
	CPoint m_Start;
	CPoint m_End;


	bool m_IsDraw = false;
	CPoint m_StartPoint;
	CPoint m_EndPoint;

	bool z_IsDraw = false;
	CPoint m_start;
	CPoint m_end;
	
	
	
	CPoint lclick;
	CPoint rclick;

	int m_iPolyDotNumbers;//多边形顶点个数(边的个数)
	CPoint m_ptPolyDotArrays[5];//存储多边形的顶点




	void DrawLine(bool isRubber, CPoint ptStart, CPoint ptEnd );
	void DrawCircle(bool isRubber, CPoint ptCenter, CPoint ptOnCircle);
	void DrawRect(bool isRubber, CPoint ptUL, CPoint ptLR);
	void DrawEllipse(bool isRubber, CPoint ptUL, CPoint ptLR);


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
	virtual ~CMFCDrawView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:

	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnDrline();
	afx_msg void OnDrcircle();
	afx_msg void OnDrrect();
	afx_msg void OnDrellipse();
	afx_msg void zhexian();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnButtonline();
	afx_msg void OnButtonpolyline();
	afx_msg void OnButtonrectangle();
	afx_msg void OnButtoncircular();
	afx_msg void OnButtonellipse();
};

#ifndef _DEBUG  // MFC_DrawView.cpp 中的调试版本
inline CMFCDrawDoc* CMFCDrawView::GetDocument() const
   { return reinterpret_cast<CMFCDrawDoc*>(m_pDocument); }
#endif

