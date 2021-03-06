
// JGameToolsView.cpp: CJGameToolsView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "JGameTools.h"
#endif

#include "JGameToolsDoc.h"
#include "JGameToolsView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CJGameToolsView

IMPLEMENT_DYNCREATE(CJGameToolsView, CView)

BEGIN_MESSAGE_MAP(CJGameToolsView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CJGameToolsView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_SIZE()
END_MESSAGE_MAP()

// CJGameToolsView 생성/소멸

CJGameToolsView::CJGameToolsView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CJGameToolsView::~CJGameToolsView()
{
}

BOOL CJGameToolsView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CJGameToolsView 그리기

void CJGameToolsView::OnDraw(CDC* /*pDC*/)
{
	CJGameToolsDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CJGameToolsView 인쇄


void CJGameToolsView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CJGameToolsView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CJGameToolsView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CJGameToolsView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CJGameToolsView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CJGameToolsView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CJGameToolsView 진단

#ifdef _DEBUG
void CJGameToolsView::AssertValid() const
{
	CView::AssertValid();
}

void CJGameToolsView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CJGameToolsDoc* CJGameToolsView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CJGameToolsDoc)));
	return (CJGameToolsDoc*)m_pDocument;
}
#endif //_DEBUG


// CJGameToolsView 메시지 처리기


void CJGameToolsView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);
	CJGameToolsApp* pApp = (CJGameToolsApp*)AfxGetApp();
	pApp->sample.ResizeClient(cx, cy);
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}
