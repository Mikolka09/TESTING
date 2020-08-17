#include"Admin.h"



//регестрация администратора
void Admin::registry_in_admin()
{
	if (log_admin_.empty())
	{
		system("cls");
		cout << "РЕГЕСТРАЦИЯ АДМИНИСТРАТОРА:\n" << endl;
		string log;
		cout << "Введите ЛОГИН: ";
		cin >> log;
		uppercase(log);
		string pas;
		bool ad = true;
		while (ad)
		{
			cout << "Введите ПАРОЛЬ (не менее 8-ми символов): ";
			cin >> pas;
			ad = check_size(pas);
		}
		auto pass = hashing(pas);
		this->log_admin_ = log;
		this->pass_admin_ = pass;
		cout << "Данные АДМИНИСТРАТОРА сохранены!!!" << endl;
		Sleep(2500);
		save_login_pass();
	}
	else
	{
		system("cls");
		cout << "ОШИБКА!!! АДМИНИСТРАТОР уже ЗАРЕГЕСТРИРОВАН!!!" << endl;
		Sleep(2500);

	}

}

//меню админитсратора
void Admin::menu_admin()
{
	while (true)
	{
		system("cls");
		cout << "МЕНЮ АДМИНИСТРАТОРА:\n" << endl;
		cout << "1. Управление ПОЛЬЗОАВАТЕЛЯМИ\n" << "2. Управление СТАТИСТИКОЙ\n" << "3. Управление ТЕСТАМИ\n"
			<< "4. Управление данными АДМИНИСТРАТОРА\n" << "5. Выход\n" << endl;
		int var1;
		cin >> var1;
		cin.ignore();
		switch (var1)
		{
		case 1:
			control_user();
			break;
		case 2:
			look_statics();
			break;
		case 3:
			control_tests();
			break;
		case 4:
			change_login();
			break;
		case 5:
			exit(0);
		default:;
		}
	}
}

//управление тестами
void Admin::control_tests()
{
	while (true)
	{
		Tested tes;
		Maths mat_;
		system("cls");
		cout << "УПРАВЛЕНИЕ ТЕСТАМИ:\n" << endl;
		cout << "1. Управление тестами по МАТЕМАТИКЕ\n" << "2. Управление тестами по ФИЗИКЕ\n"
			<< "3. Управление тестами по ХИМИИ\n" << "4. Возврат в предыдущее меню\n" << endl;
		int var1;
		cin >> var1;
		cin.ignore();
		switch (var1)
		{
		case 1:
			mat_.menu_maths_admin();
			break;
		case 2:
			//mat_.menu_maths_admin();
			break;
		case 3:
			//mat_.menu_maths_admin();
			break;
		case 4:
			menu_admin();
			break;
		default:;
		}
	}
}

//загрузка тестов из файла
void Admin::load_tests()
{
}

//изменение логина и пароля администратора
void Admin::change_login()
{
	bool l = true;
	string log;
	while (l)
	{
		system("cls");
		cout << "РЕДАКТИРОВАНИЕ ДАННЫХ АДМИНИСТРАТОРА:\n" << endl;
		cout << "Введите новый ЛОГИН: ";
		cin >> log;
		uppercase(log);
		if (get_log_admin() == log)
		{
			cout << "Такой ЛОГИН уже есть, введите другой ЛОГИН!!!" << endl;
			Sleep(2500);
		}
		else
			l = false;
	}
	set_log_admin(log);
	cout << "ЛОГИН ИЗМЕНЕН!!" << endl;
	Sleep(2500);
	bool ad = true;
	string pas;
	//проверка пороля на размер
	while (ad)
	{
		system("cls");
		cout << "РЕДАКТИРОВАНИЕ ДАННЫХ АДМИНИСТРАТОРА:\n" << endl;
		cout << "Введите ПАРОЛЬ (не менее 8-ми символов): ";
		cin >> pas;
		ad = check_size(pas);
	}
	auto pass = hashing(pas);
	bool p = true;
	//проверка пароля на повторение
	while (p)
	{
		if (get_pass_admin() == pass)
		{
			cout << "Такой ПАРОЛЬ уже есть, введите другой ПАРОЛЬ!!!" << endl;
			Sleep(2500);
			system("cls");
			cout << "РЕДАКТИРОВАНИЕ ДАННЫХ АДМИНИСТРАТОРА:\n" << endl;
			cout << "Введите новый ПАРОЛЬ: ";
			cin >> pas;
			pass = hashing(pas);
			if (get_log_admin() != log)
				p = false;
		}
		else
			p = false;
	}
	set_pass_admin(pass);
	cout << "ПАРОЛЬ ИЗМЕНЕН!!" << endl;
	Sleep(2500);
	save_login_pass();
}

void Admin::registry_user()
{
	string log;
	bool lp = true;
	User* user = new User;
	Tested tes;
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
		auto it = tes.base_tested_.begin();
		for (; it != tes.base_tested_.end(); ++it)
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
		if (tes.base_users_.count(pass) != 0)  //проверяем есть ли еще такой пароль в базе
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
			if (tes.base_users_.count(pass) == 0)
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
	tes.base_tested_.push_back(user);
	tes.base_users_.insert(make_pair(pass, tes.base_tested_));
	cout << "ПОЛЬЗОВАТЕЛЬ ДОБАВЛЕН!!!" << endl;
	Sleep(2500);
	tes.save_base();
	control_user();
}

//изменение данных пользователя (тестируемого)
void Admin::control_user()
{
	while (true)
	{
		Tested tes;
		tes.load_base();
		system("cls");
		cout << "УПРАВЛЕНИЕ ПОЛЬЗОВАТЕЛЯМИ:\n" << endl;
		cout << "1. Создание ПОЛЬЗОАВАТЕЛЯ\n"
			<< "2. Удаление ПОЛЬЗОВАТЕЛЯ\n"
			<< "3. Редактирование ПОЛЬЗОВАТЕЛЯ\n"
			<< "4. Печать ПОЛЬЗОВАТЕЛЕЙ\n"
			<< "5. Возврат в предыдущее меню\n" << endl;
		int var;
		cin >> var;
		cin.ignore();
		switch (var)
		{
		case 1:
			registry_user();
			break;
		case 2:
			dell_user();
			break;
		case 3:
			edit_user();
			break;
		case 4:
			while (true)
			{
				system("cls");
				cout << "ПЕЧАТЬ ПОЛЬЗОВАТЕЛЕЙ:\n" << endl;
				cout << "1. Печать в файл ПОЛЬЗОВАТЕЛЕЙ\n"
					<< "2. Печать на экран ПОЛЬЗОВАТЕЛЕЙ\n"
					<< "3. Возврат в предыдущее меню\n" << endl;
				int var1;
				cin >> var1;
				cin.ignore();
				switch (var1)
				{
				case 1:
					print_user_file();
					break;
				case 2:
					print_user();
					system(("pause"));
					break;
				case 3:
					control_user();
					break;
				default:;
				}
			}
		case 5:
			menu_admin();
			break;
		default:;
		}
	}
}

//удаление пользователя
void Admin::dell_user()
{
	system("cls");
	cout << "УДАЛЕНИЕ ПОЛЬЗОВАТЕЛЯ:\n" << endl;
	print_user();
	cout << "\n";
	string ld;
	cout << "Введите ЛОГИН ПОЛЬЗОВАТЕЛЯ для УДАЛЕНИЯ: ";
	cin >> ld;
	uppercase(ld);
	bool set = false;
	Tested tes;
	auto it = tes.base_tested_.begin();
	for (; it != tes.base_tested_.end(); ++it)
	{
		if ((*it)->get_login() == ld)
		{
			it = tes.base_tested_.erase(it);
			set = true;
		}
	}
	if (set)
	{
		system("cls");
		cout << "ПОЛЬЗОВАТЕЛЬ УДАЛЕН!!!" << endl;
		tes.save_base();
		Sleep(2500);
	}
	else
	{
		system("cls");
		cout << "ТАКОГО ПОЛЬЗОВАТЕЛЯ НЕТ!!!" << endl;
		Sleep(2500);
	}
}

//редактирование пользователя
void Admin::edit_user()
{
	system("cls");
	cout << "РЕДАКТИРОВАННИЕ ДАННЫХ ПОЛЬЗОВАТЕЛЯ:\n" << endl;
	print_user();
	cout << "\n";
	string ld;
	cout << "Введите ЛОГИН ПОЛЬЗОВАТЕЛЯ для РЕДАКТИРОВАНИЯ: ";
	cin >> ld;
	uppercase(ld);
	bool set = false;
	Tested tes;
	unsigned int pas_p = 0;
	auto it = tes.base_tested_.begin();
	for (; it != tes.base_tested_.end(); ++it)
	{
		if ((*it)->get_login() == ld)
		{
			set = true;
			pas_p = (*it)->get_pass();
		}

	}
	if (set)
	{
		while (true)
		{
			tes.load_base();
			system("cls");
			int var;
			cout << "РЕДАКТИРОВАНИЕ ПРОФИЛЯ:\n" << endl;
			cout << "1. Редактировать ЛОГИН\n" << "2. Редактировать ПАРОЛЬ\n" << "3. Редактировать ФИО\n"
				<< "4. Редактировать EMAIL\n" << "5. Редактировать номер ТЕЛЕФОНА\n" << "6. Возврат в предыдущее меню\n" << endl;
			cin >> var;
			cin.ignore();
			switch (var)
			{
			case 1:
			{
				system("cls");
				string log;
				bool s = true;
				while (s)
				{
					system("cls");
					cout << "Редактирование ЛОГИНА:\n" << endl;
					cout << "Введите новый ЛОГИН:";
					cin >> log;
					uppercase(log);
					int count = 0;
					//поиск одинаковых логинов со счетчиком
					auto iterator = tes.base_tested_.begin();
					for (; iterator != tes.base_tested_.end(); ++iterator)
					{
						if ((*iterator)->get_login() == log)
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
						s = false;
				}
				auto it = tes.base_tested_.begin();
				for (; it != tes.base_tested_.end(); ++it)
				{
					if ((*it)->get_login() == ld)
					{
						(*it)->set_login(log);
					}
				}
				ld = log;
				cout << "ЛОГИН ИЗМЕНЕН!!!" << endl;
				tes.save_base();
				Sleep(2500);
				break;
			}
			case 2:
			{
				string pas;
				bool ad = true;
				while (ad)
				{
					system("cls");
					cout << "Редактирование ПАРОЛЯ:\n" << endl;
					cout << "Введите ПАРОЛЬ (не менее 8-ми символов): ";
					cin >> pas;
					ad = check_size(pas);
				}
				auto pp = hashing(pas);
				bool ps = true;
				while (ps)
				{
					if (tes.base_users_.count(pp) != 0)  //проверяем есть ли еще такой пароль в базе
					{
						cout << "Такой ПАРОЛЬ уже есть, введите другой ПАРОЛЬ!!!" << endl;
						Sleep(2500);
						bool d = true;
						while (d)
						{
							system("cls");
							cout << "Редактирование ПАРОЛЯ:\n" << endl;
							cout << "Введите ПАРОЛЬ (не менее 8-ми символов): ";
							cin >> pas;
							d = check_size(pas);
						}
						pp = hashing(pas);
						if (tes.base_users_.count(pp) == 0)
							ps = false;
					}
					else
						ps = false;
				}
				auto it = tes.base_tested_.begin();
				for (; it != tes.base_tested_.end(); ++it)
				{
					if ((*it)->get_login() == ld)
						(*it)->set_pass(pp);
				}
				cout << "ПАРОЛЬ ИЗМЕНЕН!!!" << endl;
				tes.save_base();
				Sleep(2500);
				break;
			}
			case 3:
			{
				system("cls");
				char* n = new char;
				cout << "Редактирование ФИО:\n" << endl;
				cout << "Введите новые ФИО: ";
				cin.getline(n, 100);
				string name = n;
				auto it = tes.base_tested_.begin();
				for (; it != tes.base_tested_.end(); ++it)
				{
					if ((*it)->get_login() == ld)
						(*it)->set_name(name);
				}
				cout << "ФИО ИЗМЕНЕН!!!" << endl;
				tes.save_base();
				Sleep(2500);
				break;
			}
			case 4:
			{
				system("cls");
				cout << "Редактирование EMAIL:\n" << endl;
				cout << "Введите новый EMAIL: ";
				string em;
				cin >> em;
				auto it = tes.base_tested_.begin();
				for (; it != tes.base_tested_.end(); ++it)
				{
					if ((*it)->get_login() == ld)
						(*it)->set_email(em);
				}
				cout << "EMAIL ИЗМЕНЕН!!!" << endl;
				tes.save_base();
				Sleep(2500);
				break;
			}
			case 5:
			{
				system("cls");
				cout << "Редактирование номера ТЕЛЕФОНА:\n" << endl;
				cout << "Введите новый номер ТЕЛЕФОНА:";
				string ph;
				cin >> ph;
				auto it = tes.base_tested_.begin();
				for (; it != tes.base_tested_.end(); ++it)
				{
					if ((*it)->get_login() == ld)
						(*it)->set_phone(ph);
				}
				cout << "ТЕЛЕФОН ИЗМЕНЕН!!!" << endl;
				tes.save_base();
				Sleep(2500);
				break;
			}
			case 6:
				control_user();
				break;
			default:
				break;
			}
		}
	}
	else
	{
		system("cls");
		cout << "ТАКОГО ПОЛЬЗОВАТЕЛЯ НЕТ!!!" << endl;
		Sleep(2500);
	}
}

//печать пользователей в файл
void Admin::print_user_file() const
{
	ofstream out("ListUsers.txt", ios::out);
	out << "СПИСОК ПОЛЬЗОВАТЕЛЕЙ:\n" << endl;
	int i = 1;
	Tested tes;
	tes.base_tested_.sort();
	auto it = tes.base_tested_.begin();
	for (; it != tes.base_tested_.end(); ++it, i++)
		out << setw(4) << i << *it;
	out << endl;
	out.close();
	system("cls");
	cout << "СПИСОК ПОЛЬЗОВАТЕЛЕЙ НАПЕЧАТАН В ФАЙЛ!!!\n" << endl;
	Sleep(2500);

}

//печать пользователей на экран
void Admin::print_user() const
{
	system("cls");
	cout << "СПИСОК ПОЛЬЗОВАТЕЛЕЙ:\n" << endl;
	int i = 1;
	Tested tes;
	tes.base_tested_.sort();
	tes.get_base().sort();
	auto it = tes.get_base().begin();
	for (; it != tes.get_base().end(); ++it, i++)
		cout << setw(4) << i << (*it);
	cout << endl;
}


//просмотр статистики
void Admin::look_statics() const
{
	while (true)
	{
		Tested tes;
		tes.load_results();
		tes.load_base();
		system("cls");
		cout << "УПРАВЛЕНИЕ СТАТИСТИКОЙ:\n" << endl;
		cout << "1. Результаты в ОБЩЕМ\n"
			<< "2. Результаты по конкретным ТЕСТАМ\n"
			<< "3. Результаты по конкретным ПОЛЬЗОВАТЕЛЯМ\n"
			<< "4. Печать результатов в ФАЙЛ\n"
			<< "5. Возврат в предыдущее меню\n" << endl;
		int var;
		cin >> var;
		cin.ignore();
		switch (var)
		{
		case 1:
		{
			system("cls");
			cout << "ОБЩАЯ БАЗА ДАННЫХ РЕЗУЛЬТАТОВ ТЕСТОВ\n" << endl;
			string log = "NICK";
			auto it = tes.get_base_users().begin();
			cout << (*it).first << " " << (*it).second.front();
			/*auto it_2 = tes.get_base_results().end();
			for (; it != it_2; ++it)
			{
				cout << it->first << " " << it->second.front() << endl;
			}*/
			break;
		}
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		default:;
			
		}
	}
}

//сохранение статистики в файл
void Admin::save_statics()
{
}

void Admin::save_login_pass()
{
	ofstream out("PassAdmin.bin", ios::binary | ios::out);
	int len_log = get_log_admin().size() + 1;
	out.write(reinterpret_cast<char*>(&len_log), sizeof(int));
	out.write(const_cast<char*>(get_log_admin().c_str()), len_log);
	unsigned int pass = get_pass_admin();
	out.write(reinterpret_cast<char*>(&pass), sizeof(unsigned int));
	out.close();
}

void Admin::load_login_pass()
{
	ifstream fin("PassAdmin.bin", ios::binary | ios::in);
	if (fin.is_open())
	{
		int len_log = 0;
		unsigned int pass = 0;
		fin.read(reinterpret_cast<char*>(&len_log), sizeof(int));
		char* buff = new char(len_log + 1);
		fin.read(buff, len_log);
		set_log_admin(buff);
		fin.read(reinterpret_cast<char*>(&pass), sizeof(unsigned int));
		set_pass_admin(pass);
	}
	fin.close();
}
