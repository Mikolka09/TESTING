#pragma once

#include"Tests.h"
#include"Admin.h"
#include"Tested.h"
#include "Functions.h"


class Testing
{
private:

	Admin admin;  //администратор
	Tested tested;  //тестируемый
	
public:

	
	void enterSystem();  //авторизированный вход
	void menu();         //меню тестирования

};
