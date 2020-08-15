#pragma once
#include"User.h"
#include "Results.h"
#include "Maths.h"



class Tested :public User
{
private:
	
	list<Results*> result_;                        //список результатов пользователей
	list<User*> base_tested_;                      //список данных пользователей
	map<int, list<User*>> base_users_;             //база данных пользователей (тестируемых)
	map<string, list<Results*>> base_results_;     //база данных результатов пользователей (тестируемых)

public:

	map<int, list<User*>> get_base_users() const { return base_users_; }
	map<string, list<Results*>> get_base_results() const { return base_results_; }
	list<User*> get_base() const { return base_tested_; }
	list<Results*>get_result() const { return result_; }
	void set_base_tested(list<User*> base) { base_tested_ = base; }
	void set_results(list<Results*> res) { result_ = res; }

	void new_testing(const list<Results*>& res);          //сдать нове тестирование
	
	void registry_in();                      //регестрация пользователя
	void menu_tested(const list<Results*>& res);          //меню тестируемого
	void print_result(const list<Results*>& res) const;   //просмотр результата тестирования
	void save_testing();                     //сохранить промежуточное тестирование
	void load_testing();                     //загрузить последнее сохраненное тестирование
	void save_base();                        //сохранение базы тестируемых
	void load_base();                        //загрузка базы тестируемых
	


	friend class Admin;
	
};
