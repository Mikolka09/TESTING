#include "Testing.h"

//авторизированный вход
void Testing::enter_system()
{
	admin_.load_login_pass();
	tested_.load_base();
	while (true)
	{
		system("cls");
		cout << "ВОХОД В СИСТЕМУ:\n" << endl;
		cout << "1. ВХОД для ЗАРЕГЕТРИРОВАННЫХ\n"
			<< "2. Регестрация АДМИНИСТРАТОРА\n"
			<< "3. Регестрация ПОЛЬЗОВАТЕЛЯ\n"
			<< "4. Выход\n" << endl;
		int var;
		cin >> var;
		cin.ignore();
		switch (var)
		{
		case 1:
			system("cls");
			cout << "ВВОД ДАННЫХ:\n" << endl;
			cout << "1. Вход АДМИНИСТРАТОРА\n"
				<< "2. Вход ПОЛЬЗОВАТЕЛЯ\n"
				<< "3. Возврат в предыдущее меню\n" << endl;
			int var2;
			cin >> var2;
			cin.ignore();
			switch (var2)
			{
			case 1:
				if (admin_.get_log_admin().empty())
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
					if (admin_.get_log_admin() == log && admin_.get_pass_admin() == pass)
						admin_.menu_admin();
					else
					{
						cout << "ЛОГИН или ПАРОЛЬ указаны не верно!!!" << endl;
						Sleep(2000);
						enter_system();
					}
				}
				break;
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
				int pass = hashing(pas);
				if (tested_.get_base_users().count(pass) == 1
					&& (*tested_.get_base_users().find(pass)).second.front()->get_login() == log)
				{
					Results res;
					tested_.menu_tested(res);
				}
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
			break;
		case 2:
			admin_.registry_in_admin();
			break;
		case 3:
			tested_.registry_in();
			break;
		case 4:
			exit(0);
		default:
			break;
		}
	}
}

