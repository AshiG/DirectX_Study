#pragma once


// SpritePane
#include "SpriteForm.h"
class SpritePane : public CDockablePane
{
	DECLARE_DYNAMIC(SpritePane)
	SpriteForm* m_pSpriteForm;
public:
	SpritePane();
	virtual ~SpritePane();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg int OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message);
};


