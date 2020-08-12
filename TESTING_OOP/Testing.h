#pragma once

#include"Tests.h"
#include"Admin.h"
#include"Tested.h"
#include "Functions.h"


class Testing
{
private:

	Admin admin_;          //администратор
	Tested tested_;        //тестируемый
	
public:

	
	void enter_system();   //авторизированный вход
	
};

