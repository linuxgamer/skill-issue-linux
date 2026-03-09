#pragma once

class CApp
{
public:
	CApp();

	bool IsInitialized();
	bool StartInterfaces();
	bool StartHooks();
private:
	bool m_bInitialized;
};

extern CApp gApp;