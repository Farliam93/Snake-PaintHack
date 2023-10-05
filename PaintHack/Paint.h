#pragma once
#include <Windows.h>
#include <vector>
#include <stdexcept>
#include <array>
#include <map>
#include <random>
#include <iostream>
#include <string>

enum FieldType { None = 0, Wall = 1, Snake = 2,SnakeHead = 3, Fruit = 4, ColorPlane = 5};

enum MoveDirection {Stand = 0, Left = 1, Up = 2, Right = 3, Down = 4};

struct Color {
	Color(std::array<double, 3> _rgb) : rgb(_rgb) {}
	std::array<double, 3> rgb;
	static constexpr auto Red = std::array<double, 3>{1.0, 0.0, 0.0};
	static constexpr auto Yellow = std::array<double, 3>{1.0, 1.0, 0.0};
	static constexpr auto Black = std::array<double, 3> {0, 0, 0};
};


class Paint {
public:
	//Methoden
	void ClearScreen();
	void MoveSnake(MoveDirection dir);
	void RefreshBlockArea(std::vector<POINT> points);
	void DisplayPoints();
	void RefreshDisplay();
	//Funktionen
	POINT SpawnAFruit();
	bool CanGoForward(POINT pkt);
	bool IsFruit(POINT pkt);
	int GetPoints();
	BYTE* CreatePixelData();
	BYTE* CreateStartScreen();
	Color GetPixelFromOffset(POINT pkt);
	void SetColorFromPixel(POINT pt, Color clr);
	//Konstruktor
	Paint(int lvl);
	~Paint();
	//Variabeln
	bool isAlive = true;
	int getLength();
	std::map<FieldType, Color> ColorType;	
private:
	Paint();
	//Variabeln
	int myPoints = 0;
	int level = 1;
	MoveDirection curMoveDir = MoveDirection::Down;
	const int Width = 400;
	const int Height = 400;
	const int Blocks = 40;	//<-- Muss dem Wert im PlayField entsprechen!
	std::vector<Color> DrawArea;
	BYTE* PaintArea;
	std::array<double, 3> DefaultBackColor;
	std::vector<POINT> MySnake;
	//Spielfeld erstellen
	void CreateFieldData();
	POINT GetNextPosition(MoveDirection dir);
	void SnakeExtend(POINT fruit);
};


