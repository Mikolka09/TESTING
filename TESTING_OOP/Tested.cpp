#include"Tested.h"


void Tested::new_testing(string const& log)
{
	while (true)
	{
		system("cls");
		Maths mat;
		load_results();
		cout << "МЕНЮ ПОЛЬЗОВАТЕЛЯ ПО СДАЧИ ТЕСТОВ:\n" << endl;
		cout << "1. Сдать тест по МАТЕМАТИКЕ\n"
			<< "2. Сдать тест по ФИЗИКЕ\n"
			<< "3. Сдать тест по ХИМИИ\n"
			<< "4. Возврат в предыдущее меню\n" << endl;
		int var1;
		cin >> var1;
		cin.ignore();
		switch (var1)
		{
		case 1:
			mat.menu_maths_user(log);
			break;
		case 2:
			//mat.menu_phisics_user(log);
			break;
		case 3:
			//mat.menu_chemistry_user(log);
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
	cout << "РЕГЕСТРАЦИЯ ПОЛЬЗОВАТЕЛЯ:\n" << endl;
	User* user = new User;
	Results* res = new Results;
	if (base_tested_.empty())  //проверка на пустоту
	{
		string log;
		cout << "Введите ЛОГИН: ";
		cin >> log;
		uppercase(log);
		user->set_login(log);
		string pas;
		bool ad = true;
		//проверка пороля на размер
		while (ad)
		{
			cout << "Введите ПАРОЛЬ (не менее 8-ми символов): ";
			cin >> pas;
			ad = check_size(pas);  //проверка на размер пароля
		}
		auto pass = hashing(pas);  //шифрование пароля
		user->set_pass(pass);
		char* n = new char;
		cin.ignore();
		cout << "Введите ФИО: ";
		cin.getline(n, 100);
		string name = n;
		user->set_name(name);
		string email;
		cout << "Введите электронный адрес: ";
		cin >> email;
		user->set_email(email);
		string phone;
		cout << "Введите номер телефона: ";
		cin >> phone;
		user->set_phone(phone);
		base_tested_.push_back(user);
		cout << "ПОЛЬЗОВАТЕЛЬ ДОБАВЛЕН!!!" << endl;
		Sleep(2500);
		system("cls");
		cout << "Теперь можете войти под своим ЛОГИНОМ и ПАРОЛЕМ!!!" << endl;
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
			cout << "РЕГЕСТРАЦИЯ ПОЛЬЗОВАТЕЛЯ:\n" << endl;
			cout << "Введите ЛОГИН: ";
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
				cout << "Такой ЛОГИН уже есть, введите другой ЛОГИН!!!" << endl;
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
			cout << "Введите ПАРОЛЬ (не менее 8-ми символов): ";
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
					cout << "Такой ПАРОЛЬ уже есть, введите другой ПАРОЛЬ!!!" << endl;
					Sleep(2500);
					system("cls");
					bool d = true;
					while (d)
					{
						cout << "РЕГЕСТРАЦИЯ ПОЛЬЗОВАТЕЛЯ:\n" << endl;
						cout << "Введите ПАРОЛЬ (не менее 8-ми символов): ";
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
		cout << "Введите ФИО: ";
		cin.getline(n, 100);
		string name = n;
		user->set_name(name);
		string email;
		cout << "Введите электронный адрес: ";
		cin >> email;
		user->set_email(email);
		string phone;
		cout << "Введите номер телефона: ";
		cin >> phone;
		user->set_phone(phone);
		base_tested_.push_back(user);
		//base_users_.insert(make_pair(pass, base_tested_));
		cout << "ПОЛЬЗОВАТЕЛЬ ДОБАВЛЕН!!!" << endl;
		Sleep(2500);
		system("cls");
		cout << "Теперь можете войти под своим ЛОГИНОМ и ПАРОЛЕМ!!!" << endl;
		Sleep(2500);
		save_base();
	}
}

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
		//load_results();
		Testing ts;
		system("cls");
		cout << "МЕНЮ ПОЛЬЗОВАТЕЛЯ:\n" << endl;
		cout << "1. Сдать ТЕСТИРОВАНИЕ\n"
			<< "2. Просмотор результатов ТЕСТИРОВАНИЯ\n"
			<< "3. Печать результатов ТЕСТИРОВАНИЯ в файл\n"
			<< "4. Возврат в предыдущее меню\n" << endl;
		int var1;
		cin >> var1;
		cin.ignore();
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
void Tested::print_result(string const& log) const
{
	system("cls");
	cout << "РЕЗУЛЬТАТЫ ТЕСТИРОВАНИЯ\n" << endl;
	string lg = log;
	auto it = result_.begin();
	for (; it != result_.end(); ++it)
	{
		if ((*it)->get_log().c_str() == lg)
			cout << (*it);
	}
}


//сохранить промежуточное тестирование
void Tested::save_results()
{
	ofstream out("BaseResult.bin", ios::binary | ios::out);
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
	out.close();
}

//загрузить последнее сохраненное тестирование
void Tested::load_results()
{
	ifstream in("BaseResult.bin", ios::binary | ios::in);
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
	in.close();
}


//сохранение базы тестируемых
void Tested::save_base()
{
	ofstream out("BaseTested.txt", ios::out);
	user_ = new User;
	while (true)
	{
		user_ = base_tested_.front();
		out << "\n";
		out << user_->get_login() << endl;;
		out << user_->get_pass() << endl;
		out << user_->get_name() << endl;
		out << user_->get_email() << endl;
		out << user_->get_phone() << endl;;
		base_tested_.pop_front();
		if (base_tested_.empty())
			break;
	}
	delete[] user_;
	out.close();

	//
	//ofstream out("BaseTested.bin", ios::binary | ios::out);
	//int length = base_tested_.size();
	//out.write(reinterpret_cast<char*>(&length), sizeof(int));
	//user_ = new User;
	//for (int i = 0; i < length; i++)
	//{
	//	user_ = base_tested_.front();
	//	unsigned int pas = user_->get_pass();
	//	out.write(reinterpret_cast<char*>(&pas), sizeof(unsigned int));
	//	int l_log = user_->get_login().size() + 1;
	//	out.write(reinterpret_cast<char*>(&l_log), sizeof(int));
	//	out.write(const_cast<char*>(user_->get_login().c_str()), l_log);
	//	int l_n = user_->get_name().size() + 1;
	//	out.write(reinterpret_cast<char*>(&l_n), sizeof(int));
	//	out.write(const_cast<char*>(user_->get_name().c_str()), l_n);
	//	int l_em = user_->get_email().size() + 1;
	//	out.write(reinterpret_cast<char*>(&l_em), sizeof(int));
	//	out.write(const_cast<char*>(user_->get_email().c_str()), l_em);
	//	int l_ph = user_->get_phone().size() + 1;
	//	out.write(reinterpret_cast<char*>(&l_ph), sizeof(int));
	//	out.write(const_cast<char*>(user_->get_phone().c_str()), l_ph);
	//	base_tested_.pop_front();
	//}
	////delete user;
	//out.close();

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
			user_ = new User;
			char lg[50];
			fin >> lg;
			int l_lg = strlen(lg) + 1;
			char* buff = new char(l_lg + 1);
			strcpy(buff, lg);
			user_->set_login(buff);
			unsigned int pas;
			fin >> pas;
			fin.get();
			user_->set_pass(pas);
			//fin.get();
			char ln[50];
			fin.getline(ln,50);
			int l_ln = strlen(ln) + 1;
			char* buff1 = new char(l_ln + 1);
			strcpy(buff1, ln);
			user_->set_name(buff1);
			char le[50];
			fin >> le;
			int l_le = strlen(le) + 1;
			char* buff2 = new char(l_le + 1);
			strcpy(buff2, le);
			user_->set_email(buff2);
			char lp[50];
			fin.ignore();
			fin.getline(lp, 50);
			int l_lp = strlen(lp) + 1;
			char* buff3 = new char(l_lp + 1);
			strcpy(buff3, lp);
			user_->set_phone(buff3);
			base_tested_.push_back(user_);
			fin.get();
			if(fin.eof())
				break;
		}
	}
	fin.close();

	//ifstream fin("BaseTested.bin", ios::binary | ios::in);
	//if (fin.is_open())
	//{
	//	int length;
	//	fin.read(reinterpret_cast<char*>(&length), sizeof(int));
	//	base_tested_.clear();
	//	user_ = new User;
	//	for (int i = 0; i < length; i++)
	//	{
	//		unsigned int pas;
	//		fin.read(reinterpret_cast<char*>(&pas), sizeof(unsigned int));
	//		user_->set_pass(pas);
	//		int l_log;
	//		fin.read(reinterpret_cast<char*>(&l_log), sizeof(int));
	//		char* buff = new char(l_log + 1);
	//		fin.read(buff, l_log);
	//		user_->set_login(buff);
	//		int l_n;
	//		fin.read(reinterpret_cast<char*>(&l_n), sizeof(int));
	//		char* buff1 = new char(l_n + 1);
	//		fin.read(buff1, l_n);
	//		user_->set_name(buff1);
	//		int l_em;
	//		fin.read(reinterpret_cast<char*>(&l_em), sizeof(int));
	//		char* buff2 = new char(l_em + 1);
	//		fin.read(buff2, l_em);
	//		user_->set_email(buff2);
	//		int l_ph;
	//		fin.read(reinterpret_cast<char*>(&l_ph), sizeof(int));
	//		char* buff3 = new char(l_ph + 1);
	//		fin.read(buff3, l_ph);
	//		user_->set_phone(buff3);
	//		
	//		base_tested_.push_back(user_);
	//		//base_users_.insert(make_pair(user_->get_pass(), base_tested_));
	//	}
	//	//delete user;
	//}
	//fin.close();
}

//проверка и добавление нового результата 
void Tested::get_res_base(Results*& res)
{
	string log = res->get_log();
	if (base_results_.count(log))
	{
		auto iter = base_results_.find(log);
		(*iter).second.push_back(res);
	}
	else
	{
		result_.push_back(res);
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
void Tested::print_result_file(string const& log) const
{
	system("cls");
	cout << "СОХРАНЕНИЕ РЕЗУЛЬТАТОВ В ФАЙЛ\n" << endl;
	cout << "Введите имя файла: ";
	string file;
	cin >> file;
	file = file + ".txt";
	ofstream out(file, ios::out);
	out << "РЕЗУЛЬТАТЫ ТЕСТИРОВАНИЯ\n" << endl;
	string lg = log;
	auto it = result_.begin();
	for (; it != result_.end(); ++it)
	{
		if ((*it)->get_log().c_str() == lg)
			out << (*it);
	}
	out.close();
	system("cls");
	cout << "РЕЗУЛЬТАТЫ СОХРАНЕНЫ В ФАЙЛ!!!" << endl;
}

//просмотр базы пользователей
void Tested::print_users()
{
	system("cls");
	cout << "СПИСОК ПОЛЬЗОВАТЕЛЕЙ:\n" << endl;
	int i = 1;
	//base_tested_.sort();
	auto it = base_tested_.begin();
	for (; it != base_tested_.end(); ++it, i++)
		cout << setw(4) << i << (*it);
	cout << endl;
}

//печать базы пользователей в файл
void Tested::print_users_file()
{
	system("cls");
	cout << "Введите название файла для печати базы пользователей: ";
	string file;
	cin >> file;
	file += ".txt";
	ofstream out(file, ios::out);
	out << "СПИСОК ПОЛЬЗОВАТЕЛЕЙ:\n" << endl;
	int i = 1;
	base_tested_.sort();
	auto it = base_tested_.begin();
	for (; it != base_tested_.end(); ++it, i++)
		out << setw(4) << i << (*it);
	out << endl;
}
