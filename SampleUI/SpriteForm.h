#pragma once

#include "SampleUI.h"
// SpriteForm 대화 상자

class SpriteForm : public CFormView
{
	DECLARE_DYNAMIC(SpriteForm)
public:
	static SpriteForm* CreateOne(CWnd* pParent);
public:
	SpriteForm(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~SpriteForm();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SpriteForm};
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_CtrlTextureList;
	afx_msg void OnLbnSelchangeTextlist();
	afx_msg void OnEnChangeMfceditbrowse1();
	afx_msg void OnLbnDblclkTextlist();
	afx_msg void OnBnClickedCreatesprite();
	CString m_NodeName;
	CString m_strParentName;
	CString m_ScaleX;
	CString m_ScaleY;
	CString m_ScaleZ;
	CString m_RotateAngle;
	CString m_TransX;
	CString m_TransY;
	CString m_TransZ;
	vector<int> m_TexID;
	vector<CString> m_SpriteList;
	afx_msg void OnEnChangeMfceditbrowse2();
	CString m_SpriteSec;
};
