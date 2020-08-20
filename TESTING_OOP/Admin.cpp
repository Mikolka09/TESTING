#include"Admin.h"

void Admin::shapka_start()
{
	string S(40, '#');
	gotoxy(30, 1);
	SetColor(8, 0);
	cout << S << endl;
	gotoxy(37, 2);
	SetColor(12, 0);
	cout << "ТЕСТОВАЯ БАЗА ТЕСТИРОВАНИЙ" << endl;
	gotoxy(30, 3);
	SetColor(8, 0);
	cout << S << endl << endl;
}


Admin::Admin(const Admin& ob)
{
	log_admin_.clear();
	log_admin_ = ob.log_admin_;
	pass_admin_ = ob.pass_admin_;
}

Admin& Admin::operator=(const Admin& ob)
{
	log_admin_.clear();
	log_admin_ = ob.log_admin_;
	pass_admin_ = 0;
	pass_admin_ = ob.pass_admin_;
	return *this;
}

//регестрация администратора
void Admin::registry_in_admin()
{
	if (log_admin_.empty())
	{
		system("cls");
		shapka_start();
		SetColor(12, 0);
		cout << "РЕГЕСТРАЦИЯ АДМИНИСТРАТОРА:\n" << endl;
		string log;
		SetColor(14, 0);
		cout << "Введите ЛОГИН: ";
		SetColor(15, 0);
		cin >> log;
		uppercase(log);
		string pas;
		bool ad = true;
		while (ad)
		{
			SetColor(14, 0);
			cout << "Введите ПАРОЛЬ (не менее 8-ми символов): ";
			SetColor(15, 0);
			cin >> pas;
			ad = check_size(pas);
		}
		auto pass = hashing(pas);
		this->log_admin_ = log;
		this->pass_admin_ = pass;
		SetColor(12, 0);
		cout << "\nДанные АДМИНИСТРАТОРА сохранены!!!" << endl;
		SetColor(15, 0);
		Sleep(2500);
		save_login_pass();
	}
	else
	{
		system("cls");
		SetColor(12, 0);
		gotoxy(10, 10);
		cout << "ОШИБКА!!! АДМИНИСТРАТОР уже ЗАРЕГЕСТРИРОВАН!!!" << endl;
		SetColor(15, 0);
		Sleep(2500);

	}

}

//меню админитсратора
void Admin::menu_admin()
{
	while (true)
	{
		system("cls");
		shapka_start();
		SetColor(12, 0);
		cout << "МЕНЮ АДМИНИСТРАТОРА:\n" << endl;
		SetColor(14, 0);
		cout << "1. Управление ПОЛЬЗОАВАТЕЛЯМИ\n" << "2. Управление СТАТИСТИКОЙ\n" << "3. Управление ТЕСТАМИ\n"
			<< "4. Управление данными АДМИНИСТРАТОРА\n" << "5. Выход\n" << endl;
		int var1;
		bool v = true;
		while (v)
		{
			SetColor(15, 0);
			cin >> var1;
			cin.ignore();
			if (var1 < 1 || var1 > 5)    // проверка ввода
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
		Maths mat;
		Physics phys;
		Chemistry chem;
		system("cls");
		shapka_start();
		SetColor(12, 0);
		cout << "УПРАВЛЕНИЕ ТЕСТАМИ:\n" << endl;
		SetColor(14, 0);
		cout << "1. Управление тестами по МАТЕМАТИКЕ\n" << "2. Управление тестами по ФИЗИКЕ\n"
			<< "3. Управление тестами по ХИМИИ\n" << "4. Возврат в предыдущее меню\n" << endl;
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
			mat.menu_maths_admin();
			break;
		case 2:
			phys.menu_physics_admin();
			break;
		case 3:
			chem.menu_chem_admin();;
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
		shapka_start();
		SetColor(12, 0);
		cout << "РЕДАКТИРОВАНИЕ ДАННЫХ АДМИНИСТРАТОРА:\n" << endl;
		SetColor(14, 0);
		cout << "Введите новый ЛОГИН: ";
		SetColor(15, 0);
		cin >> log;
		uppercase(log);
		if (get_log_admin() == log)
		{
			SetColor(12, 0);
			cout << "\nТакой ЛОГИН уже есть, введите другой ЛОГИН!!!" << endl;
			SetColor(14, 0);
			Sleep(2500);
		}
		else
			l = false;
	}
	set_log_admin(log);
	SetColor(12, 0);
	cout << "\nЛОГИН ИЗМЕНЕН!!" << endl;
	SetColor(15, 0);
	Sleep(2500);
	bool ad = true;
	string pas;
	//проверка пороля на размер
	while (ad)
	{
		system("cls");
		shapka_start();
		SetColor(12, 0);
		cout << "РЕДАКТИРОВАНИЕ ДАННЫХ АДМИНИСТРАТОРА:\n" << endl;
		SetColor(14, 0);
		cout << "Введите ПАРОЛЬ (не менее 8-ми символов): ";
		SetColor(15, 0);
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
			SetColor(12, 0);
			cout << "\nТакой ПАРОЛЬ уже есть, введите другой ПАРОЛЬ!!!" << endl;
			Sleep(2500);
			system("cls");
			shapka_start();
			SetColor(12, 0);
			cout << "РЕДАКТИРОВАНИЕ ДАННЫХ АДМИНИСТРАТОРА:\n" << endl;
			SetColor(14, 0);
			cout << "Введите новый ПАРОЛЬ: ";
			SetColor(15, 0);
			cin >> pas;
			pass = hashing(pas);
			if (get_log_admin() != log)
				p = false;
		}
		else
			p = false;
	}
	set_pass_admin(pass);
	SetColor(12, 0);
	cout << "\nПАРОЛЬ ИЗМЕНЕН!!" << endl;
	SetColor(15, 0);
	Sleep(2500);
	save_login_pass();
}

void Admin::registry_user()
{
	string log;
	bool lp = true;
	User* user = new User;
	Tested tes;
	tes.load_base();
	//проверяем логин на повторение
	while (lp)
	{
		system("cls");
		shapka_start();
		SetColor(12, 0);
		cout << "РЕГЕСТРАЦИЯ ПОЛЬЗОВАТЕЛЯ:\n" << endl;
		SetColor(14, 0);
		cout << "Введите ЛОГИН: ";
		SetColor(15, 0);
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
		auto it = tes.base_tested_.begin();
		for (; it != tes.base_tested_.end(); ++it)
		{
			if ((*it)->get_pass() == pass)
			{
				SetColor(12, 0);
				cout << "\nТакой ПАРОЛЬ уже есть, введите другой ПАРОЛЬ!!!" << endl;
				SetColor(15, 0);
				Sleep(2500);

				bool d = true;
				while (d)
				{
					system("cls");
					shapka_start();
					SetColor(12, 0);
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
	SetColor(12, 0);
	cout << "Введите номер телефона: ";
	SetColor(15, 0);
	cin >> phone;
	user->set_phone(phone);
	tes.base_tested_.push_back(user);
	SetColor(12, 0);
	cout << "\nПОЛЬЗОВАТЕЛЬ ДОБАВЛЕН!!!" << endl;
	SetColor(15, 0);
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
		shapka_start();
		SetColor(12, 0);
		cout << "УПРАВЛЕНИЕ ПОЛЬЗОВАТЕЛЯМИ:\n" << endl;
		SetColor(14, 0);
		cout << "1. Создание ПОЛЬЗОАВАТЕЛЯ\n"
			<< "2. Удаление ПОЛЬЗОВАТЕЛЯ\n"
			<< "3. Редактирование ПОЛЬЗОВАТЕЛЯ\n"
			<< "4. Печать ПОЛЬЗОВАТЕЛЕЙ\n"
			<< "5. Возврат в предыдущее меню\n" << endl;
		int var;
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
				Sleep(2000);
				SetColor(15, 0);
			}
			else
				v = false;
		}
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
				shapka_start();
				SetColor(12, 0);
				cout << "ПЕЧАТЬ ПОЛЬЗОВАТЕЛЕЙ:\n" << endl;
				SetColor(14, 0);
				cout << "1. Печать в файл ПОЛЬЗОВАТЕЛЕЙ\n"
					<< "2. Печать на экран ПОЛЬЗОВАТЕЛЕЙ\n"
					<< "3. Возврат в предыдущее меню\n" << endl;
				int var1;
				bool v = true;
				while (v)
				{
					SetColor(15, 0);
					cin >> var1;
					cin.ignore();
					if (var1 < 1 || var1 > 3)    // проверка ввода
					{
						SetColor(12, 0);
						cout << "НЕВЕРНО!!! ПОПРОБУЙТЕ ЕЩЕ РАЗ!!!" << endl;
						Sleep(2000);
						SetColor(15, 0);
					}
					else
						v = false;
				}
				switch (var1)
				{
				case 1:
					tes.print_users_file();
					break;
				case 2:
					tes.print_users();
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
	shapka_start();
	SetColor(12, 0);
	cout << "УДАЛЕНИЕ ПОЛЬЗОВАТЕЛЯ:\n" << endl;
	Tested tes;
	tes.load_base();
	SetColor(15, 0);
	tes.print_users();
	cout << "\n";
	string ld;
	SetColor(14, 0);
	cout << "Введите ЛОГИН ПОЛЬЗОВАТЕЛЯ для УДАЛЕНИЯ: ";
	SetColor(15, 0);
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
		SetColor(12, 0);
		gotoxy(10, 10);
		cout << "ПОЛЬЗОВАТЕЛЬ УДАЛЕН!!!" << endl;
		SetColor(15, 0);
		tes.save_base();
		Sleep(2500);
	}
	else
	{
		system("cls");
		SetColor(12, 0);
		gotoxy(10, 10);
		cout << "ТАКОГО ПОЛЬЗОВАТЕЛЯ НЕТ!!!" << endl;
		SetColor(15, 0);
		Sleep(2500);
	}
}

//редактирование пользователя
void Admin::edit_user()
{
	
	system("cls");
	shapka_start();
	SetColor(12, 0);
	cout << "РЕДАКТИРОВАННИЕ ДАННЫХ ПОЛЬЗОВАТЕЛЯ:\n" << endl;
	Tested tes;
	tes.load_base();
	SetColor(15, 0);
	tes.print_users();
	cout << "\n";
	string ld;
	SetColor(14, 0);
	cout << "Введите ЛОГИН ПОЛЬЗОВАТЕЛЯ для РЕДАКТИРОВАНИЯ: ";
	SetColor(15, 0);
	cin >> ld;
	uppercase(ld);
	bool set = false;
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
			//tes.load_base();
			system("cls");
			int var;
			shapka_start();
			SetColor(12, 0);
			cout << "РЕДАКТИРОВАНИЕ ПРОФИЛЯ:\n" << endl;
			SetColor(14, 0);
			cout << "1. Редактировать ЛОГИН\n" << "2. Редактировать ПАРОЛЬ\n" << "3. Редактировать ФИО\n"
				<< "4. Редактировать EMAIL\n" << "5. Редактировать номер ТЕЛЕФОНА\n" << "6. Возврат в предыдущее меню\n" << endl;
			bool v = true;
			while (v)
			{
				SetColor(15, 0);
				cin >> var;
				cin.ignore();
				if (var < 1 || var > 6)    // проверка ввода
				{
					SetColor(12, 0);
					cout << "НЕВЕРНО!!! ПОПРОБУЙТЕ ЕЩЕ РАЗ!!!" << endl;
					Sleep(2000);
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
				string log;
				bool s = true;
				while (s)
				{
					system("cls");
					shapka_start();
					SetColor(12, 0);
					cout << "Редактирование ЛОГИНА:\n" << endl;
					SetColor(14, 0);
					cout << "Введите новый ЛОГИН:";
					SetColor(15, 0);
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
						SetColor(12, 0);
						cout << "\nТакой ЛОГИН уже есть, введите другой ЛОГИН!!!" << endl;
						SetColor(15, 0);
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
				SetColor(12, 0);
				cout << "\nЛОГИН ИЗМЕНЕН!!!" << endl;
				SetColor(15, 0);
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
					shapka_start();
					SetColor(12, 0);
					cout << "Редактирование ПАРОЛЯ:\n" << endl;
					SetColor(14, 0);
					cout << "Введите ПАРОЛЬ (не менее 8-ми символов): ";
					SetColor(15, 0);
					cin >> pas;
					ad = check_size(pas);
				}
				auto pp = hashing(pas);
				bool ps = true;
				while (ps)
				{
					auto it = tes.base_tested_.begin();
					for (; it != tes.base_tested_.end(); ++it)
					{
						if ((*it)->get_pass() == pp)
						{
							SetColor(12, 0);
							cout << "\nТакой ПАРОЛЬ уже есть, введите другой ПАРОЛЬ!!!" << endl;
							SetColor(15, 0);
							Sleep(2500);
							bool d = true;
							while (d)
							{
								system("cls");
								shapka_start();
								SetColor(12, 0);
								cout << "Редактирование ПАРОЛЯ:\n" << endl;
								SetColor(14, 0);
								cout << "Введите ПАРОЛЬ (не менее 8-ми символов): ";
								SetColor(15, 0);
								cin >> pas;
								d = check_size(pas);
							}
							pp = hashing(pas);
							if ((*it)->get_pass() != pp)
								ps = false;
						}
						else
							ps = false;

					}
				}
				auto it = tes.base_tested_.begin();
				for (; it != tes.base_tested_.end(); ++it)
				{
					if ((*it)->get_login() == ld)
						(*it)->set_pass(pp);
				}
				SetColor(12, 0);
				cout << "\nПАРОЛЬ ИЗМЕНЕН!!!" << endl;
				SetColor(15, 0);
				tes.save_base();
				Sleep(2500);
				break;
			}
			case 3:
			{
				system("cls");
				shapka_start();
				char* n = new char;
				SetColor(12, 0);
				cout << "Редактирование ФИО:\n" << endl;
				SetColor(14, 0);
				cout << "Введите новые ФИО: ";
				SetColor(15, 0);
				cin.getline(n, 100);
				string name = n;
				auto it = tes.base_tested_.begin();
				for (; it != tes.base_tested_.end(); ++it)
				{
					if ((*it)->get_login() == ld)
						(*it)->set_name(name);
				}
				SetColor(12, 0);
				cout << "\nФИО ИЗМЕНЕН!!!" << endl;
				SetColor(15, 0);
				tes.save_base();
				Sleep(2500);
				break;
			}
			case 4:
			{
				system("cls");
				shapka_start();
				SetColor(12, 0);
				cout << "Редактирование EMAIL:\n" << endl;
				SetColor(14, 0);
				cout << "Введите новый EMAIL: ";
				SetColor(15, 0);
				string em;
				cin >> em;
				auto it = tes.base_tested_.begin();
				for (; it != tes.base_tested_.end(); ++it)
				{
					if ((*it)->get_login() == ld)
						(*it)->set_email(em);
				}
				SetColor(12, 0);
				cout << "\nEMAIL ИЗМЕНЕН!!!" << endl;
				SetColor(15, 0);
				tes.save_base();
				Sleep(2500);
				break;
			}
			case 5:
			{
				system("cls");
				shapka_start();
				SetColor(12, 0);
				cout << "Редактирование номера ТЕЛЕФОНА:\n" << endl;
				SetColor(14, 0);
				cout << "Введите новый номер ТЕЛЕФОНА:";
				SetColor(15, 0);
				string ph;
				cin >> ph;
				auto it = tes.base_tested_.begin();
				for (; it != tes.base_tested_.end(); ++it)
				{
					if ((*it)->get_login() == ld)
						(*it)->set_phone(ph);
				}
				SetColor(12, 0);
				cout << "\nТЕЛЕФОН ИЗМЕНЕН!!!" << endl;
				SetColor(15, 0);
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
		SetColor(12, 0);
		gotoxy(10, 10);
		cout << "ТАКОГО ПОЛЬЗОВАТЕЛЯ НЕТ!!!" << endl;
		SetColor(15, 0);
		Sleep(2500);
	}
}


//просмотр статистики
void Admin::look_statics()
{
	while (true)
	{
		Tested tes;
		tes.load_results();
		tes.load_base();
		system("cls");
		shapka_start();
		SetColor(12, 0);
		cout << "УПРАВЛЕНИЕ СТАТИСТИКОЙ:\n" << endl;
		SetColor(14, 0);
		cout << "1. Результаты в ОБЩЕМ\n"
			<< "2. Результаты по конкретным ТЕСТАМ\n"
			<< "3. Результаты по конкретным ПОЛЬЗОВАТЕЛЯМ\n"
			<< "4. Печать результатов в ФАЙЛ\n"
			<< "5. Возврат в предыдущее меню\n" << endl;
		int var;
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
				Sleep(2000);
				SetColor(15, 0);
			}
			else
				v = false;
		}
		switch (var)
		{
		case 1:
			tes.print_all_results();
			system("pause");
			break;
		case 2:
		{
			system("cls");
			string cat;
			shapka_start();
			SetColor(12, 0);
			cout << "РЕЗУЛЬТАТЫ ПО КОНКРЕТНЫМ ТЕСТАМ:\n" << endl;
			SetColor(14, 0);
			cout << "1. АЛГЕБРА\n" << "2. ГЕОМЕТРИЯ\n" << "3. КВАНТОВАЯ ФИЗИКА\n"
				<< "4. МЕХАНИКА\n" << "5. ОРГАНИЧЕСКАЯ ХИМИЯ\n" << "6. НЕОРГАНИЧЕСКАЯ ХИМИЯ\n"
				<< "7. Возврат в предыдущее меню\n" << endl;
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
					Sleep(2000);
					SetColor(15, 0);
				}
				else
					v = false;
			}
			switch (var)
			{
			case 1: cat = "АЛГЕБРА"; tes.print_result_tests(cat); system("pause"); break;
			case 2: cat = "ГЕОМЕТРИЯ"; tes.print_result_tests(cat); system("pause"); break;
			case 3: cat = "КВАНТОВАЯ"; tes.print_result_tests(cat); system("pause"); break;
			case 4: cat = "МЕХАНИКА"; tes.print_result_tests(cat); system("pause"); break;
			case 5: cat = "ОРГАНИЧЕСКАЯ"; tes.print_result_tests(cat); system("pause"); break;
			case 6: cat = "НЕОРГАНИЧЕСКАЯ"; tes.print_result_tests(cat); system("pause"); break;
			default:;
			}
			break;
		}
		case 3:
			tes.print_result_user(); 
			system("pause"); 
			break;
		case 4:
			tes.print_all_result_file();
			break;
		case 5:
			menu_admin();
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
