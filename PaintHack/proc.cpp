#include "proc.h"

DWORD GetProcID(const wchar_t* procName) {
	DWORD procID = 0;
	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hSnap != INVALID_HANDLE_VALUE) {
		PROCESSENTRY32 procEntry;
		procEntry.dwSize = sizeof(procEntry);
		if (Process32First(hSnap, &procEntry)) {
			do {
				if (!_wcsicmp(procEntry.szExeFile, procName)) {
					procID = procEntry.th32ProcessID;
					break;
				}
			} while (Process32Next(hSnap, &procEntry));
		}
	}
	CloseHandle(hSnap);
	return procID;
}

uintptr_t GetModuleBaseAdress(DWORD procID, const wchar_t* modName) {
	uintptr_t modBaseAddr = 0;
	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, procID);
	if (hSnap != INVALID_HANDLE_VALUE) {
		MODULEENTRY32 modEntry;
		modEntry.dwSize = sizeof(modEntry);
		if (Module32First(hSnap, &modEntry)) {
			do {
				if (!_wcsicmp(modEntry.szModule, modName)) {
					modBaseAddr = (uintptr_t)modEntry.modBaseAddr;
					break;
				}
			} while (Module32Next(hSnap, &modEntry));
		}
	}
	return modBaseAddr;
}

uintptr_t FindDMAAddy(HANDLE hProc, uintptr_t ptr, std::vector<unsigned int> offset) {
	uintptr_t addr = ptr;
	for (unsigned int i = 0; i < offset.size(); ++i) {
		ReadProcessMemory(hProc, (BYTE*)addr, &addr, sizeof(addr), 0);
		addr += offset[i];
	}
	return addr;
}

void RefreshWindow() {
	HWND foreground = GetForegroundWindow();
	wchar_t window_title[256];
	GetWindowText(foreground, window_title, 256);
	if (wcscmp(window_title, L"Unbenannt - Paint") == 0) {
		mouse_event(MOUSEEVENTF_WHEEL, 0, 0, 4 * 120, 0);
	}
}

bool HasFocus() {
	HWND foreground = GetForegroundWindow();
	wchar_t window_title[256];
	GetWindowText(foreground, window_title, 256);
	if (wcscmp(window_title, L"Unbenannt - Paint") == 0) {
		return true;
	}
	return false;
}
