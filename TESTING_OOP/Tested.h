#pragma once
#include"User.h"


class Tested :public User
{
private:
	
	list<string> result_;                          //список результатов пользователей
	list<User*> base_tested_;                      //список данных пользователей
	map<int, list<User*>> base_users_;             //база данных пользователей (тестируемых)

public:

	map<int, list<User*>> get_base_users() const { return base_users_; }
	list<User*> get_base() const { return base_tested_; }
	void set_base(const list<User*>base) { base_tested_ = base; }

	void new_testing();          //сдать нове тестирование
	void registry_in();          //регестрация пользователя
	void menu_tested();          //меню тестируемого
	void print_result() const;   //просмотр результата тестирования
	void save_testing();         //сохранить промежуточное тестирование
	void load_testing();         //загрузить последнее сохраненное тестирование
	void save_base();            //сохранение базы тестируемых
	void load_base();            //загрузка базы тестируемых
	

	friend class Admin;
	
};
