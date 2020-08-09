#include"Tested.h"


//проверка пароля на размер
bool checkSize(string p)
{
	if (p.size() < 8)
	{
		cout << "Пароль слишком короткий, попробуйте еще раз!!!" << endl;
		Sleep(2500);
		return true;
	}
	else
		return false;
}

//регестрация пользователя
void Tested::chekIn()
{
	system("cls");
	cout << "РЕГЕСТРАЦИЯ ПОЛЬЗОВАТЕЛЯ:\n" << endl;
	User* user = new User;
	if (base_users.empty())
	{
		string log;
		cout << "Введите ЛОГИН: ";
		cin >> log;
		user->setLogin(log);
		string pas;
		bool ad = true;
		//проверка пороля на размер
		while (ad)
		{
			cout << "Введите ПАРОЛЬ (не менее 8-ми символов): ";
			cin >> pas;
			ad = checkSize(pas);
		}
		hash<string> cod;
		int pass = cod(pas);
		user->setPass(pass);
		char* n = new char;
		cin.ignore();
		cout << "Введите ФИО: ";
		cin.getline(n, 100);
		string name = n;
		user->setName(name);
		string email;
		cout << "Введите электронный адрес: ";
		cin >> email;
		user->setEmail(email);
		string phone;
		cout << "Введите номер телефона: ";
		cin >> phone;
		user->setPhone(phone);
		base_tested.push_back(user);
		base_users.insert(make_pair(pass, base_tested));
		cout << "ПОЛЬЗОВАТЕЛЬ ДОБАВЛЕН!!!" << endl;
		Sleep(2500);
		menuTested();
	}
	else
	{
		string log;
		bool lp = true;
		//проверяем логин на повторение
		while (lp)
		{
			cout << "Введите ЛОГИН: ";
			cin >> log;
			int count = 0;
			auto it = base_users.begin();
			for (it; it != base_users.end(); it++)
			{
				if ((*it).second.front()->getLogin() == log)
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
		user->setLogin(log);
		string pas;
		bool ad = true;
		//проверка пороля на размер
		while (ad)
		{
			cout << "Введите ПАРОЛЬ (не менее 8-ми символов): ";
			cin >> pas;
			ad = checkSize(pas);
		}
		hash<string> cod;
		int pass = cod(pas);
		bool ps = true;
		while (ps)
		{
			if (base_users.count(pass) != 0)
			{
				cout << "Такой ПАРОЛЬ уже есть, введите другой ПАРОЛЬ!!!" << endl;
				Sleep(2500);
				system("cls");
				while (ad)
				{
					cout << "Введите ПАРОЛЬ (не менее 8-ми символов): ";
					cin >> pas;
					ad = checkSize(pas);
				}
				hash<string> cod;
				int pass = cod(pas);
			}
			else
				ps = false;

		}
		user->setPass(pass);
		char* n = new char;
		cin.ignore();
		cout << "Введите ФИО: ";
		cin.getline(n, 100);
		string name = n;
		user->setName(name);
		string email;
		cout << "Введите электронный адрес: ";
		cin >> email;
		user->setEmail(email);
		string phone;
		cout << "Введите номер телефона: ";
		cin >> phone;
		user->setPhone(phone);
		base_tested.push_back(user);
		base_users.insert(make_pair(pass, base_tested));
		cout << "ПОЛЬЗОВАТЕЛЬ ДОБАВЛЕН!!!" << endl;
		Sleep(2500);
		menuTested();
	}
}

//меню тестируемого
void Tested::menuTested()
{
	system("cls");
	cout << "МЕНЮ ПОЛЬЗОВАТЕЛЯ:\n" << endl;
	cout << "1. Управление ПОЛЬЗОАВАТЕЛЯМИ\n"
		<< "2. Управление СТАТИСТИКОЙ\n"
		<< "3. Управление ТЕСТАМИ\n"
		<< "4. Управление данными АДМИНИСТРАТОРА\n"
		<< "5. Выход\n" << endl;
	int var1;
	cin >> var1;
	switch (var1)
	{
	case 1:
		//controlUser();
		break;
	case 2:
		//lookStatics();
		break;
	case 3:
		//addTests();
		break;
	case 4:
		//changeLogin();
		break;
	case 5:
		exit(0);
		break;
	}
}

//просмотр результата тестирования
void Tested::printResult()
{
}

//сохранить промежуточное тестирование
void Tested::saveTesting()
{
}

//загрузить последнее сохраненное тестирование
void Tested::loadTesting()
{
}