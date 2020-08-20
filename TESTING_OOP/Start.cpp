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
		SetColor(14, 0);
		cout << "1. ВХОД для ЗАРЕГЕCТРИРОВАННЫХ\n"
			<< "2. Регестрация АДМИНИСТРАТОРА\n"
			<< "3. Регестрация ПОЛЬЗОВАТЕЛЯ\n"
			<< "4. Выход\n" << endl;
		SetColor(15, 0);
		int var;
		bool v = true;
		while (v)
		{
			cin >> var;
			cin.ignore();
			if (var < 1 || var > 4)    // проверка ввода
			{
				SetColor(12, 0);
				cout << "НЕВЕРНО!!! ПОПРОБУЙТЕ ЕЩЕ РАЗ!!!" << endl;
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
			shapka_start();
			SetColor(12, 0);
			cout << "ВВОД ДАННЫХ:\n" << endl;
			SetColor(14, 0);
			cout << "1. Вход АДМИНИСТРАТОРА\n"
				<< "2. Вход ПОЛЬЗОВАТЕЛЯ\n"
				<< "3. Возврат в предыдущее меню\n" << endl;
			int var2;
			bool p = true;
			while (p)
			{
				SetColor(15, 0);
				cin >> var2;
				cin.ignore();
				if (var2 < 1 || var2 > 3)    // проверка ввода
				{
					SetColor(12, 0);
					cout << "НЕВЕРНО!!! ПОПРОБУЙТЕ ЕЩЕ РАЗ!!!" << endl;
					SetColor(15, 0);
				}
				else
					p = false;
			}
			switch (var2)
			{
			case 1:
			{
				if (admin.get_log_admin().empty())
				{
					SetColor(12, 0);
					cout << "\nАДМИНИСТРАТОР НЕ ЗАРЕГЕСТРИРОВАН!!!" << endl;
					Sleep(2500);
					enter_system();
				}
				else
				{
					system("cls");
					shapka_start();
					SetColor(12, 0);
					cout << "ВХОД В СИСТЕМУ АДМИНИСТРАТОРА:\n" << endl;
					string log;
					SetColor(14, 0);
					cout << "Введите ЛОГИН: ";
					SetColor(15, 0);
					cin >> log;
					uppercase(log);
					string pas;
					SetColor(14, 0);
					cout << "Введите ПАРОЛЬ: ";
					SetColor(15, 0);
					cin >> pas;
					auto pass = hashing(pas);
					if (admin.get_log_admin() == log && admin.get_pass_admin() == pass)
						admin.menu_admin();
					else
					{
						SetColor(12, 0);
						cout << "\nЛОГИН или ПАРОЛЬ указаны не верно!!!" << endl;
						Sleep(2500);
						enter_system();
					}
				}
				break;
			}
			case 2:
			{
				system("cls");
				shapka_start();
				SetColor(12, 0);
				cout << "ВХОД В СИСТЕМУ ПОЛЬЗОВАТЕЛЯ:\n" << endl;
				SetColor(14, 0);
				cout << "Введите свой ЛОГИН: ";
				SetColor(15, 0);
				string log;
				cin >> log;
				uppercase(log);
				SetColor(14, 0);
				cout << "Введите свой ПАРОЛЬ: ";
				SetColor(15, 0);
				string pas;
				cin >> pas;
				auto pass = hashing(pas);
				if (tested.check_in(pass, log))
					tested.menu_tested(log);
				else
				{
					SetColor(12, 0);
					cout << "\nЛОГИН или ПАРОЛЬ указаны не верно!!!" << endl;
					Sleep(2000);
					SetColor(15, 0);
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
		default:
			break;
		}

	}
}

