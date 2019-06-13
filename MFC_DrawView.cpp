
// MFC_DrawView.cpp: CMFCDrawView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC_Draw.h"
#endif

#include "MFC_DrawDoc.h"
#include "MFC_DrawView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include <iostream>
#include "MainFrm.h"

#include <afx.h>


// CMFCDrawView

IMPLEMENT_DYNCREATE(CMFCDrawView, CView)

BEGIN_MESSAGE_MAP(CMFCDrawView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_32771, &CMFCDrawView::OnDrline)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()

	ON_COMMAND(ID_32774, &CMFCDrawView::OnDrcircle)
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_32772, &CMFCDrawView::OnDrrect)
	ON_COMMAND(ID_32773, &CMFCDrawView::OnDrellipse)
	ON_COMMAND(ID_32775, &CMFCDrawView::zhexian)
	ON_WM_RBUTTONDOWN()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_BUTTONLine, &CMFCDrawView::OnButtonline)
	ON_COMMAND(ID_BUTTONpolyline, &CMFCDrawView::OnButtonpolyline)
	ON_COMMAND(ID_BUTTONrectangle, &CMFCDrawView::OnButtonrectangle)
	ON_COMMAND(ID_BUTTONcircular, &CMFCDrawView::OnButtoncircular)
	ON_COMMAND(ID_BUTTONEllipse, &CMFCDrawView::OnButtonellipse)
END_MESSAGE_MAP()

// CMFCDrawView 构造/析构

CMFCDrawView::CMFCDrawView() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCDrawView::~CMFCDrawView()
{
}

BOOL CMFCDrawView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCDrawView 绘图

void CMFCDrawView::OnDraw(CDC* /*pDC*/)
{
	CMFCDrawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCDrawView 打印

BOOL CMFCDrawView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCDrawView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCDrawView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFCDrawView 诊断

#ifdef _DEBUG
void CMFCDrawView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCDrawView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCDrawDoc* CMFCDrawView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCDrawDoc)));
	return (CMFCDrawDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCDrawView 消息处理程序


void CMFCDrawView::OnDrline()
{
	// TODO: 在此添加命令处理程序代码
	flag = 1;
}


// 绘制圆
void CMFCDrawView::OnDrcircle()
{
	// TODO: 在此添加命令处理程序代码
	flag = 2;
}


// 绘制矩形
void CMFCDrawView::OnDrrect()
{
	// TODO: 在此添加命令处理程序代码
	flag = 3;

}


// 绘制椭圆
void CMFCDrawView::OnDrellipse()
{
	// TODO: 在此添加命令处理程序代码
	flag = 4;
}



void CMFCDrawView::zhexian()
{
	// TODO: 在此添加命令处理程序代码
	flag = 5;
}


void CMFCDrawView::OnLButtonDown(UINT nFlags, CPoint point)
{

	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (0 != flag)
	{
		// 绘制直线
		if (1 == flag)
		{
			/*if (false == nClick)
			{
				m_Start = m_End = point;
				DrawLine(false, m_Start, m_End);
				nClick = true;
			}
			else
			{
				DrawLine(false, m_Start, m_End);
				nClick = false;
			}*/

			m_IsDraw = true; //开始绘制直线
			m_StartPoint = m_EndPoint = point; //开始画线时起始点与终止点重合
			CView::OnLButtonDown(nFlags, point);

		}
		// 绘制圆
		if (2 == flag)
		{
			if (false == nClick)
			{
				m_Start = m_End = point;
				DrawCircle(false, m_Start, m_End);
				nClick = true;
			}
			else
			{
				DrawCircle(false, m_Start, m_End);
				nClick = false;
			}
		}
		// 绘制矩形
		if (3 == flag)
		{
			if (false == nClick)
			{
				m_Start = m_End = point;
				DrawRect(false, m_Start, m_End);
				nClick = true;
			}
			else
			{
				DrawRect(false, m_Start, m_End);
				nClick = false;
			}
		}


		// 绘制椭圆
		if (4 == flag)
		{
			if (false == nClick)
			{
				m_Start = m_End = point;
				DrawEllipse(false, m_Start, m_End);
				nClick = true;
			}
			else
			{
				DrawEllipse(false, m_Start, m_End);
				nClick = false;
			}
		}

		if (5 == flag)
		{
			z_IsDraw = true; //开始绘制直线
			m_start = m_end = point; //开始画线时起始点与终止点重合
			CView::OnLButtonDown(nFlags, point);
		}
	}
	CView::OnLButtonDown(nFlags, point);
}

void CMFCDrawView::OnLButtonUp(UINT nFlags, CPoint point)
{
	if (5 == flag)
	{
		//z_IsDraw = true; //开始绘制直线
		m_start = m_end = point; //开始画线时起始点与终止点重合
		CView::OnLButtonDown(nFlags, point);
	}

	nClick = false;
	m_IsDraw = false;
	CView::OnLButtonUp(nFlags, point);
}



void CMFCDrawView::OnRButtonDown(UINT nFlags, CPoint point)
{
	z_IsDraw = false;
	CView::OnRButtonDown(nFlags, point);
}


void CMFCDrawView::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//z_IsDraw = true;
	CView::OnRButtonUp(nFlags, point);
}


void CMFCDrawView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (0 != flag)
	{
		// 直线
		if (1 == flag)
		{
			/*if (nClick)
			{
				DrawLine(true, m_Start, m_End);
				DrawLine(true, m_Start, point);
				m_End = point;
			}*/
			CClientDC dc(this);  //构造一个客户设备环境dc
			if (m_IsDraw) {
				dc.MoveTo(m_StartPoint); //移动到起始点
				dc.SetROP2(R2_NOTXORPEN);//设置绘图模式为R2_NOTXORPEN
				dc.LineTo(m_EndPoint); //从点m_StartPoint画线到点m_EndPoint,即删除原旧线
				dc.MoveTo(m_StartPoint); //移动到起始点		
				dc.LineTo(point);	//从点   m_StartPoint画线到当前的鼠标位置point
				m_EndPoint = point; //改变终止点为当前的鼠标位置point
			}

		}
		//圆
		if (2 == flag)
		{
			if (nClick)
			{
				DrawCircle(true, m_Start, m_End);
				DrawCircle(true, m_Start, point);
				m_End = point;
			}
		}
		//矩形
		if (3 == flag)
		{
			if (nClick)
			{
				DrawRect(true, m_Start, m_End);
				DrawRect(true, m_Start, point);
				m_End = point;
			}
		}
		//椭圆
		if (4 == flag)
		{
			if (nClick)
			{
				DrawEllipse(true, m_Start, m_End);
				DrawEllipse(true, m_Start, point);
				m_End = point;
			}
		}
		//画折线
		if (5 == flag)
		{


			CClientDC dc(this);  //构造一个客户设备环境dc
			if (z_IsDraw) 
			{
				dc.MoveTo(m_start); //移动到起始点
				
				
				dc.SetROP2(R2_NOTXORPEN);//设置绘图模式为R2_NOTXORPEN
				dc.LineTo(m_end); //从点m_StartPoint画线到点m_EndPoint,即删除原旧线
				dc.MoveTo(m_start); //移动到起始点		
				
				
				dc.LineTo(point);	//从点   m_StartPoint画线到当前的鼠标位置point
				m_end = point; //改变终止点为当前的鼠标位置point
			}
			
		}

	}


	CString sMousePos;
	sMousePos.Format(_T("x=%d,y=%d"), point.x, point.y);
	AfxGetMainWnd()->GetDescendantWindow(AFX_IDW_STATUS_BAR)->SetWindowText(sMousePos);

	CView::OnMouseMove(nFlags, point);
}


// 绘制直线
void CMFCDrawView::DrawLine(bool isRubber, CPoint ptStart, CPoint ptEnd)
{
	/*CDC* pDC = GetDC();
	if (isRubber)
	{
		pDC->SetROP2(R2_NOT);
	}
	CPen pen(PS_SOLID, 1, RGB(255, 0, 0));
	CPen* pOldPen = pDC->SelectObject(&pen);
	pDC->MoveTo(ptStart.x, ptStart.y);
	pDC->LineTo(ptEnd.x, ptEnd.y);
	pDC->SelectObject(pOldPen);
	ReleaseDC(pDC);*/


	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CClientDC dc(this);  //构造一个客户设备环境dc
	if (flag) {
		dc.MoveTo(m_Start); //移动到起始点
		dc.SetROP2(R2_NOTXORPEN);//设置绘图模式为R2_NOTXORPEN
		dc.LineTo(m_End); //从点m_StartPoint画线到点m_EndPoint,即删除原旧线
		dc.MoveTo(m_Start); //移动到起始点		
		dc.LineTo(m_End);	//从点   m_StartPoint画线到当前的鼠标位置point
		//m_End = point; //改变终止点为当前的鼠标位置point
	}

}


// 绘制圆
void CMFCDrawView::DrawCircle(bool isRubber, CPoint ptCenter, CPoint ptOnCircle)
{
	CDC* pDC = GetDC();
	// 半径计算
	float r1 = (float)((ptCenter.x - ptOnCircle.x) * (ptCenter.x - ptOnCircle.x) + (ptCenter.y - ptOnCircle.y) * (ptCenter.y - ptOnCircle.y));
	LONG r = sqrt(r1);
	// 设置透明画刷
	CBrush* pBrush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
	CBrush* pOldBrush = pDC->SelectObject(pBrush);
	if (isRubber)
	{
		pDC->SetROP2(R2_NOT);
		//pDC->MoveTo(ptCenter.x, ptCenter.y);
		//pDC->LineTo(ptOnCircle.x, ptOnCircle.y);
		// 半径
		pDC->Ellipse(ptCenter.x - r, ptCenter.y - r, ptCenter.x + r, ptCenter.y + r);
	}
	else
	{
		CPen pen(PS_SOLID, 1, RGB(255, 0, 0));
		CPen* pOldPen = pDC->SelectObject(&pen);
		pDC->Ellipse(ptCenter.x - r, ptCenter.y - r, ptCenter.x + r, ptCenter.y + r);
		pDC->SelectObject(pOldPen);
		pDC->SetROP2(R2_NOT);
		pDC->MoveTo(ptCenter.x, ptCenter.y);
		pDC->LineTo(ptOnCircle.x, ptOnCircle.y);
	}
	ReleaseDC(pDC);
}


// 绘制矩形，ptUL: 左上，ptLR: 右下
void CMFCDrawView::DrawRect(bool isRubber, CPoint ptUL, CPoint ptLR)
{
	CDC* pDC = GetDC();
	// 设置透明画刷
	CBrush* pBrush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
	CBrush* pOldBrush = pDC->SelectObject(pBrush);
	if (isRubber)
	{
		pDC->SetROP2(R2_NOT);
		pDC->Rectangle(ptUL.x, ptUL.y, ptLR.x, ptLR.y);
	}
	else
	{
		CPen pen(PS_SOLID, 1, RGB(255, 0, 0));
		CPen* pOldPen = pDC->SelectObject(&pen);
		pDC->Rectangle(ptUL.x, ptUL.y, ptLR.x, ptLR.y);
	}

	ReleaseDC(pDC);
}




void CMFCDrawView::DrawEllipse(bool isRubber, CPoint ptUL, CPoint ptLR)
{
	CDC* pDC = GetDC();
	// 设置透明画刷
	CBrush* pBrush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
	//CBrush * pBrush = CBrush::FromHandle(CreateSolidBrush(RGB(0, 255, 0)));//填充版

	CBrush* pOldBrush = pDC->SelectObject(pBrush);

	//pDC->SelectObject(pOldBrush);

	if (isRubber)
	{
		pDC->SetROP2(R2_NOT);
		pDC->Ellipse(ptUL.x, ptUL.y, ptLR.x, ptLR.y);
	}
	else
	{
		CPen pen(PS_SOLID, 1, RGB(0, 0, 0));
		CPen* pOldPen = pDC->SelectObject(&pen);
		pDC->Ellipse(ptUL.x, ptUL.y, ptLR.x, ptLR.y);
	}

	ReleaseDC(pDC);
}


//1直线
//2圆
//3矩形
//4椭圆
//5折线


void CMFCDrawView::OnButtonline()
{
	flag = 1;
	// TODO: 在此添加命令处理程序代码
}


void CMFCDrawView::OnButtonpolyline()
{
	flag = 5;
	// TODO: 在此添加命令处理程序代码
}


void CMFCDrawView::OnButtonrectangle()
{
	flag = 3;
	// TODO: 在此添加命令处理程序代码
}


void CMFCDrawView::OnButtoncircular()
{
	flag = 2;
	// TODO: 在此添加命令处理程序代码
}


void CMFCDrawView::OnButtonellipse()
{
	flag = 4;
	nClick = false;
	// TODO: 在此添加命令处理程序代码
}
