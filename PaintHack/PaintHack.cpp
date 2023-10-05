#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>
#include <iostream>
#include <tchar.h>
#include <vector>
#include <stdlib.h>
#include "proc.h"
#include "Paint.h"

//100x100 Zeichenfläche

const int x = 5;



int main()
{
	//Prozess ID von Paint

	DWORD procID = GetProcID(L"mspaint.exe");

	//ModuleBaseAdress von Paint
	uintptr_t moduleBase = GetModuleBaseAdress(procID, L"mspaint.exe");

	//Handle zum Prozess
	HANDLE hProcess = 0;
	hProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, procID);

	//Ergebniss der Pointerchain
	uintptr_t dynamicPtrBaseAddr = moduleBase + 0x000E9E80;

	const std::vector<unsigned int> ImageDataOffsets = { 0x3C8, 0xC8, 0x90, 0x110, 0x10, 0x88,0x0 };
	uintptr_t ImageDataAddr = FindDMAAddy(hProcess, dynamicPtrBaseAddr, ImageDataOffsets);

	std::cout << "Bitte geben Sie ein Level an: ";
	int lvl = 0;
	std::cin >> lvl;

	Paint mspaint(lvl);

	BYTE* pxDatas = mspaint.CreatePixelData();


	while (!HasFocus()) {
		Sleep(100);
	};

	while (true) {
		pxDatas = mspaint.CreateStartScreen();
		WriteProcessMemory(hProcess, (BYTE*)ImageDataAddr, pxDatas, mspaint.getLength(), nullptr);
		RefreshWindow();
		if (GetAsyncKeyState(VK_RETURN) & 0x8000)break;
		Sleep(100);
	}
	
	while (mspaint.isAlive) {
		if (GetKeyState('A') & 0x8000) {
			mspaint.MoveSnake(MoveDirection::Left);
		} else if (GetKeyState('W') & 0x8000) {
			mspaint.MoveSnake(MoveDirection::Up);
		} else if (GetKeyState('D') & 0x8000) {
			mspaint.MoveSnake(MoveDirection::Right);
		} else if (GetKeyState('S') & 0x8000) {
			mspaint.MoveSnake(MoveDirection::Down);
		} else {
			mspaint.MoveSnake(MoveDirection::Stand);
		}
		pxDatas = mspaint.CreatePixelData();
		WriteProcessMemory(hProcess, (BYTE*)ImageDataAddr, pxDatas, mspaint.getLength(), nullptr);
		RefreshWindow();
		Sleep(100);
	}

	mspaint.DisplayPoints();
	pxDatas = mspaint.CreatePixelData();
	WriteProcessMemory(hProcess, (BYTE*)ImageDataAddr, pxDatas, mspaint.getLength(), nullptr);
	RefreshWindow();
}



//Rot 0; Grün 162; Blau 232 

//Letzter Wert ist Rot
//MittlererWert ist Grün
//Erster Wert ist Blau