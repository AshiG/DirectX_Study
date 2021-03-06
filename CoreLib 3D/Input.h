#pragma once
#include "ISingleton.h"
#include "IBasis.h"
#include "Window.h"

enum class EKeyState : char {
	FREE = 0,
	DOWN,
	UP,
	HOLD
};

enum EMouseButton : char {
	Left = 0, Right= 1, Middle = 2,
};

class Input : public ISingleton<Input>, public IBasis
{
public:
	static bool	 isDebug;
	//static bool	 isChatting;
private:
	static short m_WheelScroll;
	static short m_tempWheelScroll;
	static POINT m_Cursor;
	static POINT m_prevCursor;
	static EKeyState m_KeyState[256];
	static EKeyState m_MouseState[3];
	static EKeyState m_MousePrevState[3];
private:
	EKeyState	 KeyCheck(const WORD& key);			// 키 검사(1회만)
public:
	static POINT	 GetCursor();
	static EKeyState GetMouseState(const EMouseButton& mouseButton);
	static short	 GetWheelScroll();
	static EKeyState GetKeyState(const WORD& keyValue);
	static D3DXVECTOR2 GetMouseMovePos();

	void		 MsgEvent(const MSG& message);			// 마우스 클릭 처리
	void		 MouseUpdate();							// 마우스 상태 갱신
public:
	virtual bool Init()		noexcept override;
	virtual bool Frame()	noexcept override;
	virtual bool Render()	noexcept override;
	virtual bool Release()	noexcept override;
private:
	Input() = default;
public:
	friend class ISingleton<Input>;
	friend class Timer;
	virtual ~Input() = default;
};

//#define I_Input  Input::GetInstance()