#include "Testing.h"

//авторизированный вход
void Testing::enterSystem()
{
	admin.loadLoginPass();
	tested.loadBase();
	while (true)
	{
		system("cls");
		cout << "ВОЙТИ В СИСТЕМУ:\n" << endl;
		cout << "1. Войти под своими данными\n"
			<< "2. Регестрация пользователя\n"
			<< "3. Выход\n" << endl;
		int var1;
		cin >> var1;
		switch (var1)
		{
		case 1:
			system("cls");
			cout << "ВВОД ДАННЫХ:\n" << endl;
			cout << "1. Вход Администратора\n"
				<< "2. Вход Пользоывателя\n"
				<< "3. Возврат в предыдущее меню\n" << endl;
			int var2;
			cin >> var2;
			switch (var2)
			{
			case 1:
				if (admin.getLogAdmin().empty())
					admin.chekInAdmin();
				else
				{
					system("cls");
					string log;
					cout << "ВВедите ЛОГИН: ";
					cin >> log;
					string pas;
					cout << "Введите ПАРОЛЬ: ";
					cin >> pas;
					hash<string> cod;
					int pass = cod(pas);
					if (admin.getLogAdmin() == log && admin.getPassAdmin() == pass)
						admin.menuAdmin();
					else
					{
						cout << "ЛОГИН или ПАРОЛЬ указаны не верно!!!" << endl;
						Sleep(2000);
						enterSystem();
					}
				}
				break;
			case 2:
			{
				system("cls");
				cout << "Введите свой ЛОГИН: ";
				string log;
				cin >> log;
				cout << "Введите свой ПАРОЛЬ: ";
				string pas;
				cin >> pas;
				hash<string> cod;
				int pass = cod(pas);
				if (tested.getBaseUsers().count(pass) == 1 && (*tested.getBaseUsers().find(pass)).second.front()->getLogin() == log)
					tested.menuTested();
				else
				{
					cout << "ЛОГИН или ПАРОЛЬ указаны не верно!!!" << endl;
					Sleep(2000);
					enterSystem();
				}
				break;
			}
			case 3:
				enterSystem();
				break;
			}
			break;
		case 2:
			tested.chekIn();
			break;
		case 3:
			exit(0);
			break;
		}
	}
}

//меню тестирования
void Testing::menu()
{
	system("cls");
	cout << "ДОБРО ПОЖАЛОВАТЬ НА ТЕСТИРОВАНИЕ!!!" << endl;
	cout << "МЕНЮ:\n" << endl;
	cout << "1. Вход в систему\n" << "2. Начат";
}
