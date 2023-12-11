
// FidleView.cpp: CFidleView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Fidle.h"
#endif

#include "FidleDoc.h"
#include "FidleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFidleView

IMPLEMENT_DYNCREATE(CFidleView, CView)

BEGIN_MESSAGE_MAP(CFidleView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CFidleView 생성/소멸

CFidleView::CFidleView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CFidleView::~CFidleView()
{
}

BOOL CFidleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CFidleView 그리기

void CFidleView::OnDraw(CDC* /*pDC*/)
{
	CFidleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CFidleView 인쇄

BOOL CFidleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CFidleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CFidleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CFidleView 진단

#ifdef _DEBUG
void CFidleView::AssertValid() const
{
	CView::AssertValid();
}

void CFidleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFidleDoc* CFidleView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFidleDoc)));
	return (CFidleDoc*)m_pDocument;
}
#endif //_DEBUG


// CFidleView 메시지 처리기



void CFidleView::OnMyDraw()
{
	// TODO: 여기에 구현 코드 추가.
	CClientDC dc(this);
	RECT r1; // 창의 크기를 저장할 구조체
	GetClientRect(&r1); // 창의 크기를 읽어 옴
	int x = rand() % r1.right;
	int y = rand() % r1.bottom;
	int w = rand() % 48;
	int h = rand() % 48;
	//dc.Rectangle(x, y, x+w, y+h);
	BYTE r = rand() % 255;
	BYTE g = rand() % 255;
	BYTE b = rand() % 255;
	COLORREF col;
	col = RGB(r, g, b);
	dc.FillSolidRect(x, y, w, h, col);
}
