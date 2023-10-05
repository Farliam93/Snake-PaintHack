#pragma once
#include <vector>
#include <Windows.h>
#include <TlHelp32.h>

DWORD GetProcID(const wchar_t* procName);

uintptr_t GetModuleBaseAdress(DWORD procID, const wchar_t* modName);

uintptr_t FindDMAAddy(HANDLE hProc, uintptr_t ptr, std::vector<unsigned int>);

void RefreshWindow();

bool HasFocus();