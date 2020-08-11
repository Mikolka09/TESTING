#pragma once

#include<iostream>
#include <string>
#include<list>
#include<map>
#include<functional>
#include<Windows.h>
#include<iomanip>
#include<fstream>



using namespace std;

//проверка пароля на размер
inline bool checkSize(string p)
{
	int r = 8;
	if (p.size() < r)
	{
		cout << "Пароль слишком короткий, попробуйте еще раз!!!" << endl;
		Sleep(2500);
		return true;
	}
	else
		return false;
}

//шифрование пароля
inline int hashing(string p)
{
	hash<string> cod;
	int pass = cod(p);
	return pass;
}


