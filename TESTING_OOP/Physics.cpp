#include "Physics.h"

//меню по физике
void Physics::menu_physics_user(string const& log)
{
	while (true)
	{

		Quantum qua;
		Mechanics mec;
		Tested tes;
		tes.load_results();
		qua.load_test_quan();
		system("cls");
		cout << "БАЗА ТЕСТОВ ПО ФИЗИКЕ для ПОЛЬЗОВАТЕЛЯ\n" << endl;
		cout << "КАТЕГОРИИ ТЕСТОВ ПО ФИЗИКЕ:" << endl;
		cout << "1. Сдача теста по КВАНТОВОЙ\n" << "2. Сдача теста по МЕХАНИКЕ\n"
			<< "3. Возврат в предыдущее меню" << endl;
		int var;
		bool v = true;
		while (v)
		{
			cin >> var;
			cin.ignore();
			if (var < 1 || var > 3)    // проверка ввода
				cout << "НЕВЕРНО!!! ПОПРОБУЙТЕ ЕЩЕ РАЗ!!!" << endl;
			else
				v = false;
		}
		switch (var)
		{
		case 1:
		{
			if (tes.get_base_results().empty())
				qua.passing_test_quan(log);
			else
			{
				//string cat = "АЛГЕБРА";
				if ((*tes.get_base_results().find(log)).second.front()->get_cat() == qua.cat_q_)     //проверка есть ли в базе результатов категория по алгебре
				{
					cout << "Тест по КВАНТОВОЙ пройден, выберите другой ТЕСТ!!!" << endl;
					Sleep(2500);
				}

				else
					qua.passing_test_quan(log);
			}
			break;
		}
		case 2:
		{
			if (tes.get_base_results().empty())
				mec.passing_test_mech(log);
			else
			{
				//string cat = "ГЕОМЕТРИЯ";
				if ((*tes.get_base_results().find(log)).second.front()->get_cat() == mec.cat_m_)    //проверка есть ли в базе результатов категория по геометрии
				{
					cout << "Тест по МЕХАНИКЕ пройден, выберите другой ТЕСТ!!!" << endl;
					Sleep(2500);
				}
				else
					mec.passing_test_mech(log);
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


//меню по физике для администратора
void Physics::menu_physics_admin()
{
	while (true)
	{
		Admin ad;
		Quantum qua;
		Mechanics mec;
		qua.load_test_quan();
		mec.load_test_mech();
		system("cls");
		cout << "БАЗА ТЕСТОВ ПО ФИЗИКЕ для АДМИНИСТРАТОРА\n" << endl;
		cout << "МЕНЮ ДЕЙСТВИЙ:" << endl;
		cout << "1. Создание тестов по КВАНТОВОЙ\n" << "2. Создание тестов по МЕХАНИКЕ\n"
			<< "3. Редактирование тестов по КВАНТОВОЙ\n" << "4. Редактирование тестов по МЕХАНИКЕ\n"
			<< "5. Печать на экран тестов по КВАНТОВОЙ\n" << "6. Печать на экран тестов по МЕХАНИКЕ\n"
			<< "7. Возврат в предыдущее меню" << endl;
		int var;
		bool v = true;
		while (v)
		{
			cin >> var;
			cin.ignore();
			if (var < 1 || var > 5)    // проверка ввода
				cout << "НЕВЕРНО!!! ПОПРОБУЙТЕ ЕЩЕ РАЗ!!!" << endl;
			else
				v = false;
		}
		switch (var)
		{
		case 1:
			qua.creature_test_quan();
			break;
		case 2:
			mec.creature_test_mech();
			break;
		case 3:
			qua.edit_test_quan();
			break;
		case 4:
			mec.edit_test_mech();
			break;
		case 5:
			qua.print_test_all_quan();
			break;
		case 6:
			mec.print_test_all_mech();
			break;
		case 7:
			ad.control_tests();
			break;
		default:;
		}
	}
}


Quantum::Quantum(const Quantum& ob)
{
	cat_q_ = ob.cat_q_;
	list<Tests*> t;
	t = ob.base_quan_;
	base_quan_ = t;
}

Quantum& Quantum ::operator=(const Quantum& ob)
{
	cat_q_ = ob.cat_q_;
	list<Tests*> t;
	t = ob.base_quan_;
	base_quan_ = t;
	return *this;
}

//прохождение теста по квантовой
void Quantum::passing_test_quan(string const& log)
{
	system("cls");
	cout << "СДАЧА ТЕСТОВ ПО КВАНТОВОЙ\n" << endl;
	Tested tes;
	Tests ts;
	string lg = log;
	int count_u = 0;                                     //количесвто угаданных ответов
	int bal_u = 0;                                       //количество набранных балов за тест
	auto it = base_quan_.begin();
	for (; it != base_quan_.end(); ++it)
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
	int size = base_quan_.size();
	res->set_cat(cat_q_);
	res->set_kol_que((count_u / size) * 100);
	res->set_kol_righ_ans(count_u);
	res->set_kol_bal(bal_u);
	tes.get_res_base(res);
	system("cls");
	cout << "ТЕСТ ПРОЙДЕН!!!" << endl;
	Sleep(2500);
}

//создание теста по квантовой
void Quantum::creature_test_quan()
{
	Tests* tes = new Tests;
	tes->set_category(cat_q_);
	//print_test_alg();                     //на УДАЛЕНИЕ
	//Sleep(2500);
	int idd = 0;
	bool p = true;
	while (p)
	{
		system("cls");
		cout << "СОЗДАНИЕ ТЕСТА ПО КВАНТОВОЙ:\n" << endl;
		cout << "Введите номер теста: ";
		cin >> idd;
		if (base_quan_.empty())
		{
			tes->set_id(idd);
			p = false;
		}
		else
		{
			auto it = base_quan_.begin();
			for (; it != base_quan_.end(); ++it)
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
		cout << "СОЗДАНИЕ ТЕСТА ПО КВАНТОВОЙ:\n" << endl;
		cout << "Введите текст вопроса: " << endl;;
		char* str = new char;
		cin.ignore();
		cin.getline(str, 1200);
		q = str;
		if (base_quan_.empty())
		{
			tes->set_question(q);
			w = false;
		}
		else
		{
			auto it = base_quan_.begin();
			for (; it != base_quan_.end(); ++it)
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
	cout << "СОЗДАНИЕ ТЕСТА ПО КВАНТОВОЙ:\n" << endl;
	cout << "Введите варианты ответов через пробел: " << endl;
	char* buff1 = new char;
	cin.getline(buff1, 1200);
	an = buff1;
	tes->set_answer(an);
	int v = 0, b = 0;
	system("cls");
	cout << "СОЗДАНИЕ ТЕСТА ПО КВАНТОВОЙ:\n" << endl;
	cout << "Введите номер правильного ответа: ";
	cin >> v;
	tes->set_right_answer(v);
	cout << endl;
	cout << "Введите количество балов за ответ: ";
	cin >> b;
	tes->set_balls(b);
	base_quan_.push_back(tes);
	system("cls");
	cout << "НОВЫЙ ТЕСТ по АЛГЕБРЕ СОЗДАН!!!" << endl;
	Sleep(2500);
	print_test_quan();
	save_test_quan();
}

//редактирование тестов по квантовой
void Quantum::edit_test_quan()
{
	system("cls");
	cout << "РЕДАКТИРОВАНИЕ ТЕСТА ПО КВАНТОВОЙ:\n" << endl;
	cout << "Введите номер теста: ";
	int idd = 0;
	cin >> idd;
	bool set = true;
	if (base_quan_.empty())
	{
		cout << "БАЗА ТЕСТОВ ПО КВАНТОВОЙ ПУСТА!!!" << endl;
		Sleep(2500);
	}
	else
	{
		auto it = base_quan_.begin();
		for (; it != base_quan_.end(); ++it)
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
			load_test_quan();
			system("cls");
			int var;
			cout << "РЕДАКТИРОВАНИЕ ТЕСТОВ ПО КВАНТОВОЙ:\n" << endl;
			cout << "1. Редактировать ВОПРОС\n" << "2. Редактировать ОТВЕТЫ\n"
				<< "3. Редактировать НОМЕР ПРАВИЛЬНОГО ОТВЕТА\n"
				<< "4. Редактировать БАЛЛЫ\n" << "5. Возврат в предыдущее меню\n" << endl;
			bool v = true;
			while (v)
			{
				cin >> var;
				cin.ignore();
				if (var < 1 || var > 5)    // проверка ввода
					cout << "НЕВЕРНО!!! ПОПРОБУЙТЕ ЕЩЕ РАЗ!!!" << endl;
				else
					v = false;
			}
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
				auto it = base_quan_.begin();
				for (; it != base_quan_.end(); ++it)
				{
					if ((*it)->get_id() == idd)
						(*it)->set_question(q);
				}
				cout << endl;
				cout << "ВОПРОС ЗАМЕНЕН!!!" << endl;
				Sleep(2500);
				save_test_quan();
				break;
			}
			case 2:
			{
				system("cls");
				cout << "РЕДАКТИРОВАНИЕ ОТВЕТОВ НА ВОПРОС:\n" << endl;
				cout << "Введите новый текст ответов через пробел: " << endl;
				string q;
				char* buff = new char;
				cin.ignore();
				cin.getline(buff, 1200);
				q = buff;
				auto it = base_quan_.begin();
				for (; it != base_quan_.end(); ++it)
				{
					if ((*it)->get_id() == idd)
						(*it)->set_answer(q);
				}
				cout << endl;
				cout << "ОТВЕТЫ ЗАМЕНЕНЫ!!!" << endl;
				Sleep(2500);
				save_test_quan();
				break;
			}
			case 3:
			{
				system("cls");
				cout << "РЕДАКТИРОВАНИЕ НОМЕРА ПРАВИЛЬНОГО ОТВЕТА:\n" << endl;
				cout << "Введите новый номер правильного ответа: " << endl;
				int an = 0;
				auto it = base_quan_.begin();
				for (; it != base_quan_.end(); ++it)
				{
					if ((*it)->get_id() == idd)
						(*it)->set_right_answer(an);
				}
				cout << endl;
				cout << "НОМЕР ПРАВИЛЬНОГО ОТВЕТА ЗАМЕНЕН!!!" << endl;
				Sleep(2500);
				save_test_quan();
				break;
			}
			case 4:
			{
				system("cls");
				cout << "РЕДАКТИРОВАНИЕ БАЛЛОВ:\n" << endl;
				cout << "Введите новое количество баллов: " << endl;
				int bl = 0;
				auto it = base_quan_.begin();
				for (; it != base_quan_.end(); ++it)
				{
					if ((*it)->get_id() == idd)
						(*it)->set_balls(bl);
				}
				cout << endl;
				cout << "БАЛЛЫ ЗАМЕНЕНЫ!!!" << endl;
				Sleep(2500);
				save_test_quan();
				break;
			}
			case 5:
				menu_physics_admin();
				break;
			default:;
			}
		}
	}
}


//сохранение тестов по квантовой
void Quantum::save_test_quan()
{
	ofstream out("BaseTestsQuantum.txt", ios::out);
	Tests* tes = new Tests;
	while (true)
	{
		tes = base_quan_.front();
		out << "\n";
		out << tes->get_category() << endl;
		out << tes->get_id() << endl;
		out << tes->get_question() << endl;
		out << tes->get_answer() << endl;
		out << tes->get_right_answer() << endl;
		out << tes->get_balls() << endl;
		base_quan_.pop_front();
		if (base_quan_.empty())
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
void Quantum::load_test_quan()
{
	ifstream in("BaseTestsQuantum.txt", ios::in);
	base_quan_.clear();
	if (in.is_open())
	{
		while (true)
		{
			Tests* tes = new Tests;
			char lc[50];
			in >> lc;
			int l_lc = strlen(lc) + 1;
			char* buff = new char(l_lc + 1);
			strcpy(buff, lc);
			tes->set_category(buff);
			int id;
			in >> id;
			in.get();
			tes->set_id(id);
			char lq[1000];
			in.getline(lq, 1000);
			int l_lq = strlen(lq) + 1;
			char* buff1 = new char(l_lq + 1);
			strcpy(buff1, lq);
			tes->set_question(buff1);
			char la[1000];
			in.getline(la, 1000);
			int l_la = strlen(la) + 1;
			char* buff2 = new char(l_lq + 1);
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
			base_quan_.push_back(tes);
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

//печать на экран теста по квантовой
void Quantum::print_test_quan() const
{
	system("cls");
	int idd = 0;
	cout << "ПЕЧАТЬ ТЕСТА ПО НОМЕРУ:\n" << endl;
	cout << "Введите номер теста: ";
	cin >> idd;
	auto it = base_quan_.begin();
	system("cls");
	cout << "ПЕЧАТЬ ТЕСТА ПО НОМЕРУ:\n" << endl;
	for (; it != base_quan_.end(); ++it)
	{
		if ((*it)->get_id() == idd)
			cout << (*it);
		else
			cout << "ТЕСТ с таким номер ОТСУТСТВУЕТ!!!" << endl;
	}
	system("pause");
}

//печать на экран всех тестов по квантовой
void Quantum::print_test_all_quan() const
{
	system("cls");
	int idd = 0;
	auto it = base_quan_.begin();
	system("cls");
	cout << "ПЕЧАТЬ ВСЕХ ТЕСТОВ ПО КВАНТОВОЙ:\n" << endl;
	for (; it != base_quan_.end(); ++it)
	{
		cout << (*it);

	}
	system("pause");
}


Mechanics::Mechanics(const Mechanics& ob)
{
	cat_m_ = ob.cat_m_;
	list<Tests*> t;
	t = ob.base_mech_;
	base_mech_ = t;
}

Mechanics& Mechanics::operator=(const Mechanics& ob)
{
	cat_m_ = ob.cat_m_;
	list<Tests*> t;
	t = ob.base_mech_;
	base_mech_ = t;
	return *this;
}

//прохождение теста по механике
void Mechanics::passing_test_mech(string const& log)
{
	system("cls");
	cout << "СДАЧА ТЕСТОВ ПО МЕХАНИКЕ\n" << endl;
	Tested tes;
	Tests ts;
	string lg = log;
	int count_u = 0;                                     //количесвто угаданных ответов
	int bal_u = 0;                                       //количество набранных балов за тест
	auto it = base_mech_.begin();
	for (; it != base_mech_.end(); ++it)
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
	int size = base_mech_.size();
	res->set_cat(cat_m_);
	res->set_kol_que((count_u / size) * 100);
	res->set_kol_righ_ans(count_u);
	res->set_kol_bal(bal_u);
	tes.get_res_base(res);
	system("cls");
	cout << "ТЕСТ ПРОЙДЕН!!!" << endl;
	Sleep(2500);
}

//создание теста по механике
void Mechanics::creature_test_mech()
{
	Tests* tes = new Tests;
	tes->set_category(cat_m_);
	int idd = 0;
	bool p = true;
	while (p)
	{
		system("cls");
		cout << "СОЗДАНИЕ ТЕСТА ПО МЕХАНИКЕ:\n" << endl;
		cout << "Введите номер теста: ";
		cin >> idd;
		if (base_mech_.empty())
		{
			tes->set_id(idd);
			p = false;
		}
		else
		{
			auto it = base_mech_.begin();
			for (; it != base_mech_.end(); ++it)
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
		cout << "СОЗДАНИЕ ТЕСТА ПО МЕХАНИКЕ:\n" << endl;
		cout << "Введите текст вопроса: " << endl;;
		char* buff = new char;
		cin.getline(buff, 1200);
		q = buff;
		if (base_mech_.empty())
		{
			tes->set_question(q);
			w = false;
		}
		else
		{
			auto it = base_mech_.begin();
			for (; it != base_mech_.end(); ++it)
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
	cout << "СОЗДАНИЕ ТЕСТА ПО МЕХАНИКЕ:\n" << endl;
	cout << "Введите варианты ответов через пробел: " << endl;
	char* buff1 = new char;
	cin.getline(buff1, 1200);
	an = buff1;
	tes->set_answer(an);
	int v = 0, b = 0;
	system("cls");
	cout << "СОЗДАНИЕ ТЕСТА ПО МЕХАНИКЕ:\n" << endl;
	cout << "Введите номер правильного ответа: ";
	cin >> v;
	tes->set_right_answer(v);
	cout << endl;
	cout << "Введите количество балов за ответ: ";
	cin >> b;
	tes->set_balls(b);
	base_mech_.push_back(tes);
	system("cls");
	cout << "НОВЫЙ ТЕСТ по ГЕОМЕТРИИ СОЗДАН!!!" << endl;
	Sleep(2500);
	print_test_mech();
	save_test_mech();

}

//редактирование тестов по механике
void Mechanics::edit_test_mech()
{
	system("cls");
	cout << "РЕДАКТИРОВАНИЕ ТЕСТА ПО МЕХАНИКЕ:\n" << endl;
	cout << "Введите номер теста: ";
	int idd = 0;
	cin >> idd;
	bool set = true;
	if (base_mech_.empty())
	{
		cout << "БАЗА ТЕСТОВ ПО ГЕОМЕТРИИ ПУСТА!!!" << endl;
		Sleep(2500);
	}
	else
	{
		auto it = base_mech_.begin();
		for (; it != base_mech_.end(); ++it)
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
			load_test_mech();
			system("cls");
			int var;
			cout << "РЕДАКТИРОВАНИЕ ТЕСТОВ ПО МЕХАНИКЕ:\n" << endl;
			cout << "1. Редактировать ВОПРОС\n" << "2. Редактировать ОТВЕТЫ\n"
				<< "3. Редактировать НОМЕР ПРАВИЛЬНОГО ОТВЕТА\n"
				<< "4. Редактировать БАЛЛЫ\n" << "5. Возврат в предыдущее меню\n" << endl;
			bool v = true;
			while (v)
			{
				cin >> var;
				cin.ignore();
				if (var < 1 || var > 5)    // проверка ввода
					cout << "НЕВЕРНО!!! ПОПРОБУЙТЕ ЕЩЕ РАЗ!!!" << endl;
				else
					v = false;
			}
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
				auto it = base_mech_.begin();
				for (; it != base_mech_.end(); ++it)
				{
					if ((*it)->get_id() == idd)
						(*it)->set_question(q);
				}
				cout << endl;
				cout << "ВОПРОС ЗАМЕНЕН!!!" << endl;
				Sleep(2500);
				save_test_mech();
				break;
			}
			case 2:
			{
				system("cls");
				cout << "РЕДАКТИРОВАНИЕ ОТВЕТОВ НА ВОПРОС:\n" << endl;
				cout << "Введите новый текст ответов через пробел: " << endl;
				string q;
				char* buff = new char;
				cin.ignore();
				cin.getline(buff, 1200);
				q = buff;
				auto it = base_mech_.begin();
				for (; it != base_mech_.end(); ++it)
				{
					if ((*it)->get_id() == idd)
						(*it)->set_answer(q);
				}
				cout << endl;
				cout << "ОТВЕТЫ ЗАМЕНЕНЫ!!!" << endl;
				Sleep(2500);
				save_test_mech();
				break;
			}
			case 3:
			{
				system("cls");
				cout << "РЕДАКТИРОВАНИЕ НОМЕРА ПРАВИЛЬНОГО ОТВЕТА:\n" << endl;
				cout << "Введите новый номер правильного ответа: " << endl;
				int an = 0;
				auto it = base_mech_.begin();
				for (; it != base_mech_.end(); ++it)
				{
					if ((*it)->get_id() == idd)
						(*it)->set_right_answer(an);
				}
				cout << endl;
				cout << "НОМЕР ПРАВИЛЬНОГО ОТВЕТА ЗАМЕНЕН!!!" << endl;
				Sleep(2500);
				save_test_mech();
				break;
			}
			case 4:
			{
				system("cls");
				cout << "РЕДАКТИРОВАНИЕ БАЛЛОВ:\n" << endl;
				cout << "Введите новое количество баллов: " << endl;
				int bl = 0;
				auto it = base_mech_.begin();
				for (; it != base_mech_.end(); ++it)
				{
					if ((*it)->get_id() == idd)
						(*it)->set_balls(bl);
				}
				cout << endl;
				cout << "БАЛЛЫ ЗАМЕНЕНЫ!!!" << endl;
				Sleep(2500);
				save_test_mech();
				break;
			}
			case 5:
				menu_physics_admin();
				break;
			default:;
			}
		}
	}
}


//сохранение тестов по механике
void Mechanics::save_test_mech()
{
	ofstream out("BaseTestsMechanics.txt", ios::out);
	Tests* tes = new Tests;
	while (true)
	{
		tes = base_mech_.front();
		out << "\n";
		out << tes->get_category() << endl;
		out << tes->get_id() << endl;
		out << tes->get_question() << endl;
		out << tes->get_answer() << endl;
		out << tes->get_right_answer() << endl;
		out << tes->get_balls() << endl;
		base_mech_.pop_front();
		if (base_mech_.empty())
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

//загрузка тестов по геометрии
void Mechanics::load_test_mech()
{
	ifstream in("BaseTestsMechanics.txt", ios::in);
	base_mech_.clear();
	if (in.is_open())
	{
		while (true)
		{
			Tests* tes = new Tests;
			char lc[50];
			in >> lc;
			int l_lc = strlen(lc) + 1;
			char* buff = new char(l_lc + 1);
			strcpy(buff, lc);
			tes->set_category(buff);
			int id;
			in >> id;
			in.get();
			tes->set_id(id);
			char lq[1000];
			in.getline(lq, 1000);
			int l_lq = strlen(lq) + 1;
			char* buff1 = new char(l_lq + 1);
			strcpy(buff1, lq);
			tes->set_question(buff1);
			char la[1000];
			in.getline(la, 1000);
			int l_la = strlen(la) + 1;
			char* buff2 = new char(l_lq + 1);
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
			base_mech_.push_back(tes);
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

//сохранение нового теста по механике
void Mechanics::print_test_mech() const
{
	system("cls");
	int idd = 0;
	cout << "ПЕЧАТЬ ТЕСТА ПО НОМЕРУ:\n" << endl;
	cout << "Введите номер теста: ";
	cin >> idd;
	auto it = base_mech_.begin();
	for (; it != base_mech_.end(); ++it)
	{
		if ((*it)->get_id() == idd)
			cout << (*it);
		else
			cout << "ТЕСТ с таким номер ОТСУТСТВУЕТ!!!" << endl;
	}
	system("pause");
}

//печать на экран всех тестов по механике
void Mechanics::print_test_all_mech() const
{
	system("cls");
	int idd = 0;
	auto it = base_mech_.begin();
	system("cls");
	cout << "ПЕЧАТЬ ВСЕХ ТЕСТОВ ПО МЕХАНИКЕ:\n" << endl;
	for (; it != base_mech_.end(); ++it)
	{
		cout << (*it);

	}
	system("pause");
}