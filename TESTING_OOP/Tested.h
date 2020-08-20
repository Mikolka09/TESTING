#pragma once
#include"User.h"
#include "Results.h"
#include "Maths.h"
#include "Physics.h"
#include "Chemistry.h"
#include "Start.h"



class Tested :public User
{
private:

	list<Results*> result_;                        //список результатов пользователей
	list<User*> base_tested_;                      //список данных пользователей
	map<string, list<Results*>> base_results_;     //база данных результатов пользователей (тестируемых)

public:

	Tested(){}
	Tested(const Tested& ob);
	Tested& operator=(const Tested& ob);

	map<string, list<Results*>> get_base_results() const { return base_results_; }
	list<User*> get_base() const { return base_tested_; }
	list<Results*>get_result() const { return result_; }
	void set_base_tested(list<User*> base) { base_tested_ = base; }
	void set_results(list<Results*> res) { result_ = res; }
	void set_base_results(map<string, list<Results*>> mp) { base_results_ = mp; }

	void new_testing(string const& log);               //сдать нове тестирование
	void registry_in();                                //регестрация пользователя
	bool check_in(unsigned int ps, string lg);         //проверка на повторение
	void menu_tested(string const& log);               //меню тестируемого
	void print_result(string const& log) const;        //просмотр результата тестирования
	void save_results();                               //сохранить промежуточное тестирование
	void load_results();                               //загрузить последнее сохраненное тестирование 
	void save_base();                                  //сохранение базы тестируемых
	void load_base();                                  //загрузка базы тестируемых
	void get_res_base (Results*& res);                 //проверка и добавление нового результата
	void get_user_base(User*& us);                     //проверка и добавление нового пользователя
	void print_result_file(string const& log) const;   //печать результатов тестирования в файл
	void print_users();                                //просмотр базы пользователей
	void print_users_file();                           //печать базы пользователей в файл

	friend class Admin;
	
};
