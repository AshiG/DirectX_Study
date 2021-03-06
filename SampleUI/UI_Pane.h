#pragma once
#include "UI_Form.h"

// UI_Pane

class UI_Pane : public CDockablePane
{
	DECLARE_DYNAMIC(UI_Pane)
public:
	UI_Form * m_pUIForm;
public:
	UI_Pane();
	virtual ~UI_Pane();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg int OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};


