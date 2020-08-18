#pragma once
#include "Tested.h"
#include"Tests.h"
#include "Admin.h"

class Mechanics;
class Quantum;

class Physics
{
private:
		
public:

	virtual void passing_test(string const& log);       //прохождение теста
	virtual void creature_test(string c, list<Tests*> b);                       //создание теста
	virtual void edit_test();                           //редактирование тестов
	virtual void save_test();                           //сохранение тестов
	virtual void load_test();                           //загрузка тестов
	virtual void print_test() const;                    //печать на экран теста

	void menu_physics_user(string const& log);     //меню по математике для пользователя
	void menu_physics_admin();                     //меню по математике для администратора
};

class Quantum :public Physics
{
private:
	string cat_q_ = "КВАНТОВАЯ";
	list<Tests*> base_quan_;
public:

	virtual void passing_test(string const& log);       //прохождение теста
	virtual void creature_test(string c, list<Tests*> b);                       //создание теста
	virtual void edit_test();                           //редактирование тестов
	virtual void save_test();                           //сохранение тестов
	virtual void load_test();                           //загрузка тестов
	virtual void print_test() const;                    //печать на экран теста

	friend class Maths;
};

class Mechanics :public Physics
{
private:
	string cat_m_ = "МЕХАНИКА";
	list<Tests*> base_mech_;
public:

	virtual void passing_test(string const& log);       //прохождение теста
	virtual void creature_test();                       //создание теста
	virtual void edit_test();                           //редактирование тестов
	virtual void save_test();                           //сохранение тестов
	virtual void load_test();                           //загрузка тестов
	virtual void print_test() const;                    //печать на экран теста

	friend class Maths;
};