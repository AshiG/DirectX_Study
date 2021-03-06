// UI_Form.cpp: 구현 파일
//

#include "stdafx.h"
#include "SampleUI.h"
#include "UI_Form.h"
#include "afxdialogex.h"


// UI_Form 대화 상자

IMPLEMENT_DYNAMIC(UI_Form, CFormView)
UI_Form* UI_Form::CreateOne(CWnd* pParent)
{
	UI_Form* pForm = new UI_Form;
	pForm->Create(NULL, NULL, WS_CHILD | WS_VISIBLE, CRect(0, 0, 500, 500), pParent, 0, NULL);
	return pForm;
}
UI_Form::UI_Form(CWnd* pParent /*=nullptr*/)
	: CFormView(IDD_UI_Form)
	, m_strParentName(_T(""))
	, m_ScaleX(_T("100"))
	, m_ScaleY(_T("100"))
	, m_ScaleZ(_T("1"))
	, m_RotateAngle(_T("0"))
	, m_TransZ(_T("0"))
	, m_TransX(_T("0"))
	, m_TransY(_T("0"))
	, m_NodeName(_T(""))
	, m_TextureName(_T(""))
{

}

UI_Form::~UI_Form()
{
}

void UI_Form::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT8, m_strParentName);
	DDX_Text(pDX, IDC_EDIT1, m_ScaleX);
	DDX_Text(pDX, IDC_EDIT2, m_ScaleY);
	DDX_Text(pDX, IDC_EDIT3, m_ScaleZ);
	DDX_Text(pDX, IDC_EDIT4, m_RotateAngle);
	DDX_Text(pDX, IDC_EDIT7, m_TransZ);
	DDX_Text(pDX, IDC_EDIT5, m_TransX);
	DDX_Text(pDX, IDC_EDIT6, m_TransY);
	DDX_Text(pDX, IDC_EDIT9, m_NodeName);
	DDX_Text(pDX, IDC_MFCEDITBROWSE1, m_TextureName);
}


BEGIN_MESSAGE_MAP(UI_Form, CFormView)
	ON_BN_CLICKED(IDC_CREATEBTN, &UI_Form::OnBtnClickCreatePlane)
	ON_EN_CHANGE(IDC_MFCEDITBROWSE1, &UI_Form::OnEnChangeMfceditbrowse1)
	ON_EN_CHANGE(IDC_EDIT6, &UI_Form::OnEnChangeEdit6)
END_MESSAGE_MAP()


// UI_Form 메시지 처리기


void UI_Form::OnBtnClickCreatePlane()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	float SclX = 0, SclY = 0, SclZ = 0;
	float fAngle = 0;
	float TransX = 0, TransY = 0, TransZ = 0;
	CString NodeName, ParentName;
	D3DXMATRIX Scl, Rot, Trans;
	D3DXMatrixIdentity(&Scl);
	D3DXMatrixIdentity(&Rot);
	D3DXMatrixIdentity(&Trans);
	GetDlgItemText(IDC_EDIT1, m_ScaleX);
	if (m_ScaleX != L"") 
		SclX = _wtoi(m_ScaleX);
	GetDlgItemText(IDC_EDIT2, m_ScaleY);
	if (m_ScaleY != L"")
		SclY = _wtoi(m_ScaleY);
	GetDlgItemText(IDC_EDIT3, m_ScaleZ);
	if (m_ScaleZ != L"")
		SclZ = _wtoi(m_ScaleZ);
	GetDlgItemText(IDC_EDIT4, m_RotateAngle);
	if (m_RotateAngle != L"")
		fAngle = _wtoi(m_RotateAngle);
	GetDlgItemText(IDC_EDIT5, m_TransX);
	if (m_TransX != L"")
		TransX = _wtoi(m_TransX);
	GetDlgItemText(IDC_EDIT6, m_TransY);
	if (m_TransY != L"")
		TransY = _wtoi(m_TransY);
	GetDlgItemText(IDC_EDIT7, m_TransZ);
	if (m_TransZ != L"")
		TransZ = _wtoi(m_TransZ);
	GetDlgItemText(IDC_EDIT8, m_strParentName);
	if (m_strParentName != L"")
		ParentName = m_strParentName;
	GetDlgItemText(IDC_EDIT9, m_NodeName);
	if (m_NodeName == L"")
	{
		AfxMessageBox(L"Node Name Error!");
	}
	else
	{
		NodeName = m_NodeName;
		D3DXMatrixScaling(&Scl, SclX, SclY, SclZ);
		float fRadian = fAngle * (3.141592f / 180.0f);
		D3DXMatrixRotationZ(&Rot, fRadian);
		Trans._41 = TransX;
		Trans._42 = TransY;
		Trans._43 = TransZ;
		CSampleUIApp* pApp = (CSampleUIApp*)AfxGetApp();
		pApp->m_Sample.CreatePlane(Scl, Rot, Trans, NodeName, ParentName);
		pApp->m_Sample.m_pCurrentPlane->m_strTexName = m_TextureName;
		pApp->m_Sample.LoadSingleTexture(m_TextureName);
		pApp->m_Sample.PathDivide(m_TextureName);
	}
}


void UI_Form::OnEnChangeMfceditbrowse1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CFormView::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CSampleUIApp* pApp = (CSampleUIApp*)AfxGetApp();
	CString TexName;
	GetDlgItemText(IDC_MFCEDITBROWSE1, m_TextureName);
	TexName = m_TextureName;
	SetDlgItemText(IDC_TEXNAME, pApp->m_Sample.PathDivide(TexName));
}


void UI_Form::OnEnChangeEdit6()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CFormView::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
