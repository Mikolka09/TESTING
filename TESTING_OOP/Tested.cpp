#include"Tested.h"




void Tested::new_testing(const list<Results*>& res)
{
	while (true)
	{
		system("cls");
		Maths mat;
		list<Results*> res = get_result();
		cout << "МЕНЮ ПОЛЬЗОВАТЕЛЯ ПО СДАЧИ ТЕСТОВ:\n" << endl;
		cout << "1. Сдать тест по МАТЕМАТИКЕ\n"
			<< "2. Сдать тест по ФИЗИКЕ\n"
			<< "3. Сдать тест по ХИМИИ\n"
			<< "4. Просмотреть текущий результат\n"
			<< "5. Возврат в предыдущее меню\n" << endl;
		int var1;
		cin >> var1;
		cin.ignore();
		switch (var1)
		{
		case 1:
			mat.menu_maths_user(res);
			break;
		case 2:
			//mat.menu_phisics_user(res);
			break;
		case 3:
			//mat.menu_chemistry_user(res);
			break;
		case 4:
			print_result(res);
			break;
		case 5:
			menu_tested(res);
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
		res->set_log(log);
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
		result_.push_back(res);
		base_users_.insert(make_pair(pass, base_tested_));
		base_results_.insert(make_pair(log, result_));
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
		res->set_log(log);
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
		result_.push_back(res);
		base_users_.insert(make_pair(pass, base_tested_));
		base_results_.insert(make_pair(log, result_));
		cout << "ПОЛЬЗОВАТЕЛЬ ДОБАВЛЕН!!!" << endl;
		Sleep(2500);
		system("cls");
		cout << "Теперь можете войти под своим ЛОГИНОМ и ПАРОЛЕМ!!!" << endl;
		Sleep(2500);
		save_base();

	}
}


//меню тестируемого
void Tested::menu_tested(const list<Results*>& res)
{
	while (true)
	{
		system("cls");
		cout << "МЕНЮ ПОЛЬЗОВАТЕЛЯ:\n" << endl;
		cout << "1. Сдать ТЕСТИРОВАНИЕ\n"
			<< "2. Просмотор результатов ТЕСТИРОВАНИЯ\n"
			<< "3. Сохранить промежуточное ТЕСТИРОВАНИЕ\n"
			<< "4. Загрузить последнее сохраненное ТЕСТИРОВАНИЕ\n"
			<< "5. Выход\n" << endl;
		int var1;
		cin >> var1;
		cin.ignore();
		switch (var1)
		{
		case 1:
			new_testing(res);
			break;
		case 2:
			print_result(res);
			system("pause");
			break;
		case 3:
			save_testing();
			break;
		case 4:
			load_testing();
			break;
		case 5:
			exit(0);
		default:;
		}
	}
}

//просмотр результата тестирования
void Tested::print_result(const list<Results*>& res) const
{
	system("cls");
	cout << "РЕЗУЛЬТАТЫ ТЕСТИРОВАНИЯ\n" << endl;
	string lg;
	cout << "Введите свой ЛОГИН: ";
	cin >> lg;
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
}

//загрузить последнее сохраненное тестирование
void Tested::load_testing()
{
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
