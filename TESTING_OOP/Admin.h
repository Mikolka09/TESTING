#pragma once
#include"User.h"
#include"Tested.h"



class Admin :public User
{
private:

	string log_admin = "";  //логин администратора
	int pass_admin = 0;     //пароль администратора
	Tested user;            //пользователь
public:

	

	string getLogAdmin() { return log_admin; }
	int getPassAdmin() { return pass_admin; }
	void setLogAdmin(string log) { this->log_admin = log; }
	void setPassAdmin(int pas) { this->pass_admin = pas; }
	
	void chekInAdmin();     //регестрация администратора
	void menuAdmin();       //меню админитсратора
	void addTests();        //добавление тестов, категорий или вопросов
	void loadTests();       //загрузка тестов из файла

	void changeLogin();     //изменение логина и пароля администратора
	void controlUser();     //изменение данных пользователя (тестируемого)
	void dellUser();        //удаление пользователя
	void editUser();        //редактирование пользователя
	void printUserFile();   //печать пользователей в файл
	void printUser();       //печать пользователей на экран
	void lookStatics();     //просмотр статистики
	void saveStatics();     //сохранение статистики в файл
	void saveLoginPass();   //сохранение логина и пароля администратора
	void loadLoginPass();   //загрузка логина и пароля администратора
};
