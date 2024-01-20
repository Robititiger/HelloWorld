// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <Windows.h>
#include <iostream>

#pragma region ConsoleStuff
void InitConsole() {
	AllocConsole();
	freopen("CONOUT$", "w", stdout);
	HWND consoleWindow = GetConsoleWindow();
	ShowWindow(consoleWindow, SW_SHOW);
}
#pragma endregion

void funnyPrint() {
	printf("Hello World\n");
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
	switch (ul_reason_for_call) {
	case DLL_PROCESS_ATTACH:
        InitConsole();
		funnyPrint();
        break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

// i was tired and bored so i just made this for my profile i guess
