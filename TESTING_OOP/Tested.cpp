#include"Tested.h"

void Tested::shapka_start(string const& log)
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

Tested::Tested(const Tested& ob)
{
	list<Results*> res;
	res = ob.result_;
	result_ = res;
	list<User*> bt;
	bt = ob.base_tested_;
	base_tested_ = bt;
	map<string, list<Results*>> br;
	br = ob.base_results_;
	base_results_ = br;
}

Tested& Tested::operator=(const Tested& ob)
{
	list<Results*> res;
	res = ob.result_;
	result_ = res;
	list<User*> bt;
	bt = ob.base_tested_;
	base_tested_ = bt;
	map<string, list<Results*>> br;
	br = ob.base_results_;
	base_results_ = br;
	return *this;
}

void Tested::new_testing(string const& log)
{
	while (true)
	{
		system("cls");
		Maths mat;
		Physics phys;
		Chemistry chem;
		load_results();
		shapka_start(log);
		SetColor(12, 0);
		cout << "МЕНЮ ПОЛЬЗОВАТЕЛЯ ПО СДАЧИ ТЕСТОВ:\n" << endl;
		SetColor(14, 0);
		cout << "1. Сдать тест по МАТЕМАТИКЕ\n"
			<< "2. Сдать тест по ФИЗИКЕ\n"
			<< "3. Сдать тест по ХИМИИ\n"
			<< "4. Возврат в предыдущее меню\n" << endl;
		int var1;
		bool v = true;
		while (v)
		{
			SetColor(15, 0);
			cin >> var1;
			cin.ignore();
			if (var1 < 1 || var1 > 4)    // проверка ввода
			{
				SetColor(12, 0);
				cout << "НЕВЕРНО!!! ПОПРОБУЙТЕ ЕЩЕ РАЗ!!!" << endl;
				SetColor(15, 0);
			}
			else
				v = false;
		}
		switch (var1)
		{
		case 1:
			mat.menu_maths_user(log);
			break;
		case 2:
			phys.menu_physics_user(log);
			break;
		case 3:
			chem.menu_chem_user(log);
			break;
		case 4:
			menu_tested(log);
			break;
		default:;
		}
	}
}

//регестрация пользователя
void Tested::registry_in()
{
	system("cls");
	string log = "";
	SetColor(12, 0);
	gotoxy(2, 10);
	cout << "РЕГЕСТРАЦИЯ ПОЛЬЗОВАТЕЛЯ:\n" << endl;
	User* user = new User;
	if (base_tested_.empty())  //проверка на пустоту
	{
		//string log;
		SetColor(14, 0);
		cout << "Введите ЛОГИН: ";
		SetColor(15, 0);
		cin >> log;
		uppercase(log);
		user->set_login(log);
		string pas;
		bool ad = true;
		//проверка пороля на размер
		while (ad)
		{
			SetColor(14, 0);
			cout << "Введите ПАРОЛЬ (не менее 8-ми символов): ";
			SetColor(15, 0);
			cin >> pas;
			ad = check_size(pas);  //проверка на размер пароля
		}
		auto pass = hashing(pas);  //шифрование пароля
		user->set_pass(pass);
		char* n = new char;
		cin.ignore();
		SetColor(14, 0);
		cout << "Введите ФИО: ";
		SetColor(15, 0);
		cin.getline(n, 100);
		string name = n;
		user->set_name(name);
		string email;
		SetColor(14, 0);
		cout << "Введите электронный адрес: ";
		SetColor(15, 0);
		cin >> email;
		user->set_email(email);
		string phone;
		SetColor(14, 0);
		cout << "Введите номер телефона: ";
		SetColor(15, 0);
		cin >> phone;
		user->set_phone(phone);
		base_tested_.push_back(user);
		SetColor(12, 0);
		cout << "\nПОЛЬЗОВАТЕЛЬ ДОБАВЛЕН!!!" << endl;
		Sleep(2500);
		system("cls");
		SetColor(12, 0);
		gotoxy(10, 10);
		cout << "Теперь можете войти под своим ЛОГИНОМ и ПАРОЛЕМ!!!" << endl;
		SetColor(15, 0);
		Sleep(2500);
		save_base();
	}
	else
	{
		string log;
		bool lp = true;
		//проверяем логин на повторение
		while (lp)
		{
			system("cls");
			SetColor(12, 0);
			gotoxy(2, 10);
			cout << "РЕГЕСТРАЦИЯ ПОЛЬЗОВАТЕЛЯ:\n" << endl;
			SetColor(14, 0);
			cout << "Введите ЛОГИН: ";
			SetColor(15, 0);
			cin >> log;
			uppercase(log);
			int count = 0;
			//поиск одинаковых логинов со счетчиком
			auto it = base_tested_.begin();
			for (; it != base_tested_.end(); ++it)
			{
				if ((*it)->get_login() == log)
				{
					count++;
				}
			}
			if (count != 0)
			{
				SetColor(12, 0);
				cout << "\nТакой ЛОГИН уже есть, введите другой ЛОГИН!!!" << endl;
				SetColor(15, 0);
				Sleep(2500);
			}
			else
				lp = false;
		}
		user->set_login(log);
		string pas;
		bool ad = true;
		//проверка пороля на размер
		while (ad)
		{
			SetColor(14, 0);
			cout << "Введите ПАРОЛЬ (не менее 8-ми символов): ";
			SetColor(15, 0);
			cin >> pas;
			ad = check_size(pas);
		}
		//шифрование пароля
		auto pass = hashing(pas);
		bool ps = true;
		while (ps)
		{
			auto it = base_tested_.begin();
			for (; it != base_tested_.end(); ++it)
			{
				if ((*it)->get_pass() == pass)  //проверяем есть ли еще такой пароль в базе
				{
					SetColor(12, 0);
					cout << "\nТакой ПАРОЛЬ уже есть, введите другой ПАРОЛЬ!!!" << endl;
					SetColor(15, 0);
					Sleep(2500);
					system("cls");
					bool d = true;
					while (d)
					{
						SetColor(12, 0);
						gotoxy(2, 10);
						cout << "РЕГЕСТРАЦИЯ ПОЛЬЗОВАТЕЛЯ:\n" << endl;
						SetColor(14, 0);
						cout << "Введите ПАРОЛЬ (не менее 8-ми символов): ";
						SetColor(15, 0);
						cin >> pas;
						d = check_size(pas);
					}
					pass = hashing(pas);
					if ((*it)->get_pass() != pass)
						ps = false;
				}
				else
					ps = false;
			}
		}
		user->set_pass(pass);
		char* n = new char;
		cin.ignore();
		SetColor(14, 0);
		cout << "Введите ФИО: ";
		SetColor(15, 0);
		cin.getline(n, 100);
		string name = n;
		user->set_name(name);
		string email;
		SetColor(14, 0);
		cout << "Введите электронный адрес: ";
		SetColor(15, 0);
		cin >> email;
		user->set_email(email);
		string phone;
		SetColor(14, 0);
		cout << "Введите номер телефона: ";
		SetColor(15, 0);
		cin >> phone;
		user->set_phone(phone);
		base_tested_.push_back(user);
		SetColor(12, 0);
		cout << "\nПОЛЬЗОВАТЕЛЬ ДОБАВЛЕН!!!" << endl;
		Sleep(2500);
		system("cls");
		SetColor(12, 0);
		gotoxy(10, 10);
		cout << "Теперь можете войти под своим ЛОГИНОМ и ПАРОЛЕМ!!!" << endl;
		SetColor(15, 0);
		Sleep(2500);
		save_base();
	}
}

//проверка на повторение
bool Tested::check_in(unsigned int ps, string lg)
{
	auto it = base_tested_.begin();
	for (; it != base_tested_.end(); ++it)
	{
		if ((*it)->get_pass() == ps && (*it)->get_login() == lg)
			return true;
	}
	return false;
}


//меню тестируемого
void Tested::menu_tested(string const& log)
{
	while (true)
	{
		load_results();
		Start ts;
		system("cls");
		shapka_start(log);
		SetColor(12, 0);
		cout << "МЕНЮ ПОЛЬЗОВАТЕЛЯ:\n" << endl;
		SetColor(14, 0);
		cout << "1. Сдать ТЕСТИРОВАНИЕ\n"
			<< "2. Просмотор результатов ТЕСТИРОВАНИЯ\n"
			<< "3. Печать результатов ТЕСТИРОВАНИЯ в файл\n"
			<< "4. Возврат в предыдущее меню\n" << endl;
		int var1;
		bool v = true;
		while (v)
		{
			SetColor(15, 0);
			cin >> var1;
			cin.ignore();
			if (var1 < 1 || var1 > 4)    // проверка ввода
			{
				SetColor(12, 0);
				cout << "НЕВЕРНО!!! ПОПРОБУЙТЕ ЕЩЕ РАЗ!!!" << endl;
				SetColor(15, 0);
			}
			else
				v = false;
		}
		switch (var1)
		{
		case 1:
			new_testing(log);
			break;
		case 2:
			print_result(log);
			system("pause");
			break;
		case 3:
			print_result_file(log);
			break;
		case 4:
			ts.enter_system();
		default:;
		}
	}
}

//просмотр результата тестирования
void Tested::print_result(string const& log)
{
	system("cls");
	load_results();
	SetColor(10, 0);
	string S(51, '#');
	cout << endl;
	gotoxy(5, 2);
	cout << "ЛОГИН: " << log;
	SetColor(12, 0);
	gotoxy(20, 2);
	cout << "РЕЗУЛЬТАТЫ ТЕСТИРОВАНИЯ\n" << endl;
	SetColor(13, 0);
	shapka_results();
	string lg = log;
	auto it = result_.begin();
	for (; it != result_.end(); ++it)
	{
		if ((*it)->get_log().c_str() == lg)
			cout << (*it);
	}
	cout << S << endl << endl;
	SetColor(15, 0);
}


//сохранить промежуточное тестирование
void Tested::save_results()
{
	ofstream out("BaseResult.txt", ios::out);
	Results* res = new Results;
	auto it = base_results_.begin();
	for (; it != base_results_.end(); ++it)
	{
		if ((*it).second.size() > 1)
		{
			auto it2 = (*it).second.begin();
			for (; it2 != (*it).second.end(); ++it2)
			{
				out << "\n";
				out << (*it2)->get_log() << endl;
				out << (*it2)->get_cat() << endl;
				out << (*it2)->get_kol_righ_ans() << endl;
				out << (*it2)->get_kol_que() << endl;
				out << (*it2)->get_kol_bal() << endl;;
			}
		}
		else
		{
			res = (*it).second.front();
			out << "\n";
			out << res->get_log() << endl;
			out << res->get_cat() << endl;
			out << res->get_kol_righ_ans() << endl;
			out << res->get_kol_que() << endl;
			out << res->get_kol_bal() << endl;;
		}
	}
	delete res;
	out.close();


	/*ofstream out("BaseResult.bin", ios::binary | ios::out);
	int length = result_.size();
	out.write(reinterpret_cast<char*>(&length), sizeof(int));
	Results* res = new Results;
	for (int i = 0; i < length; i++)
	{
		res = result_.front();
		int l_log = res->get_log().size() + 1;
		out.write(reinterpret_cast<char*>(&l_log), sizeof(int));
		out.write(const_cast<char*>(res->get_log().c_str()), l_log);
		int l_c = res->get_cat().size() + 1;
		out.write(reinterpret_cast<char*>(&l_c), sizeof(int));
		out.write(const_cast<char*>(res->get_cat().c_str()), l_c);
		int kol_q = res->get_kol_que();
		out.write(reinterpret_cast<char*>(&kol_q), sizeof(int));
		int kol_r = res->get_kol_righ_ans();
		out.write(reinterpret_cast<char*>(&kol_r), sizeof(int));
		int kol_b = res->get_kol_bal();
		out.write(reinterpret_cast<char*>(&kol_b), sizeof(int));
		result_.pop_front();

	}
	delete res;
	out.close();*/
}

//загрузить последнее сохраненное тестирование
void Tested::load_results()
{
	ifstream in("BaseResult.txt", ios::in);
	result_.clear();
	base_results_.clear();
	if (in.is_open())
	{
		while (true)
		{
			Results* res = new Results;
			char lg[50];
			in >> lg;
			char* buff = new char[strlen(lg) + 1];
			strcpy(buff, lg);
			res->set_log(buff);
			char lc[50];
			in >> lc;
			char* buff1 = new char[strlen(lc) + 1];
			strcpy(buff1, lc);
			res->set_cat(buff1);
			int qr;
			in >> qr;
			in.get();
			res->set_kol_righ_ans(qr);
			int que;
			in >> que;
			in.get();
			res->set_kol_que(que);
			int bl;
			in >> bl;
			in.get();
			res->set_kol_bal(bl);
			result_.push_back(res);
			base_results_.insert(make_pair(res->get_log(), result_));
			in.get();
			if (in.eof())
				break;
		}
	}
	in.close();



	/*ifstream in("BaseResult.bin", ios::binary | ios::in);
	int length;
	in.read(reinterpret_cast<char*>(&length), sizeof(int));
	result_.clear();
	base_results_.clear();
	if (in.is_open())
	{
		for (int i = 0; i < length; i++)
		{
			Results* res = new Results;
			int l_log;
			in.read(reinterpret_cast<char*>(&l_log), sizeof(int));
			char* buff = new char(l_log + 1);
			in.read(buff, l_log);
			res->set_log(buff);
			delete buff;
			int l_c;
			in.read(reinterpret_cast<char*>(&l_c), sizeof(int));
			char* buff1 = new char(l_c + 1);
			in.read(buff1, l_c);
			res->set_cat(buff1);
			delete buff1;
			int kol_q;
			in.read(reinterpret_cast<char*>(&kol_q), sizeof(int));
			res->set_kol_que(kol_q);
			int kol_r;
			in.read(reinterpret_cast<char*>(&kol_r), sizeof(int));
			res->set_kol_righ_ans(kol_r);
			int kol_b;
			in.read(reinterpret_cast<char*>(&kol_b), sizeof(int));
			res->set_kol_bal(kol_b);

			result_.push_back(res);
			base_results_.insert(make_pair(res->get_log(), result_));
		}

	}
	in.close();*/
}


//сохранение базы тестируемых
void Tested::save_base()
{
	ofstream out("BaseTested.txt", ios::out);
	User* us = new User;
	while (true)
	{
		us = base_tested_.front();
		out << "\n";
		out << us->get_login() << endl;
		out << us->get_pass() << endl;
		out << us->get_name() << endl;
		out << us->get_email() << endl;
		out << us->get_phone() << endl;;
		base_tested_.pop_front();
		if (base_tested_.empty())
			break;
	}
	delete us;
	out.close();


	/*ofstream out("BaseTested.bin", ios::binary | ios::out);
	int length = base_tested_.size();
	out.write(reinterpret_cast<char*>(&length), sizeof(int));
	user_ = new User;
	for (int i = 0; i < length; i++)
	{
		user_ = base_tested_.front();
		unsigned int pas = user_->get_pass();
		out.write(reinterpret_cast<char*>(&pas), sizeof(unsigned int));
		int l_log = user_->get_login().size() + 1;
		out.write(reinterpret_cast<char*>(&l_log), sizeof(int));
		out.write(const_cast<char*>(user_->get_login().c_str()), l_log);
		int l_n = user_->get_name().size() + 1;
		out.write(reinterpret_cast<char*>(&l_n), sizeof(int));
		out.write(const_cast<char*>(user_->get_name().c_str()), l_n);
		int l_em = user_->get_email().size() + 1;
		out.write(reinterpret_cast<char*>(&l_em), sizeof(int));
		out.write(const_cast<char*>(user_->get_email().c_str()), l_em);
		int l_ph = user_->get_phone().size() + 1;
		out.write(reinterpret_cast<char*>(&l_ph), sizeof(int));
		out.write(const_cast<char*>(user_->get_phone().c_str()), l_ph);
		base_tested_.pop_front();
	}
	delete user_;
	out.close();*/

}

//загрузка базы тестируемых
void Tested::load_base()
{
	ifstream fin("BaseTested.txt");
	if (fin.is_open())
	{
		base_tested_.clear();

		while (true)
		{
			User* us = new User;
			char lg[50];
			fin >> lg;
			char* buff = new char[strlen(lg) + 1];
			strcpy(buff, lg);
			us->set_login(buff);
			unsigned int pas;
			fin >> pas;
			fin.get();
			us->set_pass(pas);
			char ln[50];
			fin.getline(ln, 50);
			char* buff1 = new char[strlen(ln) + 1];
			strcpy(buff1, ln);
			us->set_name(buff1);
			char le[50];
			fin >> le;
			char* buff2 = new char[strlen(le) + 1];
			strcpy(buff2, le);
			us->set_email(buff2);
			char lp[50];
			fin.ignore();
			fin.getline(lp, 50);
			char* buff3 = new char[strlen(lp) + 1];
			strcpy(buff3, lp);
			us->set_phone(buff3);
			base_tested_.push_back(us);
			fin.get();
			if (fin.eof())
				break;
		}
	}
	fin.close();

	/*ifstream fin("BaseTested.bin", ios::binary | ios::in);
	if (fin.is_open())
	{
		int length;
		fin.read(reinterpret_cast<char*>(&length), sizeof(int));
		base_tested_.clear();
		for (int i = 0; i < length; i++)
		{
			user_ = new User;
			unsigned int pas;
			fin.read(reinterpret_cast<char*>(&pas), sizeof(unsigned int));
			user_->set_pass(pas);
			int l_log;
			fin.read(reinterpret_cast<char*>(&l_log), sizeof(int));
			char* buff = new char(l_log + 1);
			fin.read(buff, l_log);
			user_->set_login(buff);
			int l_n;
			fin.read(reinterpret_cast<char*>(&l_n), sizeof(int));
			char* buff1 = new char(l_n + 1);
			fin.read(buff1, l_n);
			user_->set_name(buff1);
			int l_em;
			fin.read(reinterpret_cast<char*>(&l_em), sizeof(int));
			char* buff2 = new char(l_em + 1);
			fin.read(buff2, l_em);
			user_->set_email(buff2);
			int l_ph;
			fin.read(reinterpret_cast<char*>(&l_ph), sizeof(int));
			char* buff3 = new char(l_ph + 1);
			fin.read(buff3, l_ph);
			user_->set_phone(buff3);

			base_tested_.push_back(user_);

		}
	}
	fin.close();*/

}

//проверка и добавление нового результата 
void Tested::get_res_base(Results*& res)
{
	load_results();
	Results* ress = res;
	string log = ress->get_log();
	if (base_results_.count(log))
	{
		auto iter = base_results_.find(log);
		(*iter).second.push_back(ress);
	}
	else
	{
		result_.push_back(ress);
		base_results_.insert(make_pair(log, result_));
	}
	save_results();
}

//проверка и добавление нового пользователя
void Tested::get_user_base(User*& us)
{
	base_tested_.push_back(us);
	save_base();
}

//печать результатов тестирования в файл
void Tested::print_result_file(string const& log)
{
	system("cls");
	shapka_start(log);
	SetColor(12, 0);
	cout << "СОХРАНЕНИЕ РЕЗУЛЬТАТОВ В ФАЙЛ\n" << endl;
	SetColor(14, 0);
	cout << "Введите имя файла: ";
	string file;
	SetColor(15, 0);
	cin >> file;
	file = file + ".txt";
	ofstream out(file, ios::out);
	string S(51, '#');
	out << endl;
	gotoxy(5, 2);
	out << "ЛОГИН: " << log;
	gotoxy(20, 2);
	out << "  РЕЗУЛЬТАТЫ ТЕСТИРОВАНИЯ\n" << endl;
	SetColor(13, 0);
	out << S << endl;
	out << right << "#" << setw(10) << "ПРЕДМЕТ" << "  #" << setw(12) << "ВЕРНЫЕ ОТВ." << "  #" << setw(8)
		<< "ПРОЦЕНТ" << "  #" << setw(8) << "БАЛЛЫ" << "  #" << endl;
	out << S << endl;
	string lg = log;
	auto it = result_.begin();
	for (; it != result_.end(); ++it)
	{
		if ((*it)->get_log().c_str() == lg)
			out << (*it);
	}
	out << S << endl;
	out.close();
	system("cls");
	SetColor(12, 0);
	gotoxy(10, 10);
	cout << "РЕЗУЛЬТАТЫ СОХРАНЕНЫ В ФАЙЛ!!!" << endl;
	Sleep(2500);
	SetColor(15, 0);
}

void Tested::shapka_users()
{
	SetColor(13, 0);
	string S(94, '#');
	cout << S << endl;
	cout << right << "#" << setw(5) << " НОМЕР" << " #" << setw(8) << "ЛОГИН" << "    #" << setw(18) << "ФИО"
		<< "         #" << setw(20) << "EMAIL" << "  #" << setw(18) << "ТЕЛЕФОН" << "  #" << endl;
	cout << S << endl;
}

void Tested::shapka_results()
{
	SetColor(13, 0);
	string S(51, '#');
	cout << S << endl;
	cout << right << "#" << setw(10) << "ПРЕДМЕТ" << "  #" << setw(12) << "ВЕРНЫЕ ОТВ." << "  #" << setw(8)
		<< "ПРОЦЕНТ" << "  #" << setw(8) << "БАЛЛЫ" << "  #" << endl;
	cout << S << endl;
}

//показать на экран все результаты
void Tested::print_all_results()
{
	system("cls");
	load_results();
	SetColor(10, 0);
	string S(61, '#');
	cout << endl;
	SetColor(12, 0);
	gotoxy(20, 2);
	cout << "ОБЩАЯ БАЗА ДАННЫХ РЕЗУЛЬТАТОВ ТЕСТОВ\n" << endl;
	auto it = base_results_.begin();
	for (; it != base_results_.end(); ++it)
	{
		SetColor(13, 0);
		cout << S << endl;
		SetColor(12, 0);
		cout << "  ЛОГИН: " << (*it).first << endl;
		auto it2 = (*it).second.begin();
		for (; it2 != (*it).second.end(); ++it2)
		{
			SetColor(13, 0);
			if ((*it).first.c_str() == (*it2)->get_log().c_str())
				cout << "  ПРЕДМЕТ: " << (*it2)->get_cat() << "  " << "ВЕРНЫЕ ОТВ.: " << (*it2)->get_kol_righ_ans()
				<< "  " << "ПРОЦЕНТ: " << (*it2)->get_kol_que() << "  " << "БАЛЛЫ: " << (*it2)->get_kol_bal() << endl;
		}
		cout << S << endl << endl;
	}
	SetColor(15, 0);
}

//показать на экран результаты по определенному тесту
void Tested::print_result_tests(string cat)
{
	system("cls");
	load_results();
	SetColor(10, 0);
	string ct = cat;
	string S(61, '#');
	cout << endl;
	SetColor(12, 0);
	gotoxy(20, 2);
	cout << "БАЗА ДАННЫХ РЕЗУЛЬТАТОВ ПО ТЕСТАМ: " << ct << "\n" << endl;
	auto it = base_results_.begin();
	for (; it != base_results_.end(); ++it)
	{
		SetColor(13, 0);
		cout << S << endl;
		auto it2 = (*it).second.begin();
		for (; it2 != (*it).second.end(); ++it2)
		{
			if ((*it2)->get_cat().c_str() == ct)
				cout << "  ПРЕДМЕТ: " << (*it2)->get_cat() << "  " << "ВЕРНЫЕ ОТВ.: " << (*it2)->get_kol_righ_ans()
				<< "  " << "ПРОЦЕНТ: " << (*it2)->get_kol_que() << "  " << "БАЛЛЫ: " << (*it2)->get_kol_bal() << endl;
		}
		cout << S << endl << endl;
	}
	SetColor(15, 0);

}

//показать на экран результаты по определенному пользователю
void Tested::print_result_user()
{
	system("cls");
	load_results();
	load_base();
	SetColor(10, 0);
	print_users();
	string lg;
	string S(61, '#');
	cout << endl << endl;
	SetColor(14, 0);
	cout << "Введите ЛОГИН ПОЛЬЗОВАТЕЛЯ для ПЕЧАТИ РЕЗУЛЬТАТОВ: ";
	SetColor(15, 0);
	cin >> lg;
	cout << endl;
	SetColor(12, 0);
	gotoxy(20, 2);
	cout << "БАЗА ДАННЫХ РЕЗУЛЬТАТОВ ПО ЛОГИНУ: " << lg << "\n" << endl;
	auto it = base_results_.begin();
	for (; it != base_results_.end(); ++it)
	{
		if ((*it).first == lg)
		{
			SetColor(13, 0);
			cout << S << endl;
			SetColor(12, 0);
			cout << "  ЛОГИН: " << (*it).first << endl;
			auto it2 = (*it).second.begin();
			for (; it2 != (*it).second.end(); ++it2)
			{
				if ((*it2)->get_log().c_str() == lg)
					cout << "  ПРЕДМЕТ: " << (*it2)->get_cat() << "  " << "ВЕРНЫЕ ОТВ.: " << (*it2)->get_kol_righ_ans()
					<< "  " << "ПРОЦЕНТ: " << (*it2)->get_kol_que() << "  " << "БАЛЛЫ: " << (*it2)->get_kol_bal() << endl;
			}
			cout << S << endl << endl;
		}
	}
	SetColor(15, 0);
}

//печать всех результатов тестирования в файл
void Tested::print_all_result_file()
{
	system("cls");
	gotoxy(2, 2);
	SetColor(12, 0);
	cout << "СОХРАНЕНИЕ РЕЗУЛЬТАТОВ В ФАЙЛ\n" << endl;
	SetColor(14, 0);
	cout << "Введите имя файла: ";
	string file;
	SetColor(15, 0);
	cin >> file;
	file = file + ".txt";
	ofstream out(file, ios::out);
	string S(51, '#');
	out << endl;
	gotoxy(20, 2);
	out << "  ВСЕ РЕЗУЛЬТАТЫ ТЕСТИРОВАНИЯ\n" << endl;
	SetColor(13, 0);
	out << S << endl;
	out << right << "#" << setw(10) << "ПРЕДМЕТ" << "  #" << setw(12) << "ВЕРНЫЕ ОТВ." << "  #" << setw(8)
		<< "ПРОЦЕНТ" << "  #" << setw(8) << "БАЛЛЫ" << "  #" << endl;
	out << S << endl;
	auto it = result_.begin();
	for (; it != result_.end(); ++it)
	{
		out << (*it);
	}
	out << S << endl;
	out.close();
	system("cls");
	SetColor(12, 0);
	gotoxy(10, 10);
	cout << "РЕЗУЛЬТАТЫ СОХРАНЕНЫ В ФАЙЛ!!!" << endl;
	Sleep(2500);
	SetColor(15, 0);
}

//просмотр базы пользователей
void Tested::print_users()
{
	system("cls");
	string S(94, '#');
	gotoxy(37, 2);
	SetColor(12, 0);
	cout << "СПИСОК ПОЛЬЗОВАТЕЛЕЙ:\n" << endl;
	SetColor(15, 0);
	int i = 1;
	base_tested_.sort();
	shapka_users();
	auto it = base_tested_.begin();
	for (; it != base_tested_.end(); ++it, i++)
		cout << "#" << setw(4) << i << "   #" << (*it);
	cout << S << endl;
}

//печать базы пользователей в файл
void Tested::print_users_file()
{
	system("cls");
	SetColor(12, 0);
	gotoxy(2, 4);
	cout << "Введите название файла для печати базы пользователей: ";
	SetColor(15, 0);
	string file;
	cin >> file;
	file += ".txt";
	ofstream out(file, ios::out);
	gotoxy(37, 2);
	out << "СПИСОК ПОЛЬЗОВАТЕЛЕЙ:\n" << endl;
	int i = 1;
	base_tested_.sort();
	string S(94, '#');
	out << S << endl;
	out << right << "#" << setw(5) << " НОМЕР" << " #" << setw(8) << "ЛОГИН" << "    #" << setw(18) << "ФИО"
		<< "         #" << setw(20) << "EMAIL" << "  #" << setw(18) << "ТЕЛЕФОН" << "  #" << endl;
	out << S << endl;
	auto it = base_tested_.begin();
	for (; it != base_tested_.end(); ++it, i++)
		out << "#" << setw(4) << i << "   #" << (*it);
	out << S << endl;
	out.close();
	system("cls");
	SetColor(12, 0);
	gotoxy(10, 10);
	cout << "БАЗА ПОЛЬЗОВАТЕЛЕЙ СОХРАНЕНА В ФАЙЛ!!!" << endl;
	Sleep(2500);
	SetColor(15, 0);
}
