#include "Start.h"

void Start::shapka_start()
{
	string S(40,'#');
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

//авторизированный вход
void Start::enter_system() const
{
	Admin admin;
	Tested tested;
	while (true)
	{
		admin.load_login_pass();
		tested.load_base();
		system("cls");
		shapka_start();
		SetColor(12, 0);
		cout << "ВХОД В СИСТЕМУ:\n" << endl;
		SetColor(1, 0);
		cout << "1. ВХОД для ЗАРЕГЕCТРИРОВАННЫХ\n"
			<< "2. Регестрация АДМИНИСТРАТОРА\n"
			<< "3. Регестрация ПОЛЬЗОВАТЕЛЯ\n"
			<< "4. Выход\n" << endl;
		SetColor(14, 0);
		int var;
		bool v = true;
		while (v)
		{
			cin >> var;
			cin.ignore();
			if (var < 1 || var > 4)    // проверка ввода
				cout << "НЕВЕРНО!!! ПОПРОБУЙТЕ ЕЩЕ РАЗ!!!" << endl;
			else
				v = false;
		}
		switch (var)
		{
		case 1:
		{
			system("cls");
			cout << "ВВОД ДАННЫХ:\n" << endl;
			cout << "1. Вход АДМИНИСТРАТОРА\n"
				<< "2. Вход ПОЛЬЗОВАТЕЛЯ\n"
				<< "3. Возврат в предыдущее меню\n" << endl;
			int var2;
			bool p = true;
			while (p)
			{
				cin >> var2;
				cin.ignore();
				if (var2 < 1 || var2 > 3)    // проверка ввода
					cout << "НЕВЕРНО!!! ПОПРОБУЙТЕ ЕЩЕ РАЗ!!!" << endl;
				else
					p = false;
			}
			switch (var2)
			{
			case 1:
			{
				if (admin.get_log_admin().empty())
				{
					cout << "АДМИНИСТРАТОР не ЗАРЕГЕСТРИРОВАН!!!" << endl;
					Sleep(2500);
					enter_system();
				}
				else
				{
					system("cls");
					cout << "ВХОД В СИСТЕМУ АДМИНИСТРАТОРА:\n" << endl;
					string log;
					cout << "Введите ЛОГИН: ";
					cin >> log;
					uppercase(log);
					string pas;
					cout << "Введите ПАРОЛЬ: ";
					cin >> pas;
					auto pass = hashing(pas);
					if (admin.get_log_admin() == log && admin.get_pass_admin() == pass)
						admin.menu_admin();
					else
					{
						cout << "ЛОГИН или ПАРОЛЬ указаны не верно!!!" << endl;
						Sleep(2500);
						enter_system();
					}
				}
				break;
			}
			case 2:
			{
				system("cls");
				cout << "ВХОД В СИСТЕМУ ПОЛЬЗОВАТЕЛЯ:\n" << endl;
				cout << "Введите свой ЛОГИН: ";
				string log;
				cin >> log;
				uppercase(log);
				cout << "Введите свой ПАРОЛЬ: ";
				string pas;
				cin >> pas;
				auto pass = hashing(pas);
				if (tested.check_in(pass, log))
					tested.menu_tested(log);
				else
				{
					cout << "ЛОГИН или ПАРОЛЬ указаны не верно!!!" << endl;
					Sleep(2000);
					enter_system();
				}
				break;
			}
			case 3:
				enter_system();
				break;
			default:
				break;
			}

		}
		case 2:
			admin.registry_in_admin();
			break;
		case 3:
			tested.registry_in();
			break;
		case 4:
			exit(0);
		/*default:
			break;*/
		}

	}
}

