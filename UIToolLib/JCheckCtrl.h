#pragma once
#include "JImageCtrl.h"
namespace UI
{
	enum CheckState
	{
		txENABLE = 0,
		txDISABLE,
	};
	class JCheckCtrl : public JImageCtrl
	{
	public:
		bool m_bCheck = false;
	public:
		bool Create(ID3D11Device* pDevice, const TCHAR* szENABLE, const TCHAR* szDISABLE,
			const char* PSName = "PS", const TCHAR* szShaderName = L"../../Data/Shader/DefaultUI.hlsl");
	public:
		void Update();
		bool Frame(const float& spf, const float& accTime) noexcept override;
		//bool Render(ID3D11DeviceContext* pContext)noexcept override;
	public:
		JCheckCtrl(wstring NodeName);
		virtual ~JCheckCtrl();
	};
}