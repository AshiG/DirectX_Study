#pragma once


// EffectForm 대화 상자

class EffectForm : public CFormView
{
	DECLARE_DYNAMIC(EffectForm)

public:
	EffectForm();   // 표준 생성자입니다.
	virtual ~EffectForm();
	static EffectForm* CreateOne(CWnd* pParent);
// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
