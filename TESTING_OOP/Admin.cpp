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
		int pass = hashing(pas);
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
void Admin::menu_admin(Tested& tes)
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
			control_user(tes);
			break;
		case 2:
			look_statics();
			break;
		case 3:
			add_tests();
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

//добавление тестов, категорий или вопросов
void Admin::add_tests()
{
}

//загрузка тестов из файла
void Admin::load_tests()
{
}

//изменение логина и пароля администратора
void Admin::change_login()
{
	system("cls");
	cout << "РЕДАКТИРОВАНИЕ ДАННЫХ АДМИНИСТРАТОРА:\n" << endl;
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
	int pass = hashing(pas);
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

void Admin::registry_user(Tested& tes)
{
	string log;
	bool lp = true;
	User* user = new User;
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
	int pass = hashing(pas);
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
	control_user(tes);
}

//изменение данных пользователя (тестируемого)
void Admin::control_user(Tested& tes)
{
	while (true)
	{
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
			registry_user(tes);
			break;
		case 2:
			dell_user(tes);
			break;
		case 3:
			edit_user(tes);
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
					print_user_file(tes);
					break;
				case 2:
					print_user(tes);
					system(("pause"));
					break;
				case 3:
					control_user(tes);
					break;
				default:;
				}
			}
		case 5:
			menu_admin(tes);
			break;
		default:;
		}
	}
}

//удаление пользователя
void Admin::dell_user(Tested& tes)
{
	system("cls");
	cout << "УДАЛЕНИЕ ПОЛЬЗОВАТЕЛЯ:\n" << endl;
	print_user(tes);
	cout << "\n";
	string ld;
	cout << "Введите ЛОГИН ПОЛЬЗОВАТЕЛЯ для УДАЛЕНИЯ: ";
	cin >> ld;
	uppercase(ld);
	bool set = false;
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
void Admin::edit_user(Tested& tes)
{
	system("cls");
	cout << "РЕДАКТИРОВАННИЕ ДАННЫХ ПОЛЬЗОВАТЕЛЯ:\n" << endl;
	print_user(tes);
	cout << "\n";
	string ld;
	cout << "Введите ЛОГИН ПОЛЬЗОВАТЕЛЯ для РЕДАКТИРОВАНИЯ: ";
	cin >> ld;
	uppercase(ld);
	bool set = false;
	int pas_p = 0;
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
				int pp = hashing(pas);
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
				control_user(tes);
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
void Admin::print_user_file(Tested& tes) const
{
	ofstream out("ListUsers.txt", ios::out);
	out << "СПИСОК ПОЛЬЗОВАТЕЛЕЙ:\n" << endl;
	int i = 1;
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
void Admin::print_user(Tested& tes) const
{
	system("cls");
	cout << "СПИСОК ПОЛЬЗОВАТЕЛЕЙ:\n" << endl;
	int i = 1;
	tes.base_tested_.sort();
	auto it = tes.base_tested_.begin();
	for (; it != tes.base_tested_.end(); ++it, i++)
		cout << setw(4) << i << *it;
	cout << endl;
}

//просмотр статистики
void Admin::look_statics() const
{
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
	int pass = get_pass_admin();
	out.write(reinterpret_cast<char*>(&pass), sizeof(int));
	out.close();
}

void Admin::load_login_pass()
{
	ifstream fin("PassAdmin.bin", ios::binary | ios::in);
	if (fin.is_open())
	{
		int len_log = 0;
		int pass = 0;
		fin.read(reinterpret_cast<char*>(&len_log), sizeof(int));
		char* buff = new char(len_log + 1);
		fin.read(buff, len_log);
		set_log_admin(buff);
		fin.read(reinterpret_cast<char*>(&pass), sizeof(int));
		set_pass_admin(pass);
	}
	fin.close();
}
