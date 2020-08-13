#include "Maths.h"


//меню по математике 
void Maths::menu_maths_user()
{
	while (true)
	{
		Algebra alg_;
		Geometry geo_;
		system("cls");
		cout << "БАЗА ТЕСТОВ ПО МАТЕМАТИКЕ для ПОЛЬЗОВАТЕЛЯ\n" << endl;
		cout << "КАТЕГОРИИ ТЕСТОВ ПО МАТЕМАТИКЕ:" << endl;
		cout << "1. Тесты по АЛГЕБРЕ\n" << "2. Тесты по ГЕОМЕТРИИ\n"
			<< "3. Возврат в предыдущее меню" << endl;
		int var;
		cin >> var;
		cin.ignore();
		switch (var)
		{
		case 1:
			alg_.menu_alg();
			break;
		case 2:
			geo_.menu_geo();
			break;
		case 3:
			//Tested::menu_tested();
			break;
		default:;
		}
	}
}


//меню по математике для администратора
void Maths::menu_maths_admin()
{
	while (true)
	{
		Admin ad_;
		Algebra alg_;
		Geometry geo_;
		system("cls");
		cout << "БАЗА ТЕСТОВ ПО МАТЕМАТИКЕ для АДМИНИСТРАТОРА\n" << endl;
		cout << "МЕНЮ ДЕЙСТВИЙ:" << endl;
		cout << "1. Создание тестов по АЛГЕБРЕ\n" << "2. Создание тестов по ГЕОМЕТРИИ\n"
			<< "3. Редактирование тестов по АЛГЕБРЕ\n" << "4. Редактирование тестов по ГЕОМЕТРИИ\n"
			<< "5. Возврат в предыдущее меню" << endl;
		int var;
		cin >> var;
		cin.ignore();
		switch (var)
		{
		case 1:
			alg_.creature_test_alg();
			break;
		case 2:
			geo_.creature_test_geo();
			break;
		case 3:
			alg_.edit_test_alg();
			break;
		case 4:
			geo_.edit_test_geo();
			break;
		case 5:
			ad_.control_tests();
			break;
		default:;
		}
	}
}


//меню по алгебре для пользователя
void Algebra::menu_alg()
{
	while (true)
	{
		system("cls");
		cout << "РАЗДЕЛ АЛГЕБРА\n" << endl;
		cout << "МЕНЮ:" << endl;
		cout << "1. Прохождние тестов\n" << "2. Промежуточное сохранение теста\n"
			<< "3. Загрузить последнее сохраненное тестирование\n" << "4. Возврат в предыдущее меню" << endl;
		int var1;
		cin >> var1;
		cin.ignore();
		switch (var1)
		{
		case 1:
			passing_test_alg();
			break;
		case 2:
			save_media_test_alg();
			break;
		case 3:
			load_media_test_alg();
			break;
		case 4:
			menu_maths_user();
			break;
		default:;
		}
	}
}

//прохождение теста по алгебре
void Algebra::passing_test_alg()
{
}

//создание теста по алгебре
void Algebra::creature_test_alg()
{
	Tests* tes = new Tests;
	tes->set_category("algebra");
	system("cls");
	cout << "СОЗДАНИЕ ТЕСТА ПО АЛГЕБРЕ:\n" << endl;
	cout << "Введите номер теста: ";
	int idd = 0;
	cin >> idd;
	if (base_alg_.empty())
		tes->set_id(idd);
	else
	{
		bool p = true;
		while (p)
		{
			system("cls");
			cout << "СОЗДАНИЕ ТЕСТА ПО АЛГЕБРЕ:\n" << endl;
			cout << "Введите номер теста: ";
			cin >> idd;
			auto it = base_alg_.begin();
			for (; it != base_alg_.end(); ++it)
			{
				if ((*it)->get_id() == idd)
					p = true;
				else
					p = false;
			}

		}
		tes->set_id(idd);
	}
	string q;
	system("cls");
	cout << "СОЗДАНИЕ ТЕСТА ПО АЛГЕБРЕ:\n" << endl;
	cout << "Введите текст вопроса: " << endl;;
	char* buff = new char;
	cin.ignore();
	cin.getline(buff, 1200);
	q = buff;
	if (base_alg_.empty())
		tes->set_question(q);
	else
	{
		bool w = true;
		while (w)
		{
			system("cls");
			cout << "СОЗДАНИЕ ТЕСТА ПО АЛГЕБРЕ:\n" << endl;
			cout << "Введите текст вопроса: " << endl;;
			char* buff = new char;
			cin.getline(buff, 1200);
			q = buff;
			auto it = base_alg_.begin();
			for (; it != base_alg_.end(); ++it)
			{
				if (strcmp((*it)->get_question().c_str(), q.c_str()) != 0)
					w = true;
				else
					w = false;
			}

		}
		tes->set_question(q);
	}
	string an;
	system("cls");
	cout << "СОЗДАНИЕ ТЕСТА ПО АЛГЕБРЕ:\n" << endl;
	cout << "Введите варианты ответов: " << endl;
	char* buff1 = new char;
	cin.getline(buff1, 1200);
	an = buff1;
	if (base_alg_.empty())
		tes->set_answer(an);
	else
	{
		bool a = true;
		while (a)
		{
			system("cls");
			cout << "СОЗДАНИЕ ТЕСТА ПО АЛГЕБРЕ:\n" << endl;
			cout << "Введите варианты ответов: " << endl;
			char* buff = new char;
			cin.getline(buff, 1200);
			an = buff;
			if (base_alg_.empty())
				tes->set_answer(an);
			else
			{
				auto it = base_alg_.begin();
				for (; it != base_alg_.end(); ++it)
				{
					if (strcmp((*it)->get_answer().c_str(), an.c_str()) != 0)
						a = true;
					else
						a = false;
				}
			}
		}
		tes->set_answer(an);
	}
	int v = 0, b = 0;
	system("cls");
	cout << "СОЗДАНИЕ ТЕСТА ПО АЛГЕБРЕ:\n" << endl;
	cout << "Введите номер правильного ответа: ";
	cin >> v;
	tes->set_right_answer(v);
	cout << endl;
	cout << "Введите количество балов за ответ: ";
	cin >> b;
	tes->set_balls(b);
	base_alg_.push_back(tes);
	system("cls");
	cout << "НОВЫЙ ТЕСТ по АЛГЕБРЕ СОЗДАН!!!" << endl;
	save_test_alg();
	print_test_alg();
}

//редактирование тестов по алгебре
void Algebra::edit_test_alg()
{
}

//сохранение промежуточного тестирования по алгебре
void Algebra::save_media_test_alg()
{
}

//загрузка промежуточного тестирования по алгебре
void Algebra::load_media_test_alg()
{
}

//сохранение нового теста по алгебре
void Algebra::save_test_alg()
{
}

//печать на экран теста по алгебре
void Algebra::print_test_alg() const
{
	system("cls");
	int idd;
	cout << "ПЕЧАТЬ ТЕСТА ПО НОМЕРУ:\n" << endl;
	cout << "Введите номер теста: " << endl;
	cin >> idd;
	auto it = base_alg_.begin();
	for (; it != base_alg_.end(); ++it)
	{
		if ((*it)->get_id() == idd)
			cout << (*it);
		else
			cout << "ТЕСТ с таким номер ОТСУТСТВУВЕТ!!!" << endl;
	}
	system("pause");
}

//меню по геометрии для пользователя
void Geometry::menu_geo()
{
	while (true)
	{
		system("cls");
		cout << "РАЗДЕЛ ГЕОМЕТРИЯ\n" << endl;
		cout << "МЕНЮ:" << endl;
		cout << "1. Прохождние тестов\n" << "2. Промежуточное сохранение теста\n"
			<< "3. Загрузить последнее сохраненное тестирование\n" << "4. Возврат в предыдущее меню" << endl;
		int var1;
		cin >> var1;
		cin.ignore();
		switch (var1)
		{
		case 1:
			passing_test_geo();
			break;
		case 2:
			save_media_test_geo();
			break;
		case 3:
			load_media_test_geo();
			break;
		case 4:
			menu_maths_user();
			break;
		default:;
		}
	}
}

//прохождение теста по геометрии
void Geometry::passing_test_geo()
{
}

//создание теста по геометрии
void Geometry::creature_test_geo()
{
	Tests* tes = new Tests;
	tes->set_category("geometry");
	system("cls");
	cout << "СОЗДАНИЕ ТЕСТА ПО ГЕОМЕТРИИ:\n" << endl;
	cout << "Введите номер теста: ";
	int idd = 0;
	cin >> idd;
	if (base_geo_.empty())
		tes->set_id(idd);
	else
	{
		bool p = true;
		while (p)
		{
			system("cls");
			cout << "СОЗДАНИЕ ТЕСТА ПО ГЕОМЕТРИИ:\n" << endl;
			cout << "Введите номер теста: ";
			cin >> idd;
			auto it = base_geo_.begin();
			for (; it != base_geo_.end(); ++it)
			{
				if ((*it)->get_id() == idd)
					p = true;
				else
					p = false;
			}

		}
		tes->set_id(idd);
	}
	string q;
	system("cls");
	cout << "СОЗДАНИЕ ТЕСТА ПО ГЕОМЕТРИИ:\n" << endl;
	cout << "Введите текст вопроса: " << endl;;
	char* buff = new char;
	cin.ignore();
	cin.getline(buff, 1200);
	q = buff;
	if (base_geo_.empty())
		tes->set_question(q);
	else
	{
		bool w = true;
		while (w)
		{
			system("cls");
			cout << "СОЗДАНИЕ ТЕСТА ПО ГЕОМЕТРИИ:\n" << endl;
			cout << "Введите текст вопроса: " << endl;;
			char* buff = new char;
			cin.getline(buff, 1200);
			q = buff;
			auto it = base_geo_.begin();
			for (; it != base_geo_.end(); ++it)
			{
				if (strcmp((*it)->get_question().c_str(), q.c_str()) != 0)
					w = true;
				else
					w = false;
			}

		}
		tes->set_question(q);
	}
	string an;
	system("cls");
	cout << "СОЗДАНИЕ ТЕСТА ПО ГЕОМЕТРИИ:\n" << endl;
	cout << "Введите варианты ответов: " << endl;
	char* buff1 = new char;
	cin.getline(buff1, 1200);
	an = buff1;
	if (base_geo_.empty())
		tes->set_answer(an);
	else
	{
		bool a = true;
		while (a)
		{
			system("cls");
			cout << "СОЗДАНИЕ ТЕСТА ПО ГЕОМЕТРИИ:\n" << endl;
			cout << "Введите варианты ответов: " << endl;
			char* buff = new char;
			cin.getline(buff, 1200);
			an = buff;
			if (base_geo_.empty())
				tes->set_answer(an);
			else
			{
				auto it = base_geo_.begin();
				for (; it != base_geo_.end(); ++it)
				{
					if (strcmp((*it)->get_answer().c_str(), an.c_str()) != 0)
						a = true;
					else
						a = false;
				}
			}
		}
		tes->set_answer(an);
	}
	int v = 0, b = 0;
	system("cls");
	cout << "СОЗДАНИЕ ТЕСТА ПО ГЕОМЕТРИИ:\n" << endl;
	cout << "Введите номер правильного ответа: ";
	cin >> v;
	tes->set_right_answer(v);
	cout << endl;
	cout << "Введите количество балов за ответ: ";
	cin >> b;
	tes->set_balls(b);
	base_geo_.push_back(tes);
	system("cls");
	cout << "НОВЫЙ ТЕСТ по ГЕОМЕТРИИ СОЗДАН!!!" << endl;
	save_test_geo();
	print_test_geo();
}

//редактирование тестов по геометрии
void Geometry::edit_test_geo()
{
}

//сохранение промежуточного тестирования ао геометрии
void Geometry::save_media_test_geo()
{
}

//загрузка промежуточного тестирования по алгебре
void Geometry::load_media_test_geo()
{
}

//сохранение нового теста по геометрии
void Geometry::save_test_geo()
{
}

//сохранение нового теста по геометрии
void Geometry::print_test_geo() const
{
	system("cls");
	int idd;
	cout << "ПЕЧАТЬ ТЕСТА ПО НОМЕРУ:\n" << endl;
	cout << "Введите номер теста: " << endl;
	cin >> idd;
	auto it = base_geo_.begin();
	for (; it != base_geo_.end(); ++it)
	{
		if ((*it)->get_id() == idd)
			cout << (*it);
		else
			cout << "ТЕСТ с таким номер ОТСУТСТВУВЕТ!!!" << endl;
	}
	system("pause");
}
