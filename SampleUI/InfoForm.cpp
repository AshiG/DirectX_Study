// InfoForm.cpp: 구현 파일
//
#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include "SampleUI.h"
#include "InfoForm.h"
#include "afxdialogex.h"


// InfoForm 대화 상자

IMPLEMENT_DYNAMIC(InfoForm, CFormView)
InfoForm* InfoForm::CreateOne(CWnd* pParent)
{
	InfoForm* pForm = new InfoForm();
	pForm->Create(NULL, NULL, WS_CHILD | WS_VISIBLE, CRect(0, 0, 500, 500), pParent, 0, NULL);
	return pForm;
}
InfoForm::InfoForm(CWnd* pParent /*=nullptr*/)
	: CFormView(IDD_Info)
	, m_NodeName(_T(""))
{

}

InfoForm::~InfoForm()
{
}

void InfoForm::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT9, m_NodeName);
	DDX_Control(pDX, IDD_TextList, m_CtrlTextureList);
}


BEGIN_MESSAGE_MAP(InfoForm, CFormView)
	ON_BN_CLICKED(IDC_GetInfo, &InfoForm::OnBnClickedGetinfo)
END_MESSAGE_MAP()


// InfoForm 메시지 처리기


void InfoForm::OnBnClickedGetinfo()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CSampleUIApp* pApp = (CSampleUIApp*)AfxGetApp();
	if (pApp->m_Sample.m_pCurrentPlane != NULL)
	{
		m_CtrlTextureList.ResetContent();

		CString NodeName = (CString)pApp->m_Sample.m_pCurrentPlane->m_szNodeName.data();
		CString ParentName = (CString)pApp->m_Sample.m_pCurrentPlane->m_szParentName.data();
		D3DXMATRIX Scl = pApp->m_Sample.m_pCurrentPlane->m_matScale;
		D3DXMATRIX Rot = pApp->m_Sample.m_pCurrentPlane->m_matRotate;
		D3DXMATRIX Trans = pApp->m_Sample.m_pCurrentPlane->m_matTrans;
		D3DXQUATERNION qAngle;
		TCHAR strSclX[256] = {0,}, strSclY[256] = { 0, }, strSclZ[256] = { 0, }, strAngle[256] = { 0, },
			strTransX[256] = { 0, }, strTransY[256] = { 0, }, strTransZ[256] = { 0, };
		float SclX = Scl._11, SclY = Scl._22, SclZ = Scl._33;
		float TransX = Trans._41, TransY = Trans._42, TransZ = Trans._43;
		D3DXQuaternionRotationMatrix(&qAngle, &Rot);
		float fAngle = qAngle.w;
		_stprintf_s(strSclX, L"%.6f", SclX);
		_stprintf_s(strSclY, L"%.6f", SclY);
		_stprintf_s(strSclZ, L"%.6f", SclZ);
		_stprintf_s(strAngle, L"%.6f", fAngle);
		_stprintf_s(strTransX, L"%.6f", TransX);
		_stprintf_s(strTransY, L"%.6f", TransY);
		_stprintf_s(strTransZ, L"%.6f", TransZ);
		SetDlgItemText(IDC_InfoNodeName, NodeName);
		SetDlgItemText(IDC_InfoParentName, ParentName);
		SetDlgItemText(IDC_InfoScaleX, strSclX);
		SetDlgItemText(IDC_InfoScaleY, strSclY);
		SetDlgItemText(IDC_InfoScaleZ, strSclZ);
		SetDlgItemText(IDC_InfoAngle, strAngle);
		SetDlgItemText(IDC_InfoTransX, strTransX);
		SetDlgItemText(IDC_InfoTransY, strTransY);
		SetDlgItemText(IDC_InfoTransZ, strTransZ);
		/* 2D Texture */
		if (pApp->m_Sample.m_pCurrentPlane->m_dxObj.m_pTexture)
		{
			CString strTexture = (CString)pApp->m_Sample.m_pCurrentPlane->m_dxObj.m_pTexture->m_szName.data();
			SetDlgItemText(IDC_InfoTexName, strTexture);
		}
		/* Sprite Texture */
		int iTextureSize = pApp->m_Sample.m_pCurrentPlane->m_pTextureList.size();
		for (int iTex = 0; iTex < iTextureSize; iTex++)
		{
			CString TextureName = (CString)pApp->m_Sample.m_pCurrentPlane->m_pTextureList[iTex]->m_szName.data();
			m_CtrlTextureList.AddString(TextureName);
		}
	}
	else
	{
		AfxMessageBox(L"생성된 UI가 하나도 없습니다.");
	}
}


//void InfoForm::OnActivateFrame(UINT nState, CFrameWnd* pDeactivateFrame)
//{
//	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
//		// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
//	CSampleUIApp* pApp = (CSampleUIApp*)AfxGetApp();
//	if (pApp->m_Sample.m_pCurrentPlane != NULL)
//	{
//		m_CtrlTextureList.ResetContent();
//
//		CString NodeName = (CString)pApp->m_Sample.m_pCurrentPlane->m_szNodeName.data();
//		CString ParentName = (CString)pApp->m_Sample.m_pCurrentPlane->m_szParentName.data();
//		D3DXMATRIX Scl = pApp->m_Sample.m_pCurrentPlane->m_matScale;
//		D3DXMATRIX Rot = pApp->m_Sample.m_pCurrentPlane->m_matRotate;
//		D3DXMATRIX Trans = pApp->m_Sample.m_pCurrentPlane->m_matTrans;
//		D3DXQUATERNION qAngle;
//		TCHAR strSclX[256] = { 0, }, strSclY[256] = { 0, }, strSclZ[256] = { 0, }, strAngle[256] = { 0, },
//			strTransX[256] = { 0, }, strTransY[256] = { 0, }, strTransZ[256] = { 0, };
//		float SclX = Scl._11, SclY = Scl._22, SclZ = Scl._33;
//		float TransX = Trans._41, TransY = Trans._42, TransZ = Trans._43;
//		D3DXQuaternionRotationMatrix(&qAngle, &Rot);
//		float fAngle = qAngle.w;
//		_stprintf_s(strSclX, L"%.6f", SclX);
//		_stprintf_s(strSclY, L"%.6f", SclY);
//		_stprintf_s(strSclZ, L"%.6f", SclZ);
//		_stprintf_s(strAngle, L"%.6f", fAngle);
//		_stprintf_s(strTransX, L"%.6f", TransX);
//		_stprintf_s(strTransY, L"%.6f", TransY);
//		_stprintf_s(strTransZ, L"%.6f", TransZ);
//		SetDlgItemText(IDC_InfoNodeName, NodeName);
//		SetDlgItemText(IDC_InfoParentName, ParentName);
//		SetDlgItemText(IDC_InfoScaleX, strSclX);
//		SetDlgItemText(IDC_InfoScaleY, strSclY);
//		SetDlgItemText(IDC_InfoScaleZ, strSclZ);
//		SetDlgItemText(IDC_InfoAngle, strAngle);
//		SetDlgItemText(IDC_InfoTransX, strTransX);
//		SetDlgItemText(IDC_InfoTransY, strTransY);
//		SetDlgItemText(IDC_InfoTransZ, strTransZ);
//		/* 2D Texture */
//		if (pApp->m_Sample.m_pCurrentPlane->m_dxObj.m_pTexture)
//		{
//			CString strTexture = (CString)pApp->m_Sample.m_pCurrentPlane->m_dxObj.m_pTexture->m_szName.data();
//			SetDlgItemText(IDC_InfoTexName, strTexture);
//		}
//		/* Sprite Texture */
//		int iTextureSize = pApp->m_Sample.m_pCurrentPlane->m_pTextureList.size();
//		for (int iTex = 0; iTex < iTextureSize; iTex++)
//		{
//			CString TextureName = (CString)pApp->m_Sample.m_pCurrentPlane->m_pTextureList[iTex]->m_szName.data();
//			m_CtrlTextureList.AddString(TextureName);
//		}
//	}
//	else
//	{
//		AfxMessageBox(L"생성된 UI가 하나도 없습니다.");
//	}
//	CFormView::OnActivateFrame(nState, pDeactivateFrame);
//}


void InfoForm::OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
		// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CSampleUIApp* pApp = (CSampleUIApp*)AfxGetApp();
	if (pApp->m_Sample.m_pCurrentPlane != NULL)
	{
		m_CtrlTextureList.ResetContent();

		CString NodeName = (CString)pApp->m_Sample.m_pCurrentPlane->m_szNodeName.data();
		CString ParentName = (CString)pApp->m_Sample.m_pCurrentPlane->m_szParentName.data();
		D3DXMATRIX Scl = pApp->m_Sample.m_pCurrentPlane->m_matScale;
		D3DXMATRIX Rot = pApp->m_Sample.m_pCurrentPlane->m_matRotate;
		D3DXMATRIX Trans = pApp->m_Sample.m_pCurrentPlane->m_matTrans;
		D3DXQUATERNION qAngle;
		TCHAR strSclX[256] = { 0, }, strSclY[256] = { 0, }, strSclZ[256] = { 0, }, strAngle[256] = { 0, },
			strTransX[256] = { 0, }, strTransY[256] = { 0, }, strTransZ[256] = { 0, };
		float SclX = Scl._11, SclY = Scl._22, SclZ = Scl._33;
		float TransX = Trans._41, TransY = Trans._42, TransZ = Trans._43;
		D3DXQuaternionRotationMatrix(&qAngle, &Rot);
		float fAngle = qAngle.w;
		_stprintf_s(strSclX, L"%.6f", SclX);
		_stprintf_s(strSclY, L"%.6f", SclY);
		_stprintf_s(strSclZ, L"%.6f", SclZ);
		_stprintf_s(strAngle, L"%.6f", fAngle);
		_stprintf_s(strTransX, L"%.6f", TransX);
		_stprintf_s(strTransY, L"%.6f", TransY);
		_stprintf_s(strTransZ, L"%.6f", TransZ);
		SetDlgItemText(IDC_InfoNodeName, NodeName);
		SetDlgItemText(IDC_InfoParentName, ParentName);
		SetDlgItemText(IDC_InfoScaleX, strSclX);
		SetDlgItemText(IDC_InfoScaleY, strSclY);
		SetDlgItemText(IDC_InfoScaleZ, strSclZ);
		SetDlgItemText(IDC_InfoAngle, strAngle);
		SetDlgItemText(IDC_InfoTransX, strTransX);
		SetDlgItemText(IDC_InfoTransY, strTransY);
		SetDlgItemText(IDC_InfoTransZ, strTransZ);
		/* 2D Texture */
		if (pApp->m_Sample.m_pCurrentPlane->m_dxObj.m_pTexture)
		{
			CString strTexture = (CString)pApp->m_Sample.m_pCurrentPlane->m_dxObj.m_pTexture->m_szName.data();
			SetDlgItemText(IDC_InfoTexName, strTexture);
		}
		/* Sprite Texture */
		int iTextureSize = pApp->m_Sample.m_pCurrentPlane->m_pTextureList.size();
		for (int iTex = 0; iTex < iTextureSize; iTex++)
		{
			CString TextureName = (CString)pApp->m_Sample.m_pCurrentPlane->m_pTextureList[iTex]->m_szName.data();
			m_CtrlTextureList.AddString(TextureName);
		}
	}
	else
	{
		AfxMessageBox(L"생성된 UI가 하나도 없습니다.");
	}
	CFormView::OnActivateView(bActivate, pActivateView, pDeactiveView);
}
