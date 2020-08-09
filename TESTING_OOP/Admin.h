#pragma once
#include"User.h"



class Admin :public User
{
private:

	string log_admin = "";  //логин администратора
	int pass_admin = 0;     //пароль администратора
	
public:

	

	string getLogAdmin() { return log_admin; }
	int getPassAdmin() { return pass_admin; }
	void setLogAdmin(string log) { this->log_admin = log; }
	void setPassAdmin(int pas) { this->pass_admin = pas; }
	
	void chekInAdmin();   //регестрация администратора
	void menuAdmin();     //меню админитсратора
	void addTests();      //добавление тестов, категорий или вопросов
	void loadTests();     //загрузка тестов из файла

	void changeLogin();   //изменение логина и пароля администратора
	void controlUser();   //изменение данных пользователя (тестируемого)
	void lookStatics();   //просмотр статистики
	void saveStatics();   //сохранение статистики в файл
	void saveLoginPass();   //сохранение логина и пароля администратора
	void loadLoginPass();   //загрузка логина и пароля администратора
};
