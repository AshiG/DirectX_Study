// MapForm.cpp: 구현 파일
//

#include "stdafx.h"
#include "JGameTools.h"
#include "MapForm.h"
#include "afxdialogex.h"


// MapForm 대화 상자

IMPLEMENT_DYNAMIC(MapForm, CFormView)
MapForm* MapForm::CreateOne(CWnd* pParent)
{
	MapForm* pForm = new MapForm;
	pForm->Create(NULL, NULL, WS_CHILD | WS_VISIBLE, CRect(0, 0, 500, 500), pParent, 0, NULL);
	return pForm;
}
MapForm::MapForm()
	: CFormView(IDD_DIALOG1)
	, m_strTexName(_T(""))
	, m_LeftString(_T(""))
{

}

MapForm::~MapForm()
{
}

void MapForm::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, m_strTexName);
	DDX_Control(pDX, IDC_RT_LEFT, m_EditLeft);
	DDX_Text(pDX, IDC_RT_LEFT, m_LeftString);
	DDX_Control(pDX, IDC_LIST1, m_CtrlList);
}


BEGIN_MESSAGE_MAP(MapForm, CFormView)
	ON_BN_CLICKED(IDC_ADDPLANE, &MapForm::OnBnClickedAddplane)
	ON_BN_CLICKED(IDC_BUTTON1, &MapForm::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT2, &MapForm::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_RT_LEFT, &MapForm::OnCurrentPlaneRectLeft)
	ON_EN_CHANGE(IDC_RT_RIGHT, &MapForm::OnCurrentPlaneRectRight)
	ON_EN_CHANGE(IDC_RT_TOP, &MapForm::OnCurrentPlaneRectTop)
	ON_EN_CHANGE(IDC_RT_BOTTOM, &MapForm::OnCurrentPlaneRectBottom)
	ON_EN_UPDATE(IDC_RT_LEFT, &MapForm::OnEnUpdateRtLeft)
	ON_EN_CHANGE(IDC_MFCEDITBROWSE1, &MapForm::OnEnChangeMfceditbrowse1)
	ON_LBN_SELCHANGE(IDC_LIST1, &MapForm::OnLbnSelchangeList1)
END_MESSAGE_MAP()


// MapForm 메시지 처리기


void MapForm::OnBnClickedAddplane()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CJGameToolsApp* pApp = (CJGameToolsApp*)AfxGetApp();
	pApp->sample.CreatePlane();
}


void MapForm::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CJGameToolsApp* pApp = (CJGameToolsApp*)AfxGetApp();
	m_CtrlList.AddString(L"abcde");
	m_CtrlList.AddString(L"123456");
	m_CtrlList.AddString(L"zxcvbhn");
	if (!pApp->sample.LoadTexture(m_strTexName))
	{
		AfxMessageBox(L"파일이 없습니다.");
	}
}


void MapForm::OnEnChangeEdit2()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CFormView::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.
	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//GetDlgItemText(IDC_EDIT2, m_strTexName);
}


void MapForm::OnCurrentPlaneRectLeft()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CFormView::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//SetDlgItemText(IDC_RT_LEFT, m_strLeft);
	//SetWindowText(m_strLeft);
}


void MapForm::OnCurrentPlaneRectRight()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CFormView::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void MapForm::OnCurrentPlaneRectTop()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CFormView::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void MapForm::OnCurrentPlaneRectBottom()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CFormView::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void MapForm::OnEnUpdateRtLeft()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CFormView::OnInitDialog() 함수를 재지정 
	//하여, IParam 마스크에 OR 연산하여 설정된 ENM_SCROLL 플래그를 지정하여 컨트롤에 EM_SETEVENTMASK 메시지를 보내지 않으면
	// 편집 컨트롤이 바뀐 텍스트를 표시하려고 함을 나타냅니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void MapForm::OnEnChangeMfceditbrowse1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CFormView::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CJGameToolsApp* pApp = (CJGameToolsApp*)AfxGetApp();
	GetDlgItemText(IDC_MFCEDITBROWSE1, m_strTexName);
	m_strTemp = m_strTexName;
	SetDlgItemText(IDC_EDIT2, pApp->sample.NameDivide(m_strTemp));


}
void MapForm::OnLbnSelchangeList1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int iIndex = m_CtrlList.GetCurSel();
	CString af;
	m_CtrlList.GetText(iIndex, af);
}
