#pragma once
#include "Tested.h"
#include"Tests.h"
#include "Admin.h"

class Mechanics;
class Quantum;

class Physics
{
		
public:

	Physics(){}

	void menu_physics_user(string const& log);     //меню по математике для пользователя
	void menu_physics_admin();                     //меню по математике для администратора
	void shapka_start(string const& log);
};

class Quantum :public Physics
{
private:
	string cat_q_ = "КВАНТОВАЯ";
	list<Tests*> base_quan_;
public:

	Quantum() {}
	Quantum(const Quantum& ob);
	Quantum& operator=(const Quantum& ob);

	void passing_test_quan(string const& log);       //прохождение теста по квантовой
	void creature_test_quan();                       //создание теста по квантовой
	void edit_test_quan();                           //редактирование тестов по квантовой
	void save_test_quan();                           //сохранение тестов по квантовой
	void load_test_quan();                           //загрузка тестов по квантовой
	void print_test_quan() const;                    //печать на экран теста по квантовой
	void print_test_all_quan() const;                //печать на экран всех тестов по квантовой
	
	friend class Physics;
};

class Mechanics :public Physics
{
private:
	string cat_m_ = "МЕХАНИКА";
	list<Tests*> base_mech_;
public:

	Mechanics() {}
	Mechanics(const Mechanics& ob);
	Mechanics& operator=(const Mechanics& ob);

	void passing_test_mech(string const& log);       //прохождение теста по механике
	void creature_test_mech();                       //создание теста по механике
	void edit_test_mech();                           //редактирование тестов по механике
	void save_test_mech();                           //сохранение тестов по механике
	void load_test_mech();                           //загрузка тестов по механике
	void print_test_mech() const;                    //печать на экран теста по механике
	void print_test_all_mech() const;                //печать на экран всех тестов по механике
	
	friend class Physics;;
};