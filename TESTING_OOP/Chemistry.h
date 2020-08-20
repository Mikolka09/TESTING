#pragma once
#include "Tested.h"
#include"Tests.h"
#include "Admin.h"

class Organic;
class Inorganic;

class Chemistry
{
public:

	Chemistry() {}

	void menu_chem_user(string const& log);     //меню по химии для пользователя
	void menu_chem_admin();                     //меню по химии для администратора
};

class Organic :public Chemistry
{
private:
	string cat_or_ = "ОРГАНИЧЕСКАЯ";
	list<Tests*> base_or_;                      //база тестов по органической

public:

	Organic() {}
	Organic(const Organic& ob);
	Organic& operator=(const Organic& ob);

	void passing_test_or(string const& log);       //прохождение теста по органической
	void creature_test_or();                       //создание теста по по органической
	void edit_test_or();                           //редактирование тестов по органической
	void save_test_or();                           //сохранение тестов по органической
	void load_test_or();                           //загрузка тестов по органической
	void print_test_or() const;                    //печать на экран теста по органической
	void print_test_all_or() const;                //печать на экран всех тестов по органической

	friend class Chemistry;
};

class Inorganic :public Chemistry
{
private:
	string cat_in_ = "НЕОРГАНИЧЕСКАЯ";
	list<Tests*> base_in_;                         //база тестов по неорганической

public:

	Inorganic() {}
	Inorganic(const Inorganic& ob);
	Inorganic& operator=(const Inorganic& ob);

	void passing_test_in(string const& log);       //прохождение теста по неорганической
	void creature_test_in();                       //создание теста по неорганической
	void edit_test_in();                           //редактирование тестов по неорганической
	void save_test_in();                           //сохранение тестов по неорганической
	void load_test_in();                           //загрузка тестов по неорганической
	void print_test_in() const;                    //печать на экран теста по неорганической
	void print_test_all_in() const;                //печать на экран всех тестов по неорганической

	friend class Chemistry;

};
