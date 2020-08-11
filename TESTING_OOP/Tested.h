#pragma once
#include"User.h"


class Tested :public User
{
private:
	
	list<string> result;
	list<User*> base_tested; //список данных пользователей
	map<unsigned int, list<User*>> base_users;  //база данных пользователей (тестируемых)

public:

	map<unsigned int, list<User*>>  getBaseUsers() { return base_users; }
	list<User*> getBase() { return base_tested; }
	void setBase(list<User*>base) { base_tested = base; }

	void newTesting();    //сдать нове тестирование
	void chekIn();        //регестрация пользователя
	void menuTested();    //меню тестируемого
	void printResult();   //просмотр результата тестирования
	void print();         //печать списка тестируемых
	void saveTesting();   //сохранить промежуточное тестирование
	void loadTesting();   //загрузить последнее сохраненное тестирование
	void saveBase();      //сохранение базы тестируемых
	void loadBase();      //загрузка базы тестируемых

	friend class Admin;
};
