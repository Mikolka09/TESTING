#include "Maths.h"


//меню по математике 
void Maths::menu_maths_user(string const& log)
{
	while (true)
	{

		Algebra alg;
		Geometry geo;
		Tested tes;
		tes.load_results();
		alg.load_test_alg();
		system("cls");
		cout << "БАЗА ТЕСТОВ ПО МАТЕМАТИКЕ для ПОЛЬЗОВАТЕЛЯ\n" << endl;
		cout << "КАТЕГОРИИ ТЕСТОВ ПО МАТЕМАТИКЕ:" << endl;
		cout << "1. Сдача теста по АЛГЕБРЕ\n" << "2. Сдача теста по ГЕОМЕТРИИ\n"
			<< "3. Возврат в предыдущее меню" << endl;
		int var;
		cin >> var;
		cin.ignore();
		switch (var)
		{
		case 1:
		{
			if (tes.get_base_results().empty())
				alg.passing_test_alg(log);
			else
			{
				string cat = "АЛГЕБРА";
				if ((*tes.get_base_results().find(log)).second.front()->get_cat() == cat)     //проверка есть ли в базе результатов категория по алгебре
				{
					cout << "Тест по АЛГЕБРЕ пройден, выберите другой ТЕСТ!!!" << endl;
					Sleep(2500);
				}

				else
					alg.passing_test_alg(log);
			}
			break;
		}
		case 2:
		{
			if (tes.get_base_results().empty())
				geo.passing_test_geo(log);
			else
			{
				string cat = "ГЕОМЕТРИЯ";
				if ((*tes.get_base_results().find(log)).second.front()->get_cat() == cat)    //проверка есть ли в базе результатов категория по геометрии
				{
					cout << "Тест по ГЕОМЕТРИИ пройден, выберите другой ТЕСТ!!!" << endl;
					Sleep(2500);
				}
				else
					geo.passing_test_geo(log);
			}
			break;
		}
		case 3:
			tes.new_testing(log);
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
		Admin ad;
		Algebra alg;
		Geometry geo;
		alg.load_test_alg();
		geo.load_test_geo();
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
			alg.creature_test_alg();
			break;
		case 2:
			geo.creature_test_geo();
			break;
		case 3:
			alg.edit_test_alg();
			break;
		case 4:
			geo.edit_test_geo();
			break;
		case 5:
			ad.control_tests();
			break;
		default:;
		}
	}
}


//прохождение теста по алгебре
void Algebra::passing_test_alg(string const& log)
{
	system("cls");
	cout << "СДАЧА ТЕСТОВ ПО АЛГЕБРЕ\n" << endl;
	Tested tes;
	Tests ts;
	string lg = log;
	int count_u = 0;                                     //количесвто угаданных ответов
	int bal_u = 0;                                       //количество набранных балов за тест
	auto it = base_alg_.begin();
	for (; it != base_alg_.end(); ++it)
	{
		cout << (*it);
		cout << endl;
		cout << "Введите номер ответа: ";
		int nom;
		cin >> nom;
		if ((*it)->get_right_answer() == nom)            //проверка на правильность ответа
		{
			bal_u += (*it)->get_balls();
			count_u++;
		}
	}
	Results* res = new Results;
	res->set_log(lg);
	int size = base_alg_.size();
	res->set_cat("АЛГЕБРА");
	res->set_kol_que((count_u / size) * 100);
	res->set_kol_righ_ans(count_u);
	res->set_kol_bal(bal_u);
	tes.get_res_base(res);
	system("cls");
	cout << "ТЕСТ ПРОЙДЕН!!!" << endl;
	Sleep(2500);
}

//создание теста по алгебре
void Algebra::creature_test_alg()
{
	Tests* tes = new Tests;
	tes->set_category("АЛГЕБРА");
	//print_test_alg();                     //на УДАЛЕНИЕ
	//Sleep(2500);
	int idd = 0;
	bool p = true;
	while (p)
	{
		system("cls");
		cout << "СОЗДАНИЕ ТЕСТА ПО АЛГЕБРЕ:\n" << endl;
		cout << "Введите номер теста: ";
		cin >> idd;
		if (base_alg_.empty())
		{
			tes->set_id(idd);
			p = false;
		}
		else
		{
			auto it = base_alg_.begin();
			for (; it != base_alg_.end(); ++it)
			{
				if ((*it)->get_id() == idd)
				{
					cout << "Такой номер уже занят, попробуйте другой!!!" << endl;
					Sleep(2500);
					p = true;
				}
				else
					p = false;
			}
		}
	}
	tes->set_id(idd);
	string q;
	bool w = true;
	while (w)
	{
		system("cls");
		cout << "СОЗДАНИЕ ТЕСТА ПО АЛГЕБРЕ:\n" << endl;
		cout << "Введите текст вопроса: " << endl;;
		char* str = new char;
		cin.ignore();
		cin.getline(str, 1200);
		q = str;
		if (base_alg_.empty())
		{
			tes->set_question(q);
			w = false;
		}
		else
		{
			auto it = base_alg_.begin();
			for (; it != base_alg_.end(); ++it)
			{
				string que = (*it)->get_question();
				if (que == q)
				{
					cout << "Такой вопрос уже есть, попробуйте еще раз!!!" << endl;
					Sleep(2500);
					w = true;
				}
				else
					w = false;
			}
		}
	}
	tes->set_question(q);
	string an;
	system("cls");
	cout << "СОЗДАНИЕ ТЕСТА ПО АЛГЕБРЕ:\n" << endl;
	cout << "Введите варианты ответов: " << endl;
	char* buff1 = new char;
	cin.getline(buff1, 1200);
	an = buff1;
	tes->set_answer(an);
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
	Sleep(2500);
	print_test_alg();
	save_test_alg();
}

//редактирование тестов по алгебре
void Algebra::edit_test_alg()
{
	system("cls");
	cout << "РЕДАКТИРОВАНИЕ ТЕСТА ПО АЛГЕБРЕ:\n" << endl;
	cout << "Введите номер теста: ";
	int idd = 0;
	cin >> idd;
	bool set = true;
	if (base_alg_.empty())
	{
		cout << "БАЗА ТЕСТОВ ПО АЛГЕБРЕ ПУСТА!!!" << endl;
		Sleep(2500);
	}
	else
	{
		auto it = base_alg_.begin();
		for (; it != base_alg_.end(); ++it)
		{
			if ((*it)->get_id() != idd)
			{
				cout << "Такой номер теста отсутствует!!!" << endl;
				Sleep(2500);
				set = false;
			}
			else
				set = true;
		}
	}
	if (set)
	{
		while (true)
		{
			load_test_alg();
			system("cls");
			int var;
			cout << "РЕДАКТИРОВАНИЕ ТЕСТОВ ПО АЛГЕБРЕ:\n" << endl;
			cout << "1. Редактировать ВОПРОС\n" << "2. Редактировать ОТВЕТЫ\n"
				<< "3. Редактировать НОМЕР ПРАВИЛЬНОГО ОТВЕТА\n"
				<< "4. Редактировать БАЛЛЫ\n" << "5. Возврат в предыдущее меню\n" << endl;
			cin >> var;
			cin.ignore();
			switch (var)
			{
			case 1:
			{
				system("cls");
				cout << "РЕДАКТИРОВАНИЕ ВОПРОСА:\n" << endl;
				cout << "Введите новый текст вопроса: " << endl;
				string q;
				char* buff = new char;
				cin.ignore();
				cin.getline(buff, 1200);
				q = buff;
				auto it = base_alg_.begin();
				for (; it != base_alg_.end(); ++it)
				{
					if ((*it)->get_id() == idd)
						(*it)->set_question(q);
				}
				cout << endl;
				cout << "ВОПРОС ЗАМЕНЕН!!!" << endl;
				Sleep(2500);
				save_test_alg();
				break;
			}
			case 2:
			{
				system("cls");
				cout << "РЕДАКТИРОВАНИЕ ОТВЕТОВ НА ВОПРОС:\n" << endl;
				cout << "Введите новый текст ответов: " << endl;
				string q;
				char* buff = new char;
				cin.ignore();
				cin.getline(buff, 1200);
				q = buff;
				auto it = base_alg_.begin();
				for (; it != base_alg_.end(); ++it)
				{
					if ((*it)->get_id() == idd)
						(*it)->set_answer(q);
				}
				cout << endl;
				cout << "ОТВЕТЫ ЗАМЕНЕНЫ!!!" << endl;
				Sleep(2500);
				save_test_alg();
				break;
			}
			case 3:
			{
				system("cls");
				cout << "РЕДАКТИРОВАНИЕ НОМЕРА ПРАВИЛЬНОГО ОТВЕТА:\n" << endl;
				cout << "Введите новый номер правильного ответа: " << endl;
				int an = 0;
				auto it = base_alg_.begin();
				for (; it != base_alg_.end(); ++it)
				{
					if ((*it)->get_id() == idd)
						(*it)->set_right_answer(an);
				}
				cout << endl;
				cout << "НОМЕР ПРАВИЛЬНОГО ОТВЕТА ЗАМЕНЕН!!!" << endl;
				Sleep(2500);
				save_test_alg();
				break;
			}
			case 4:
			{
				system("cls");
				cout << "РЕДАКТИРОВАНИЕ БАЛЛОВ:\n" << endl;
				cout << "Введите новое количество баллов: " << endl;
				int bl = 0;
				auto it = base_alg_.begin();
				for (; it != base_alg_.end(); ++it)
				{
					if ((*it)->get_id() == idd)
						(*it)->set_balls(bl);
				}
				cout << endl;
				cout << "БАЛЛЫ ЗАМЕНЕНЫ!!!" << endl;
				Sleep(2500);
				save_test_alg();
				break;
			}
			case 5:
				menu_maths_admin();
				break;
			default:;
			}
		}
	}
}


//сохранение тестов по алгебре
void Algebra::save_test_alg()
{
	ofstream out("BaseTestsAlgebra.bin", ios::binary | ios::out);
	int length = base_alg_.size();
	out.write(reinterpret_cast<char*>(&length), sizeof(int));
	for (int i = 0; i < length; i++)
	{
		Tests* test = base_alg_.front();
		int l_c = test->get_category().size() + 1;
		out.write(reinterpret_cast<char*>(&l_c), sizeof(int));
		out.write(const_cast<char*>(test->get_category().c_str()), l_c);
		int id = test->get_id();
		out.write(reinterpret_cast<char*>(&id), sizeof(int));
		int l_q = test->get_question().size() + 1;
		out.write(reinterpret_cast<char*>(&l_q), sizeof(int));
		out.write(const_cast<char*>(test->get_question().c_str()), l_q);
		int l_an = test->get_answer().size() + 1;
		out.write(reinterpret_cast<char*>(&l_an), sizeof(int));
		out.write(const_cast<char*>(test->get_answer().c_str()), l_an);
		int an_r = test->get_right_answer();
		out.write(reinterpret_cast<char*>(&an_r), sizeof(int));
		int bl = test->get_balls();
		out.write(reinterpret_cast<char*>(&bl), sizeof(int));
		base_alg_.pop_front();
	}
	out.close();
}

//загрузка тестов по алгебре
void Algebra::load_test_alg()
{
	ifstream in("BaseTestsAlgebra.bin", ios::binary | ios::in);
	int length = 0;
	in.read(reinterpret_cast<char*>(&length), sizeof(int));
	base_alg_.clear();
	for (int i = 0; i < length; i++)
	{
		Tests* test = new Tests;
		int l_c = 0;
		in.read(reinterpret_cast<char*>(&l_c), sizeof(int));
		char* buff = new char(l_c + 1);
		in.read(const_cast<char*>(buff), l_c);
		test->set_category(buff);
		int id = 0;
		in.read(reinterpret_cast<char*>(&id), sizeof(int));
		test->set_id(id);
		int l_q = 0;
		in.read(reinterpret_cast<char*>(&l_q), sizeof(int));
		char* buff1 = new char(l_q + 1);
		in.read(const_cast<char*>(buff1), l_q);
		test->set_question(buff1);
		int l_an = 0;
		in.read(reinterpret_cast<char*>(&l_an), sizeof(int));
		char* buff2 = new char(l_an + 1);
		in.read(const_cast<char*>(buff2), l_an);
		test->set_answer(buff2);
		int an_r = 0;
		in.read(reinterpret_cast<char*>(&an_r), sizeof(int));
		test->set_right_answer(an_r);
		int bl = 0;
		in.read(reinterpret_cast<char*>(&bl), sizeof(int));
		test->set_balls(bl);

		base_alg_.push_back(test);
	}
	in.close();
}

//печать на экран теста по алгебре
void Algebra::print_test_alg() const
{
	system("cls");
	int idd = 0;
	cout << "ПЕЧАТЬ ТЕСТА ПО НОМЕРУ:\n" << endl;
	cout << "Введите номер теста: ";
	cin >> idd;
	auto it = base_alg_.begin();
	for (; it != base_alg_.end(); ++it)
	{
		if ((*it)->get_id() == idd)
			cout << (*it);
		else
			cout << "ТЕСТ с таким номер ОТСУТСТВУЕТ!!!" << endl;
	}
	system("pause");
}


//прохождение теста по геометрии
void Geometry::passing_test_geo(string const& log)
{
}

//создание теста по геометрии
void Geometry::creature_test_geo()
{
	Tests* tes = new Tests;
	tes->set_category("ГЕОМЕТРИЯ");
	int idd = 0;
	bool p = true;
	while (p)
	{
		system("cls");
		cout << "СОЗДАНИЕ ТЕСТА ПО ГЕОМЕТРИИ:\n" << endl;
		cout << "Введите номер теста: ";
		cin >> idd;
		if (base_geo_.empty())
		{
			tes->set_id(idd);
			p = false;
		}
		else
		{
			auto it = base_geo_.begin();
			for (; it != base_geo_.end(); ++it)
			{
				if ((*it)->get_id() == idd)
				{
					cout << "Такой номер уже занят, попробуйте другой!!!" << endl;
					Sleep(2500);
					p = true;
				}
				else
					p = false;
			}
		}
	}
	tes->set_id(idd);
	string q;
	bool w = true;
	while (w)
	{
		system("cls");
		cout << "СОЗДАНИЕ ТЕСТА ПО ГЕОМЕТРИИ:\n" << endl;
		cout << "Введите текст вопроса: " << endl;;
		char* buff = new char;
		cin.getline(buff, 1200);
		q = buff;
		if (base_geo_.empty())
		{
			tes->set_question(q);
			w = false;
		}
		else
		{
			auto it = base_geo_.begin();
			for (; it != base_geo_.end(); ++it)
			{
				string que = (*it)->get_question();
				if (que == q)
				{
					cout << "Такой вопрос уже есть, попробуйте еще раз!!!" << endl;
					Sleep(2500);
					w = true;
				}
				else
					w = false;
			}
		}
	}
	tes->set_question(q);
	string an;
	system("cls");
	cout << "СОЗДАНИЕ ТЕСТА ПО ГЕОМЕТРИИ:\n" << endl;
	cout << "Введите варианты ответов: " << endl;
	char* buff1 = new char;
	cin.getline(buff1, 1200);
	an = buff1;
	tes->set_answer(an);
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
	Sleep(2500);
	print_test_geo();
	save_test_geo();

}

//редактирование тестов по геометрии
void Geometry::edit_test_geo()
{
	system("cls");
	cout << "РЕДАКТИРОВАНИЕ ТЕСТА ПО ГЕОМЕТРИИ:\n" << endl;
	cout << "Введите номер теста: ";
	int idd = 0;
	cin >> idd;
	bool set = true;
	if (base_geo_.empty())
	{
		cout << "БАЗА ТЕСТОВ ПО ГЕОМЕТРИИ ПУСТА!!!" << endl;
		Sleep(2500);
	}
	else
	{
		auto it = base_geo_.begin();
		for (; it != base_geo_.end(); ++it)
		{
			if ((*it)->get_id() != idd)
			{
				cout << "Такой номер теста отсутствует!!!" << endl;
				Sleep(2500);
				set = false;
			}
			else
				set = true;
		}
	}
	if (set)
	{
		while (true)
		{
			load_test_geo();
			system("cls");
			int var;
			cout << "РЕДАКТИРОВАНИЕ ТЕСТОВ ПО ГЕОМЕТРИИ:\n" << endl;
			cout << "1. Редактировать ВОПРОС\n" << "2. Редактировать ОТВЕТЫ\n"
				<< "3. Редактировать НОМЕР ПРАВИЛЬНОГО ОТВЕТА\n"
				<< "4. Редактировать БАЛЛЫ\n" << "5. Возврат в предыдущее меню\n" << endl;
			cin >> var;
			cin.ignore();
			switch (var)
			{
			case 1:
			{
				system("cls");
				cout << "РЕДАКТИРОВАНИЕ ВОПРОСА:\n" << endl;
				cout << "Введите новый текст вопроса: " << endl;
				string q;
				char* buff = new char;
				cin.ignore();
				cin.getline(buff, 1200);
				q = buff;
				auto it = base_geo_.begin();
				for (; it != base_geo_.end(); ++it)
				{
					if ((*it)->get_id() == idd)
						(*it)->set_question(q);
				}
				cout << endl;
				cout << "ВОПРОС ЗАМЕНЕН!!!" << endl;
				Sleep(2500);
				save_test_geo();
				break;
			}
			case 2:
			{
				system("cls");
				cout << "РЕДАКТИРОВАНИЕ ОТВЕТОВ НА ВОПРОС:\n" << endl;
				cout << "Введите новый текст ответов: " << endl;
				string q;
				char* buff = new char;
				cin.ignore();
				cin.getline(buff, 1200);
				q = buff;
				auto it = base_geo_.begin();
				for (; it != base_geo_.end(); ++it)
				{
					if ((*it)->get_id() == idd)
						(*it)->set_answer(q);
				}
				cout << endl;
				cout << "ОТВЕТЫ ЗАМЕНЕНЫ!!!" << endl;
				Sleep(2500);
				save_test_geo();
				break;
			}
			case 3:
			{
				system("cls");
				cout << "РЕДАКТИРОВАНИЕ НОМЕРА ПРАВИЛЬНОГО ОТВЕТА:\n" << endl;
				cout << "Введите новый номер правильного ответа: " << endl;
				int an = 0;
				auto it = base_geo_.begin();
				for (; it != base_geo_.end(); ++it)
				{
					if ((*it)->get_id() == idd)
						(*it)->set_right_answer(an);
				}
				cout << endl;
				cout << "НОМЕР ПРАВИЛЬНОГО ОТВЕТА ЗАМЕНЕН!!!" << endl;
				Sleep(2500);
				save_test_geo();
				break;
			}
			case 4:
			{
				system("cls");
				cout << "РЕДАКТИРОВАНИЕ БАЛЛОВ:\n" << endl;
				cout << "Введите новое количество баллов: " << endl;
				int bl = 0;
				auto it = base_geo_.begin();
				for (; it != base_geo_.end(); ++it)
				{
					if ((*it)->get_id() == idd)
						(*it)->set_balls(bl);
				}
				cout << endl;
				cout << "БАЛЛЫ ЗАМЕНЕНЫ!!!" << endl;
				Sleep(2500);
				save_test_geo();
				break;
			}
			case 5:
				menu_maths_admin();
				break;
			default:;
			}
		}
	}
}


//сохранение тестов по геометрии
void Geometry::save_test_geo()
{
	ofstream out("BaseTestsGeometry.bin", ios::binary | ios::out);
	int length = base_geo_.size();
	out.write(reinterpret_cast<char*>(&length), sizeof(int));
	for (int i = 0; i < length; i++)
	{
		Tests* test = base_geo_.front();
		int l_c = test->get_category().size() + 1;
		out.write(reinterpret_cast<char*>(&l_c), sizeof(int));
		out.write(const_cast<char*>(test->get_category().c_str()), l_c);
		int id = test->get_id();
		out.write(reinterpret_cast<char*>(&id), sizeof(int));
		int l_q = test->get_question().size() + 1;
		out.write(reinterpret_cast<char*>(&l_q), sizeof(int));
		out.write(const_cast<char*>(test->get_question().c_str()), l_q);
		int l_an = test->get_answer().size() + 1;
		out.write(reinterpret_cast<char*>(&l_an), sizeof(int));
		out.write(const_cast<char*>(test->get_answer().c_str()), l_an);
		int an_r = test->get_right_answer();
		out.write(reinterpret_cast<char*>(&an_r), sizeof(int));
		int bl = test->get_balls();
		out.write(reinterpret_cast<char*>(&bl), sizeof(int));
		base_geo_.pop_front();
	}
	out.close();
}

//загрузка тестов по геометрии
void Geometry::load_test_geo()
{
	ifstream in("BaseTestsGeometry.bin", ios::binary | ios::in);
	int length = 0;
	in.read(reinterpret_cast<char*>(&length), sizeof(int));
	base_geo_.clear();
	for (int i = 0; i < length; i++)
	{
		Tests* test = new Tests;
		int l_c = 0;
		in.read(reinterpret_cast<char*>(&l_c), sizeof(int));
		char* buff = new char(l_c + 1);
		in.read(const_cast<char*>(buff), l_c);
		test->set_category(buff);
		int id = 0;
		in.read(reinterpret_cast<char*>(&id), sizeof(int));
		test->set_id(id);
		int l_q = 0;
		in.read(reinterpret_cast<char*>(&l_q), sizeof(int));
		char* buff1 = new char(l_q + 1);
		in.read(const_cast<char*>(buff1), l_q);
		test->set_question(buff1);
		int l_an = 0;
		in.read(reinterpret_cast<char*>(&l_an), sizeof(int));
		char* buff2 = new char(l_an + 1);
		in.read(const_cast<char*>(buff2), l_an);
		test->set_answer(buff2);
		int an_r = 0;
		in.read(reinterpret_cast<char*>(&an_r), sizeof(int));
		test->set_right_answer(an_r);
		int bl = 0;
		in.read(reinterpret_cast<char*>(&bl), sizeof(int));
		test->set_balls(bl);

		base_geo_.push_back(test);
	}
	in.close();
}

//сохранение нового теста по геометрии
void Geometry::print_test_geo() const
{
	system("cls");
	int idd = 0;
	cout << "ПЕЧАТЬ ТЕСТА ПО НОМЕРУ:\n" << endl;
	cout << "Введите номер теста: ";
	cin >> idd;
	auto it = base_geo_.begin();
	for (; it != base_geo_.end(); ++it)
	{
		if ((*it)->get_id() == idd)
			cout << (*it);
		else
			cout << "ТЕСТ с таким номер ОТСУТСТВУЕТ!!!" << endl;
	}
	system("pause");
}
