#pragma once
#include"Tested.h"
#include "Maths.h"
#include "Results.h"


class Admin 
{
private:

	string log_admin_;                 //логин администратора
	unsigned int pass_admin_ = 0;      //пароль администратора
	
public:

	string get_log_admin() const { return log_admin_; }
	unsigned int get_pass_admin() const { return pass_admin_; }
	void set_log_admin(string log) { this->log_admin_ = log; }
	void set_pass_admin(unsigned int pas) { this->pass_admin_ = pas; }
	
	void registry_in_admin();       //регестрация администратора
	void menu_admin();              //меню админитсратора
	void control_tests();           //управление тестами
	void load_tests();              //загрузка тестов из файла

	void change_login();            //изменение логина и пароля администратора
	void registry_user();           //регестрация нового пользователя
	void control_user();            //изменение данных пользователя (тестируемого)
	void dell_user();               //удаление пользователя
	void edit_user();               //редактирование пользователя
	void print_user_file() const;   //печать пользователей в файл
	void print_user() const;        //печать пользователей на экран
	void look_statics() const;      //просмотр статистики
	void save_statics();            //сохранение статистики в файл
	void save_login_pass();         //сохранение логина и пароля администратора
	void load_login_pass();         //загрузка логина и пароля администратора

	
	friend class Testing;
};
