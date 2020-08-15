#include"Tested.h"


void Tested::new_testing(string const& log)
{
	while (true)
	{
		system("cls");
		Maths mat;
		load_testing();
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
	if (base_users_.empty())  //проверка на пустоту
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
		base_users_.insert(make_pair(pass, base_tested_));
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
			if (base_users_.count(pass) != 0)  //проверяем есть ли еще такой пароль в базе
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
				if (base_users_.count(pass) == 0)
					ps = false;
			}
			else
				ps = false;
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
		base_users_.insert(make_pair(pass, base_tested_));
		cout << "ПОЛЬЗОВАТЕЛЬ ДОБАВЛЕН!!!" << endl;
		Sleep(2500);
		system("cls");
		cout << "Теперь можете войти под своим ЛОГИНОМ и ПАРОЛЕМ!!!" << endl;
		Sleep(2500);
		save_base();
		delete user;
	}
}


//меню тестируемого
void Tested::menu_tested(string const& log)
{
	while (true)
	{
		load_testing();
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
void Tested::save_testing()
{
	ofstream out("BaseResult.bin", ios::binary | ios::out);
	int length = result_.size();
	out.write(reinterpret_cast<char*>(&length), sizeof(int));
	for (int i = 0; i < length; i++)
	{
		Results* res = result_.front();
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
	out.close();
}

//загрузить последнее сохраненное тестирование
void Tested::load_testing()
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
			int l_c;
			in.read(reinterpret_cast<char*>(&l_c), sizeof(int));
			char* buff1 = new char(l_c + 1);
			in.read(buff1, l_c);
			res->set_cat(buff1);
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
	ofstream out("BaseTested.bin", ios::binary | ios::out);
	int length = base_tested_.size();
	out.write(reinterpret_cast<char*>(&length), sizeof(int));
	for (int i = 0; i < length; i++)
	{
		User* user = base_tested_.front();
		unsigned int pas = user->get_pass();
		out.write(reinterpret_cast<char*>(&pas), sizeof(unsigned int));
		int l_log = user->get_login().size() + 1;
		out.write(reinterpret_cast<char*>(&l_log), sizeof(int));
		out.write(const_cast<char*>(user->get_login().c_str()), l_log);
		int l_n = user->get_name().size() + 1;
		out.write(reinterpret_cast<char*>(&l_n), sizeof(int));
		out.write(const_cast<char*>(user->get_name().c_str()), l_n);
		int l_em = user->get_email().size() + 1;
		out.write(reinterpret_cast<char*>(&l_em), sizeof(int));
		out.write(const_cast<char*>(user->get_email().c_str()), l_em);
		int l_ph = user->get_phone().size() + 1;
		out.write(reinterpret_cast<char*>(&l_ph), sizeof(int));
		out.write(const_cast<char*>(user->get_phone().c_str()), l_ph);
		base_tested_.pop_front();
	}
	out.close();

}

//загрузка базы тестируемых
void Tested::load_base()
{
	ifstream fin("BaseTested.bin", ios::binary | ios::in);
	if (fin.is_open())
	{
		int length;
		fin.read(reinterpret_cast<char*>(&length), sizeof(int));
		this->base_tested_.clear();
		for (int i = 0; i < length; i++)
		{
			User* user = new User;
			unsigned int pas;
			fin.read(reinterpret_cast<char*>(&pas), sizeof(unsigned int));
			user->set_pass(pas);
			int l_log;
			fin.read(reinterpret_cast<char*>(&l_log), sizeof(int));
			char* buff = new char(l_log + 1);
			fin.read(buff, l_log);
			user->set_login(buff);
			int l_n;
			fin.read(reinterpret_cast<char*>(&l_n), sizeof(int));
			char* buff1 = new char(l_n + 1);
			fin.read(buff1, l_n);
			user->set_name(buff1);
			int l_em;
			fin.read(reinterpret_cast<char*>(&l_em), sizeof(int));
			char* buff2 = new char(l_em + 1);
			fin.read(buff2, l_em);
			user->set_email(buff2);
			int l_ph;
			fin.read(reinterpret_cast<char*>(&l_ph), sizeof(int));
			char* buff3 = new char(l_ph + 1);
			fin.read(buff3, l_ph);
			user->set_phone(buff3);

			this->base_tested_.push_back(user);
			this->base_users_.insert(make_pair(user->get_pass(), base_tested_));
		}

	}
	fin.close();
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
	save_testing();
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
