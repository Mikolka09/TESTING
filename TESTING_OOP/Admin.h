#pragma once
#include"Tested.h"
#include "Maths.h"


class Admin 
{
private:

	string log_admin_;        //логин администратора
	int pass_admin_ = 0;      //пароль администратора
	
public:

	string get_log_admin() const { return log_admin_; }
	int get_pass_admin() const { return pass_admin_; }
	void set_log_admin(string log) { this->log_admin_ = log; }
	void set_pass_admin(int pas) { this->pass_admin_ = pas; }
	
	void registry_in_admin();                  //регестрация администратора
	void menu_admin(Tested& tes);              //меню админитсратора
	void control_tests();                      //управление тестами
	void load_tests();                         //загрузка тестов из файла

	void change_login();                       //изменение логина и пароля администратора
	void registry_user(Tested& tes);           //регестрация нового пользователя
	void control_user(Tested& tes);            //изменение данных пользователя (тестируемого)
	void dell_user(Tested& tes);               //удаление пользователя
	void edit_user(Tested& tes);               //редактирование пользователя
	void print_user_file(Tested& tes) const;   //печать пользователей в файл
	void print_user(Tested& tes) const;        //печать пользователей на экран
	void look_statics() const;                 //просмотр статистики
	void save_statics();                       //сохранение статистики в файл
	void save_login_pass();                    //сохранение логина и пароля администратора
	void load_login_pass();                    //загрузка логина и пароля администратора
};
