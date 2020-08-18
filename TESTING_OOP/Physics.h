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

	void menu_physics_user(string const& log);     //меню по математике для пользователя
	void menu_physics_admin();                     //меню по математике для администратора
};

class Quantum :public Physics
{
private:
	string cat_q_ = "КВАНТОВАЯ";
	list<Tests*> base_quan_;
public:

	void passing_test_quan(string const& log);       //прохождение теста
	void creature_test_quan(string c, list<Tests*> b);                       //создание теста
	void edit_test_quan();                           //редактирование тестов
	void save_test_quan();                           //сохранение тестов
	void load_test_quan();                           //загрузка тестов
	void print_test_quan() const;                    //печать на экран теста

	friend class Physics;
};

class Mechanics :public Physics
{
private:
	string cat_m_ = "МЕХАНИКА";
	list<Tests*> base_mech_;
public:

	void passing_test_mech(string const& log);       //прохождение теста
	void creature_test_mech();                       //создание теста
	void edit_test_mech();                           //редактирование тестов
	void save_test_mech();                           //сохранение тестов
	void load_test_mech();                           //загрузка тестов
	void print_test_mech() const;                    //печать на экран теста

	friend class Physics;;
};