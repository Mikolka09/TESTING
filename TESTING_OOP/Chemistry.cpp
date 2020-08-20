#include "Chemistry.h"

void Chemistry::shapka_start(string const& log)
{
	string S(40, '#');
	gotoxy(30, 1);
	SetColor(8, 0);
	cout << S << endl;
	gotoxy(37, 2);
	SetColor(12, 0);
	cout << "ТЕСТОВАЯ БАЗА ТЕСТИРОВАНИЙ" << endl;
	gotoxy(8, 2);
	SetColor(10, 0);
	cout << "ЛОГИН: " << log;
	gotoxy(30, 3);
	SetColor(8, 0);
	cout << S << endl << endl;
}

//меню по химии
void Chemistry::menu_chem_user(string const& log)
{
	while (true)
	{

		Organic org;
		Inorganic in;
		Tested tes;
		tes.load_results();
		org.load_test_or();
		system("cls");
		shapka_start(log);
		SetColor(12, 0);
		cout << "БАЗА ТЕСТОВ ПО ХИМИИ для ПОЛЬЗОВАТЕЛЯ\n" << endl;
		SetColor(14, 0);
		cout << "КАТЕГОРИИ ТЕСТОВ ПО ХИМИИ:" << endl;
		cout << "1. Сдача теста по ОРГАНИЧЕСКОЙ\n" << "2. Сдача теста по НЕОРГАНИЧЕСКОЙ\n"
			<< "3. Возврат в предыдущее меню" << endl;
		int var;
		bool v = true;
		while (v)
		{
			SetColor(15, 0);
			cin >> var;
			cin.ignore();
			if (var < 1 || var > 3)    // проверка ввода
			{
				SetColor(12, 0);
				cout << "НЕВЕРНО!!! ПОПРОБУЙТЕ ЕЩЕ РАЗ!!!" << endl;
				SetColor(15, 0);
			}
			else
				v = false;
		}
		switch (var)
		{
		case 1:
		{
			if (tes.get_base_results().empty())
				org.passing_test_or(log);
			else
			{
				//string cat = "АЛГЕБРА";
				if ((*tes.get_base_results().find(log)).second.front()->get_cat() == org.cat_or_)     //проверка есть ли в базе результатов категории
				{
					SetColor(12, 0);
					cout << "Тест по ОРГАНИЧЕСКОЙ пройден, выберите другой ТЕСТ!!!" << endl;
					Sleep(2500);
					SetColor(15, 0);
				}

				else
					org.passing_test_or(log);
			}
			break;
		}
		case 2:
		{
			if (tes.get_base_results().empty())
				in.passing_test_in(log);
			else
			{
				//string cat = "ГЕОМЕТРИЯ";
				if ((*tes.get_base_results().find(log)).second.front()->get_cat() == in.cat_in_)    //проверка есть ли в базе результатов категории
				{
					SetColor(12, 0);
					cout << "Тест по НЕОРГАНИЧЕСКОЙ пройден, выберите другой ТЕСТ!!!" << endl;
					Sleep(2500);
					SetColor(15, 0);
				}
				else
					in.passing_test_in(log);
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


//меню по химии для администратора
void Chemistry::menu_chem_admin()
{
	while (true)
	{
		Admin ad;
		Organic org;
		Inorganic in;
		org.load_test_or();
		in.load_test_in();
		system("cls");
		SetColor(12, 0);
		cout << "БАЗА ТЕСТОВ ПО ХИМИИ для АДМИНИСТРАТОРА\n" << endl;
		SetColor(14, 0);
		cout << "МЕНЮ ДЕЙСТВИЙ:" << endl;
		cout << "1. Создание тестов по ОРГАНИЧЕСКОЙ\n" << "2. Создание тестов по НЕОРГАНИЧЕСКОЙ\n"
			<< "3. Редактирование тестов по ОРГАНИЧЕСКОЙ\n" << "4. Редактирование тестов по НЕОРГАНИЧЕСКОЙ\n"
			<< "5. Печать на экран тестов по ОРГАНИЧЕСКОЙ\n" << "6. Печать на экран тестов по НЕОРГАНИЧЕСКОЙ\n"
			<< "7. Возврат в предыдущее меню" << endl;
		int var;
		bool v = true;
		while (v)
		{
			SetColor(15, 0);
			cin >> var;
			cin.ignore();
			if (var < 1 || var > 7)    // проверка ввода
			{
				SetColor(12, 0);
				cout << "НЕВЕРНО!!! ПОПРОБУЙТЕ ЕЩЕ РАЗ!!!" << endl;
				SetColor(15, 0);
			}
			else
				v = false;
		}
		switch (var)
		{
		case 1:
			org.creature_test_or();
			break;
		case 2:
			in.creature_test_in();
			break;
		case 3:
			org.edit_test_or();
			break;
		case 4:
			in.edit_test_in();
			break;
		case 5:
			org.print_test_all_or();
			break;
		case 6:
			in.print_test_all_in();
			break;
		case 7:
			ad.control_tests();
			break;
		default:;
		}
	}
}


Organic::Organic(const Organic& ob)
{
	cat_or_ = ob.cat_or_;
	list<Tests*> t;
	t = ob.base_or_;
	base_or_ = t;
}

Organic& Organic::operator=(const Organic& ob)
{
	cat_or_ = ob.cat_or_;
	list<Tests*> t;
	t = ob.base_or_;
	base_or_ = t;
	return *this;
}

//прохождение теста по органической
void Organic::passing_test_or(string const& log)
{
	system("cls");
	gotoxy(4, 4);
	SetColor(12, 0);
	cout << "СДАЧА ТЕСТОВ ПО ОРГАНИЧЕСКОЙ\n" << endl;
	SetColor(15, 0);
	Tested tes;
	Tests ts;
	string lg = log;
	int count_u = 0;                                     //количесвто угаданных ответов
	int bal_u = 0;                                       //количество набранных балов за тест
	auto it = base_or_.begin();
	for (; it != base_or_.end(); ++it)
	{
		system("cls");
		cout << (*it);
		cout << endl;
		SetColor(14, 0);
		cout << "Введите номер ответа: ";
		SetColor(15, 0);
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
	int size = base_or_.size();
	res->set_cat(cat_or_);
	res->set_kol_que((count_u / size) * 100);
	res->set_kol_righ_ans(count_u);
	res->set_kol_bal(bal_u);
	tes.get_res_base(res);
	system("cls");
	gotoxy(10, 10);
	SetColor(12, 0);
	cout << "ТЕСТ ПРОЙДЕН!!!" << endl;
	Sleep(2500);
	SetColor(15, 0);
}

//создание теста по органической
void Organic::creature_test_or()
{
	Tests* tes = new Tests;
	tes->set_category(cat_or_);
	//print_test_alg();                     //на УДАЛЕНИЕ
	//Sleep(2500);
	int idd = 0;
	bool p = true;
	while (p)
	{
		system("cls");
		SetColor(12, 0);
		cout << "СОЗДАНИЕ ТЕСТА ПО ОРГАНИЧЕСКОЙ:\n" << endl;
		SetColor(14, 0);
		cout << "Введите номер теста: ";
		SetColor(15, 0);
		cin >> idd;
		if (base_or_.empty())
		{
			tes->set_id(idd);
			p = false;
		}
		else
		{
			auto it = base_or_.begin();
			for (; it != base_or_.end(); ++it)
			{
				if ((*it)->get_id() == idd)
				{
					SetColor(12, 0);
					cout << "Такой номер уже занят, попробуйте другой!!!" << endl;
					Sleep(2500);
					SetColor(15, 0);
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
		SetColor(12, 0);
		cout << "СОЗДАНИЕ ТЕСТА ПО ОРГАНИЧЕСКОЙ:\n" << endl;
		SetColor(14, 0);
		cout << "Введите текст вопроса: " << endl;
		SetColor(15, 0);
		char* str = new char;
		cin.ignore();
		cin.getline(str, 1200);
		q = str;
		if (base_or_.empty())
		{
			tes->set_question(q);
			w = false;
		}
		else
		{
			auto it = base_or_.begin();
			for (; it != base_or_.end(); ++it)
			{
				string que = (*it)->get_question();
				if (que == q)
				{
					SetColor(12, 0);
					cout << "Такой вопрос уже есть, попробуйте еще раз!!!" << endl;
					Sleep(2500);
					SetColor(15, 0);
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
	SetColor(12, 0);
	cout << "СОЗДАНИЕ ТЕСТА ПО ОРГАНИЧЕСКОЙ:\n" << endl;
	SetColor(14, 0);
	cout << "Введите варианты ответов через пробел: " << endl;
	SetColor(15, 0);
	char* buff1 = new char;
	cin.getline(buff1, 1200);
	an = buff1;
	tes->set_answer(an);
	int v = 0, b = 0;
	system("cls");
	SetColor(12, 0);
	cout << "СОЗДАНИЕ ТЕСТА ПО ОРГАНИЧЕСКОЙ:\n" << endl;
	SetColor(14, 0);
	cout << "Введите номер правильного ответа: ";
	SetColor(15, 0);
	cin >> v;
	tes->set_right_answer(v);
	cout << endl;
	SetColor(14, 0);
	cout << "Введите количество балов за ответ: ";
	SetColor(15, 0);
	cin >> b;
	tes->set_balls(b);
	base_or_.push_back(tes);
	system("cls");
	gotoxy(10, 10);
	SetColor(12, 0);
	cout << "НОВЫЙ ТЕСТ по АЛГЕБРЕ СОЗДАН!!!" << endl;
	SetColor(15, 0);
	Sleep(2500);
	print_test_or();
	save_test_or();
}

//редактирование тестов по органической
void Organic::edit_test_or()
{
	system("cls");
	SetColor(12, 0);
	cout << "РЕДАКТИРОВАНИЕ ТЕСТА ПО ОРГАНИЧЕСКОЙ:\n" << endl;
	SetColor(14, 0);
	cout << "Введите номер теста: ";
	SetColor(15, 0);
	int idd = 0;
	cin >> idd;
	bool set = true;
	if (base_or_.empty())
	{
		SetColor(12, 0);
		cout << "БАЗА ТЕСТОВ ПО ОРГАНИЧЕСКОЙ ПУСТА!!!" << endl;
		SetColor(15, 0);
		Sleep(2500);
	}
	else
	{
		auto it = base_or_.begin();
		for (; it != base_or_.end(); ++it)
		{
			if ((*it)->get_id() != idd)
			{
				SetColor(12, 0);
				cout << "Такой номер теста отсутствует!!!" << endl;
				SetColor(15, 0);
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
			load_test_or();
			system("cls");
			int var;
			SetColor(12, 0);
			cout << "РЕДАКТИРОВАНИЕ ТЕСТОВ ПО ОРГАНИЧЕСКОЙ:\n" << endl;
			SetColor(14, 0);
			cout << "1. Редактировать ВОПРОС\n" << "2. Редактировать ОТВЕТЫ\n"
				<< "3. Редактировать НОМЕР ПРАВИЛЬНОГО ОТВЕТА\n"
				<< "4. Редактировать БАЛЛЫ\n" << "5. Возврат в предыдущее меню\n" << endl;
			bool v = true;
			while (v)
			{
				SetColor(15, 0);
				cin >> var;
				cin.ignore();
				if (var < 1 || var > 5)    // проверка ввода
				{
					SetColor(12, 0);
					cout << "НЕВЕРНО!!! ПОПРОБУЙТЕ ЕЩЕ РАЗ!!!" << endl;
					SetColor(15, 0);
				}
				else
					v = false;
			}
			switch (var)
			{
			case 1:
			{
				system("cls");
				SetColor(12, 0);
				cout << "РЕДАКТИРОВАНИЕ ВОПРОСА:\n" << endl;
				SetColor(14, 0);
				cout << "Введите новый текст вопроса: " << endl;
				SetColor(15, 0);
				string q;
				char* buff = new char;
				cin.ignore();
				cin.getline(buff, 1200);
				q = buff;
				auto it = base_or_.begin();
				for (; it != base_or_.end(); ++it)
				{
					if ((*it)->get_id() == idd)
						(*it)->set_question(q);
				}
				cout << endl;
				SetColor(12, 0);
				cout << "\nВОПРОС ЗАМЕНЕН!!!" << endl;
				SetColor(15, 0);
				Sleep(2500);
				save_test_or();
				break;
			}
			case 2:
			{
				system("cls");
				SetColor(12, 0);
				cout << "РЕДАКТИРОВАНИЕ ОТВЕТОВ НА ВОПРОС:\n" << endl;
				SetColor(14, 0);
				cout << "Введите новый текст ответов через пробел: " << endl;
				SetColor(15, 0);
				string q;
				char* buff = new char;
				cin.ignore();
				cin.getline(buff, 1200);
				q = buff;
				auto it = base_or_.begin();
				for (; it != base_or_.end(); ++it)
				{
					if ((*it)->get_id() == idd)
						(*it)->set_answer(q);
				}
				cout << endl;
				SetColor(12, 0);
				cout << "\nОТВЕТЫ ЗАМЕНЕНЫ!!!" << endl;
				SetColor(15, 0);
				Sleep(2500);
				save_test_or();
				break;
			}
			case 3:
			{
				system("cls");
				SetColor(12, 0);
				cout << "РЕДАКТИРОВАНИЕ НОМЕРА ПРАВИЛЬНОГО ОТВЕТА:\n" << endl;
				SetColor(14, 0);
				cout << "Введите новый номер правильного ответа: " << endl;
				SetColor(15, 0);
				int an = 0;
				cin >> an;
				auto it = base_or_.begin();
				for (; it != base_or_.end(); ++it)
				{
					if ((*it)->get_id() == idd)
						(*it)->set_right_answer(an);
				}
				cout << endl;
				SetColor(12, 0);
				cout << "\nНОМЕР ПРАВИЛЬНОГО ОТВЕТА ЗАМЕНЕН!!!" << endl;
				SetColor(15, 0);
				Sleep(2500);
				save_test_or();
				break;
			}
			case 4:
			{
				system("cls");
				SetColor(12, 0);
				cout << "РЕДАКТИРОВАНИЕ БАЛЛОВ:\n" << endl;
				SetColor(14, 0);
				cout << "Введите новое количество баллов: " << endl;
				SetColor(15, 0);
				int bl = 0;
				cin >> bl;
				auto it = base_or_.begin();
				for (; it != base_or_.end(); ++it)
				{
					if ((*it)->get_id() == idd)
						(*it)->set_balls(bl);
				}
				cout << endl;
				SetColor(12, 0);
				cout << "\nБАЛЛЫ ЗАМЕНЕНЫ!!!" << endl;
				SetColor(15, 0);
				Sleep(2500);
				save_test_or();
				break;
			}
			case 5:
				menu_chem_admin();
				break;
			default:;
			}
		}
	}
}


//сохранение тестов по органической
void Organic::save_test_or()
{
	ofstream out("BaseTestsOrganic.txt", ios::out);
	Tests* tes = new Tests;
	while (true)
	{
		tes = base_or_.front();
		out << "\n";
		out << tes->get_category() << endl;
		out << tes->get_id() << endl;
		out << tes->get_question() << endl;
		out << tes->get_answer() << endl;
		out << tes->get_right_answer() << endl;
		out << tes->get_balls() << endl;
		base_or_.pop_front();
		if (base_or_.empty())
			break;
	}
	delete tes;
	out.close();

	/*ofstream out("BaseTestsAlgebra.bin", ios::binary | ios::out);
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
	out.close();*/
}

//загрузка тестов по алгебре
void Organic::load_test_or()
{
	ifstream in("BaseTestsOrganic.txt", ios::in);
	base_or_.clear();
	if (in.is_open())
	{
		while (true)
		{
			Tests* tes = new Tests;
			char lc[50];
			in >> lc;
			char* buff = new char[strlen(lc) + 1];
			strcpy(buff, lc);
			tes->set_category(buff);
			int id;
			in >> id;
			in.get();
			tes->set_id(id);
			char lq[1000];
			in.getline(lq, 1000);
			char* buff1 = new char[strlen(lq) + 1];
			strcpy(buff1, lq);
			tes->set_question(buff1);
			char la[1000];
			in.getline(la, 1000);
			char* buff2 = new char[strlen(la) + 1];
			strcpy(buff2, la);
			tes->set_question(buff2);
			int ra;
			in >> ra;
			in.get();
			tes->set_id(ra);
			int b;
			in >> b;
			in.get();
			tes->set_id(b);
			base_or_.push_back(tes);
			in.get();
			if (in.eof())
				break;
		}
	}
	in.close();


	/*ifstream in("BaseTestsAlgebra.bin", ios::binary | ios::in);
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
	in.close();*/
}

//печать на экран теста по органической
void Organic::print_test_or() const
{
	system("cls");
	int idd = 0;
	SetColor(12, 0);
	cout << "ПЕЧАТЬ ТЕСТА ПО НОМЕРУ:\n" << endl;
	SetColor(14, 0);
	cout << "Введите номер теста: ";
	SetColor(15, 0);
	cin >> idd;
	auto it = base_or_.begin();
	system("cls");
	SetColor(12, 0);
	cout << "ПЕЧАТЬ ТЕСТА ПО НОМЕРУ:\n" << endl;
	SetColor(15, 0);
	for (; it != base_or_.end(); ++it)
	{
		if ((*it)->get_id() == idd)
			cout << (*it);
		else
		{
			SetColor(12, 0);
			cout << "\nТЕСТ с таким номер ОТСУТСТВУЕТ!!!" << endl;
			Sleep(2500);
		}
	}
	system("pause");
}

//печать на экран всех тестов по органической
void Organic::print_test_all_or() const
{
	system("cls");
	int idd = 0;
	auto it = base_or_.begin();
	system("cls");
	SetColor(12, 0);
	cout << "ПЕЧАТЬ ВСЕХ ТЕСТОВ ПО ОРГАНИЧЕСКОЙ:\n" << endl;
	SetColor(15, 0);
	for (; it != base_or_.end(); ++it)
	{
		cout << (*it);

	}
	system("pause");
}


Inorganic::Inorganic(const Inorganic& ob)
{
	cat_in_ = ob.cat_in_;
	list<Tests*> t;
	t = ob.base_in_;
	base_in_ = t;
}

Inorganic& Inorganic::operator=(const Inorganic& ob)
{
	cat_in_ = ob.cat_in_;
	list<Tests*> t;
	t = ob.base_in_;
	base_in_ = t;
	return *this;
}

//прохождение теста по неорганической
void Inorganic::passing_test_in(string const& log)
{
	system("cls");
	SetColor(12, 0);
	cout << "СДАЧА ТЕСТОВ ПО НЕОРГАНИЧЕСКОЙ\n" << endl;
	SetColor(15, 0);
	Tested tes;
	Tests ts;
	string lg = log;
	int count_u = 0;                                     //количесвто угаданных ответов
	int bal_u = 0;                                       //количество набранных балов за тест
	auto it = base_in_.begin();
	for (; it != base_in_.end(); ++it)
	{
		system("cls");
		cout << (*it);
		cout << endl;
		SetColor(14, 0);
		cout << "Введите номер ответа: ";
		SetColor(15, 0);
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
	int size = base_in_.size();
	res->set_cat(cat_in_);
	res->set_kol_que((count_u / size) * 100);
	res->set_kol_righ_ans(count_u);
	res->set_kol_bal(bal_u);
	tes.get_res_base(res);
	system("cls");
	gotoxy(10, 10);
	SetColor(12, 0);
	cout << "ТЕСТ ПРОЙДЕН!!!" << endl;
	SetColor(15, 0);
	Sleep(2500);
}

//создание теста по геометрии
void Inorganic::creature_test_in()
{
	Tests* tes = new Tests;
	tes->set_category(cat_in_);
	int idd = 0;
	bool p = true;
	while (p)
	{
		system("cls");
		SetColor(12, 0);
		cout << "СОЗДАНИЕ ТЕСТА ПО НЕОРГАНИЧЕСКОЙ:\n" << endl;
		SetColor(14, 0);
		cout << "Введите номер теста: ";
		SetColor(15, 0);
		cin >> idd;
		if (base_in_.empty())
		{
			tes->set_id(idd);
			p = false;
		}
		else
		{
			auto it = base_in_.begin();
			for (; it != base_in_.end(); ++it)
			{
				if ((*it)->get_id() == idd)
				{
					SetColor(12, 0);
					cout << "\nТакой номер уже занят, попробуйте другой!!!" << endl;
					SetColor(15, 0);
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
		SetColor(12, 0);
		cout << "СОЗДАНИЕ ТЕСТА ПО НЕОРГАНИЧЕСКОЙ:\n" << endl;
		SetColor(14, 0);
		cout << "Введите текст вопроса: " << endl;
		SetColor(15, 0);
		char* buff = new char;
		cin.getline(buff, 1200);
		q = buff;
		if (base_in_.empty())
		{
			tes->set_question(q);
			w = false;
		}
		else
		{
			auto it = base_in_.begin();
			for (; it != base_in_.end(); ++it)
			{
				string que = (*it)->get_question();
				if (que == q)
				{
					SetColor(12, 0);
					cout << "Такой вопрос уже есть, попробуйте еще раз!!!" << endl;
					SetColor(15, 0);
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
	SetColor(12, 0);
	cout << "СОЗДАНИЕ ТЕСТА ПО НЕОРГАНИЧЕСКОЙ:\n" << endl;
	SetColor(14, 0);
	cout << "Введите варианты ответов через пробел: " << endl;
	SetColor(15, 0);
	char* buff1 = new char;
	cin.getline(buff1, 1200);
	an = buff1;
	tes->set_answer(an);
	int v = 0, b = 0;
	system("cls");
	SetColor(12, 0);
	cout << "СОЗДАНИЕ ТЕСТА ПО НЕОРГАНИЧЕСКОЙ:\n" << endl;
	SetColor(16, 0);
	cout << "Введите номер правильного ответа: ";
	SetColor(15, 0);
	cin >> v;
	tes->set_right_answer(v);
	cout << endl;
	SetColor(14, 0);
	cout << "Введите количество балов за ответ: ";
	SetColor(15, 0);
	cin >> b;
	tes->set_balls(b);
	base_in_.push_back(tes);
	system("cls");
	SetColor(12, 0);
	gotoxy(10, 10);
	cout << "НОВЫЙ ТЕСТ по ГЕОМЕТРИИ СОЗДАН!!!" << endl;
	SetColor(15, 0);
	Sleep(2500);
	print_test_in();
	save_test_in();

}

//редактирование тестов по неорганической
void Inorganic::edit_test_in()
{
	system("cls");
	SetColor(12, 0);
	cout << "РЕДАКТИРОВАНИЕ ТЕСТА ПО НЕОРГАНИЧЕСКОЙ:\n" << endl;
	SetColor(14, 0);
	cout << "Введите номер теста: ";
	SetColor(5, 0);
	int idd = 0;
	cin >> idd;
	bool set = true;
	if (base_in_.empty())
	{
		SetColor(12, 0);
		cout << "БАЗА ТЕСТОВ ПО НЕОРГАНИЧЕСКОЙ ПУСТА!!!" << endl;
		SetColor(15, 0);
		Sleep(2500);
	}
	else
	{
		auto it = base_in_.begin();
		for (; it != base_in_.end(); ++it)
		{
			if ((*it)->get_id() != idd)
			{
				SetColor(12, 0);
				cout << "Такой номер теста отсутствует!!!" << endl;
				SetColor(15, 0);
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
			load_test_in();
			system("cls");
			int var;
			SetColor(12, 0);
			cout << "РЕДАКТИРОВАНИЕ ТЕСТОВ ПО НЕОРГАНИЧЕСКОЙ:\n" << endl;
			SetColor(14, 0);
			cout << "1. Редактировать ВОПРОС\n" << "2. Редактировать ОТВЕТЫ\n"
				<< "3. Редактировать НОМЕР ПРАВИЛЬНОГО ОТВЕТА\n"
				<< "4. Редактировать БАЛЛЫ\n" << "5. Возврат в предыдущее меню\n" << endl;
			bool v = true;
			while (v)
			{
				SetColor(15, 0);
				cin >> var;
				cin.ignore();
				if (var < 1 || var > 5)    // проверка ввода
				{
					SetColor(12, 0);
					cout << "НЕВЕРНО!!! ПОПРОБУЙТЕ ЕЩЕ РАЗ!!!" << endl;
					SetColor(15, 0);
				}
				else
					v = false;
			}
			switch (var)
			{
			case 1:
			{
				system("cls");
				SetColor(12, 0);
				cout << "РЕДАКТИРОВАНИЕ ВОПРОСА:\n" << endl;
				SetColor(14, 0);
				cout << "Введите новый текст вопроса: " << endl;
				SetColor(15, 0);
				string q;
				char* buff = new char;
				cin.ignore();
				cin.getline(buff, 1200);
				q = buff;
				auto it = base_in_.begin();
				for (; it != base_in_.end(); ++it)
				{
					if ((*it)->get_id() == idd)
						(*it)->set_question(q);
				}
				cout << endl;
				SetColor(12, 0);
				cout << "\nВОПРОС ЗАМЕНЕН!!!" << endl;
				SetColor(14, 0);
				Sleep(2500);
				save_test_in();
				break;
			}
			case 2:
			{
				system("cls");
				SetColor(12, 0);
				cout << "РЕДАКТИРОВАНИЕ ОТВЕТОВ НА ВОПРОС:\n" << endl;
				SetColor(14, 0);
				cout << "Введите новый текст ответов через пробел: " << endl;
				SetColor(15, 0);
				string q;
				char* buff = new char;
				cin.ignore();
				cin.getline(buff, 1200);
				q = buff;
				auto it = base_in_.begin();
				for (; it != base_in_.end(); ++it)
				{
					if ((*it)->get_id() == idd)
						(*it)->set_answer(q);
				}
				cout << endl;
				SetColor(12, 0);
				cout << "\nОТВЕТЫ ЗАМЕНЕНЫ!!!" << endl;
				SetColor(15, 0);
				Sleep(2500);
				save_test_in();
				break;
			}
			case 3:
			{
				system("cls");
				SetColor(12, 0);
				cout << "РЕДАКТИРОВАНИЕ НОМЕРА ПРАВИЛЬНОГО ОТВЕТА:\n" << endl;
				SetColor(14, 0);
				cout << "Введите новый номер правильного ответа: " << endl;
				SetColor(15, 0);
				int an = 0;
				cin >> an;
				auto it = base_in_.begin();
				for (; it != base_in_.end(); ++it)
				{
					if ((*it)->get_id() == idd)
						(*it)->set_right_answer(an);
				}
				cout << endl;
				SetColor(12, 0);
				cout << "\nНОМЕР ПРАВИЛЬНОГО ОТВЕТА ЗАМЕНЕН!!!" << endl;
				SetColor(15, 0);
				Sleep(2500);
				save_test_in();
				break;
			}
			case 4:
			{
				system("cls");
				SetColor(12, 0);
				cout << "РЕДАКТИРОВАНИЕ БАЛЛОВ:\n" << endl;
				SetColor(14, 0);
				cout << "Введите новое количество баллов: " << endl;
				SetColor(15, 0);
				int bl = 0;
				cin >> bl;
				auto it = base_in_.begin();
				for (; it != base_in_.end(); ++it)
				{
					if ((*it)->get_id() == idd)
						(*it)->set_balls(bl);
				}
				cout << endl;
				SetColor(12, 0);
				cout << "\nБАЛЛЫ ЗАМЕНЕНЫ!!!" << endl;
				SetColor(15, 0);
				Sleep(2500);
				save_test_in();
				break;
			}
			case 5:
				menu_chem_admin();
				break;
			default:;
			}
		}
	}
}


//сохранение тестов по неорганической
void Inorganic::save_test_in()
{
	ofstream out("BaseTestsInorganic.txt", ios::out);
	Tests* tes = new Tests;
	while (true)
	{
		tes = base_in_.front();
		out << "\n";
		out << tes->get_category() << endl;
		out << tes->get_id() << endl;
		out << tes->get_question() << endl;
		out << tes->get_answer() << endl;
		out << tes->get_right_answer() << endl;
		out << tes->get_balls() << endl;
		base_in_.pop_front();
		if (base_in_.empty())
			break;
	}
	delete tes;
	out.close();


	/*ofstream out("BaseTestsGeometry.bin", ios::binary | ios::out);
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
	out.close();*/
}

//загрузка тестов по неорганической
void Inorganic::load_test_in()
{
	ifstream in("BaseTestsInorganic.txt", ios::in);
	base_in_.clear();
	if (in.is_open())
	{
		while (true)
		{
			Tests* tes = new Tests;
			char lc[50];
			in >> lc;
			char* buff = new char[strlen(lc) + 1];
			strcpy(buff, lc);
			tes->set_category(buff);
			int id;
			in >> id;
			in.get();
			tes->set_id(id);
			char lq[1000];
			in.getline(lq, 1000);
			char* buff1 = new char[strlen(lq) + 1];
			strcpy(buff1, lq);
			tes->set_question(buff1);
			char la[1000];
			in.getline(la, 1000);
			char* buff2 = new char[strlen(la) + 1];
			strcpy(buff2, la);
			tes->set_question(buff2);
			int ra;
			in >> ra;
			in.get();
			tes->set_id(ra);
			int b;
			in >> b;
			in.get();
			tes->set_id(b);
			base_in_.push_back(tes);
			in.get();
			if (in.eof())
				break;
		}
	}
	in.close();



	/*ifstream in("BaseTestsGeometry.bin", ios::binary | ios::in);
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
	in.close();*/
}

//сохранение нового теста по неорганической
void Inorganic::print_test_in() const
{
	system("cls");
	int idd = 0;
	SetColor(12, 0);
	cout << "ПЕЧАТЬ ТЕСТА ПО НОМЕРУ:\n" << endl;
	SetColor(14, 0);
	cout << "Введите номер теста: ";
	SetColor(15, 0);
	cin >> idd;
	auto it = base_in_.begin();
	for (; it != base_in_.end(); ++it)
	{
		if ((*it)->get_id() == idd)
			cout << (*it);
		else
		{
			SetColor(12, 0);
			cout << "\nТЕСТ с таким номер ОТСУТСТВУЕТ!!!" << endl;
			SetColor(15, 0);
			Sleep(2500);
		}
	}
	system("pause");
}

//печать на экран всех тестов по неорганической
void Inorganic::print_test_all_in() const
{
	int idd = 0;
	auto it = base_in_.begin();
	system("cls");
	SetColor(12, 0);
	cout << "ПЕЧАТЬ ВСЕХ ТЕСТОВ ПО НЕОРГАНИЧЕСКОЙ:\n" << endl;
	SetColor(15, 0);
	for (; it != base_in_.end(); ++it)
	{
		cout << (*it);

	}
	system("pause");
}