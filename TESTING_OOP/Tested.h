#pragma once
#include"User.h"

class Tested :public User
{
private:

	list<string> result;
	list<User*> base_tested; //список данных пользователей
	map<int, list<User*>> base_users;  //база данных пользователей

public:

	map<int, list<User*>>  getBaseUsers() { return base_users; }
	void setBase(list<User*>base) { base_tested = base; }

	void chekIn();        //регестрация пользователя
	void menuTested();    //меню тестируемого
	void printResult();   //просмотр результата тестирования
	void saveTesting();   //сохранить промежуточное тестирование
	void loadTesting();   //загрузить последнее сохраненное тестирование

};
