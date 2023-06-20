#pragma once

#include <memory>
#include "Common/DirectXSample.h"
#include "Common/DeviceResources.h"
#include "Common/StepTimer.h"
#include "LogicClass.h"
#include "MoveLookController.h"
#include "Camera.h"
#include "MyRenderer.h"


class GameClass : public winrt::implements<GameClass, winrt::Windows::Foundation::IInspectable>, DX::IDeviceNotify
{
public:
	GameClass(std::shared_ptr<DX::DeviceResources> const& deviceResources);
	~GameClass();
	void CreateWindowSizeDependentResources();
	void CreateDeviceDependentResources();
	void AddObject(std::shared_ptr<Cube>);
	void Update();
	bool Render();

	// IDeviceNotify
	virtual void OnDeviceLost();
	virtual void OnDeviceRestored();

private:

	float delta;

	std::shared_ptr <LogicClass>						m_logic;

	std::shared_ptr<DX::DeviceResources>				m_deviceResources;

	std::shared_ptr<MyRenderer>							m_sceneRenderer;

	std::shared_ptr<MoveLookController>                 m_controller;

};



