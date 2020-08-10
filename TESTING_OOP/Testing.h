#pragma once
#include <iostream>
#include"Tests.h"
#include"Admin.h"
#include"Tested.h"
#include<Windows.h>

using namespace std;

class Testing
{
private:

	Admin admin;  //администратор
	Tested tested;  //тестируемый
	
public:

	
	void enterSystem();  //авторизированный вход
	void menu();         //меню тестирования

};
