#include <Windows.h>
#include <timeapi.h>
#include <stdio.h>

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	static TIMECAPS timeCaps;

	switch (fdwReason) {
		case DLL_PROCESS_ATTACH: {
			timeGetDevCaps(&timeCaps, sizeof(TIMECAPS));
			timeBeginPeriod(timeCaps.wPeriodMin);
			break;
		}

		case DLL_PROCESS_DETACH:
			timeEndPeriod(timeCaps.wPeriodMin);
			break;

		case DLL_THREAD_ATTACH:
			break;

		case DLL_THREAD_DETACH:
			break;
	}

	return TRUE;
}

extern "C" __declspec(dllexport) double gmonitor_initialize()
{
	// NOTE Here just to be super, super sure that DllMain is hooked
	return 0;
}
