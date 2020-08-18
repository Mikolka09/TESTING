#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include <string>
#include<list>
#include<map>
#include<functional>
#include<Windows.h>
#include<iomanip>
#include<fstream>
#include <algorithm>
#include <chrono>


using namespace std;

//цвет символов
enum ConsoleColor
{
	Black = 0, Blue = 1, Green = 2, Cyan = 3, Red = 4, Magenta = 5, Brown = 6, LightGray = 7, DarkGray = 8,
	LightBlue = 9, LightGreen = 10, LightCyan = 11, LightRed = 12, LightMagenta = 13, Yellow = 14, White = 15
};

//цвет символов
inline void SetColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

//перенос курсосра по координатам
inline void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//подсчет времени (секундомер)
class Timer
{
private:
	// Псевдонимы типов используются для удобного доступа к вложенным типам
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1> >;

	std::chrono::time_point<clock_t> m_beg;

public:
	Timer() : m_beg(clock_t::now())
	{
	}

	void reset()
	{
		m_beg = clock_t::now();
	}

	double elapsed() const
	{
		return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
	}
};

//проверка пароля на размер
inline bool check_size(string p)
{
	const int r = 8;
	if (p.size() < r)
	{
		cout << "Пароль слишком короткий, попробуйте еще раз!!!" << endl;
		Sleep(2500);
		return true;
	}
	return false;
}

//шифрование пароля
inline unsigned int hashing(string p)
{
	hash<string> cod;
	unsigned int pass = cod(p);
	return pass;
}

//перевод строки в верхний регистр
inline void uppercase(string& str)
{
	transform(str.begin(), str.end(), str.begin(), ::toupper);
}

