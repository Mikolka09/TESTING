#pragma once
#include "Tested.h"
#include"Tests.h"
#include "Admin.h"

class Algebra;
class Geometry;


class Maths
{
public:

	Maths(){}
		
	void menu_maths_user(string const& log);     //меню по математике для пользователя
	void menu_maths_admin();                     //меню по математике для администратора
	
};


class Algebra :public Maths
{
private:
	string cat_al_ = "АЛГЕБРА";
	list<Tests*> base_alg_;        //база тестов по алгебре

public:

	Algebra() {}
	Algebra (const Algebra& ob);
	Algebra& operator=(const Algebra& ob);
		
	void passing_test_alg(string const& log);       //прохождение теста по алгебре
	void creature_test_alg();                       //создание теста по алгебре
	void edit_test_alg();                           //редактирование тестов по алгебре
	void save_test_alg();                           //сохранение тестов по алгебре
	void load_test_alg();                           //загрузка тестов по алгебре
	void print_test_alg() const;                    //печать на экран теста по алгебре
	void print_test_all_alg() const;                //печать на экран всех тестов по алгебре

	friend class Maths;
};

class Geometry :public Maths    
{
private:
	string cat_g_ = "ГЕОМЕТРИЯ";
	list<Tests*> base_geo_;        //база тестов по геометрии

public:

	Geometry() {}
	Geometry(const Geometry& ob);
	Geometry& operator=(const Geometry& ob);
	
	void passing_test_geo(string const& log);       //прохождение теста по геометрии
	void creature_test_geo();                       //создание теста по геометрии
	void edit_test_geo();                           //редактирование тестов по геометрии
	void save_test_geo();                           //сохранение тестов по геометрии
	void load_test_geo();                           //загрузка тестов по геометрии
	void print_test_geo() const;                    //печать на экран теста по геометрии
	void print_test_all_geo() const;                //печать на экран всех тестов по геометрии

	friend class Maths;
};

