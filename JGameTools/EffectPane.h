#pragma once
#include "EffectForm.h"

// EffectPane

class EffectPane : public CDockablePane
{
	DECLARE_DYNAMIC(EffectPane)

public:
	EffectPane();
	virtual ~EffectPane();
	EffectForm* m_wndForm;
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg int OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};


