//============ Copyright (c) Valve Corporation, All rights reserved. ============
#pragma once

#include <memory>
#include <windows.h>

#include "controller_device_driver.h"
#include "openvr_driver.h"

// make sure your class is publicly inheriting vr::IServerTrackedDeviceProvider!
class MyDeviceProvider : public vr::IServerTrackedDeviceProvider
{
public:
	vr::EVRInitError Init( vr::IVRDriverContext *pDriverContext ) override;
	const char *const *GetInterfaceVersions() override;

	void RunFrame() override;

	bool ShouldBlockStandbyMode() override;
	void EnterStandby() override;
	void LeaveStandby() override;

	void Cleanup() override;

private:

	int InitBridge();
	void ReleaseBridge();

	std::unique_ptr<MyControllerDeviceDriver> my_left_controller_device_;
	//std::unique_ptr<MyControllerDeviceDriver> my_right_controller_device_;

	HANDLE m_hSharedMemory;
	LPVOID m_lpSharedMemory;
	//HANDLE m_hMutex;
};