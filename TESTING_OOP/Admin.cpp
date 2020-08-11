#include"Admin.h"


//регестрация администратора
void Admin::chekInAdmin()
{
	system("cls");
	cout << "РЕГЕСТРАЦИЯ АДМИНИСТРАТОРА:\n" << endl;
	string log;
	cout << "Введите ЛОГИН: ";
	cin >> log;
	string pas;
	bool ad = true;
	while (ad)
	{
		cout << "Введите ПАРОЛЬ (не менее 8-ми символов): ";
		cin >> pas;
		if (pas.size() < 8)
		{
			cout << "Пароль слишком короткий, попробуйте еще раз!!!" << endl;
			Sleep(2500);
		}
		else
			ad = false;
	}
	hash<string> cod;
	int pass = cod(pas);
	this->log_admin = log;
	this->pass_admin = pass;
	cout << "Данные АДМИНИСТРАТОРА сохранены!!!" << endl;
	Sleep(2000);
	saveLoginPass();
}

//меню админитсратора
void Admin::menuAdmin(Tested& tes)
{
	while (true)
	{
		system("cls");
		cout << "МЕНЮ АДМИНИСТРАТОРА:\n" << endl;
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
			controlUser(tes);
			break;
		case 2:
			lookStatics();
			break;
		case 3:
			addTests();
			break;
		case 4:
			changeLogin();
			break;
		case 5:
			exit(0);
			break;
		}
	}
}

//добавление тестов, категорий или вопросов
void Admin::addTests()
{
}

//загрузка тестов из файла
void Admin::loadTests()
{
}

//изменение логина и пароля администратора
void Admin::changeLogin()
{
}

//изменение данных пользователя (тестируемого)
void Admin::controlUser(Tested& tes)
{
	while (true)
	{
		system("cls");
		cout << "УПРАВЛЕНИЕ ПОЛЬЗОВАТЕЛЯМИ:\n" << endl;
		cout << "1. Создание ПОЛЬЗОАВАТЕЛЯ\n"
			<< "2. Удаление ПОЛЬЗОАВАТЕЛЯ\n"
			<< "3. Редактирование ПОЛЬЗОАВАТЕЛЯ\n"
			<< "4. Печать ПОЛЬЗОАВАТЕЛЕЙ\n"
			<< "5. Возврат в предыдущее меню\n" << endl;
		int var;
		cin >> var;
		switch (var)
		{
		case 1:
			tes.chekIn();
			break;
		case 2:
			dellUser(tes);
			break;
		case 3:
			editUser(tes);
			break;
		case 4:
			while (true)
			{
				system("cls");
				cout << "ПЕЧАТЬ ПОЛЬЗОВАТЕЛЕЙ:\n" << endl;
				cout << "1. Печать в файл ПОЛЬЗОАВАТЕЛЕЙ\n"
					<< "2. Печать на экран ПОЛЬЗОАВАТЕЛЕЙ\n"
					<< "3. Возврат в предыдущее меню\n" << endl;
				int var1;
				cin >> var1;
				switch (var1)
				{
				case 1:
					printUserFile(tes);
					break;
				case 2:
					printUser(tes);
					break;
				case 3:
					controlUser(tes);
					break;
				}
			}
			break;
		case 5:
			menuAdmin(tes);
			break;
		}
	}
}

//удаление пользователя
void Admin::dellUser(Tested& tes)
{
}

//редактирование пользователя
void Admin::editUser(Tested& tes)
{
}

//печать пользователей в файл
void Admin::printUserFile(Tested& tes)
{
}

//печать пользователей на экран
void Admin::printUser(Tested& tes)
{
	system("cls");
	cout << "СПИСОК ПОЛЬЗОВАТЕЛЕЙ:\n" << endl;
	auto it = tes.base_tested.begin();
	for (it; it != tes.base_tested.end(); ++it)
		cout << *it;
	cout << endl;
	system("pause");

}

//просмотр статистики
void Admin::lookStatics()
{
}

//сохранение статистики в файл
void Admin::saveStatics()
{
}

void Admin::saveLoginPass()
{
	ofstream fout("PassAdmin.bin", ios::binary | ios::out);
	int len_log = getLogAdmin().size() + 1;
	fout.write((char*)&len_log, sizeof(int));
	fout.write((char*)getLogAdmin().c_str(), len_log);
	int pass = getPassAdmin();
	fout.write((char*)&pass, sizeof(int));
	fout.close();
}

void Admin::loadLoginPass()
{
	ifstream fin("PassAdmin.bin", ios::binary | ios::in);
	if (fin.is_open())
	{
		int len_log = 0;
		int pass = 0;
		fin.read((char*)&len_log, sizeof(int));
		char* buff = new char(len_log + 1);
		fin.read(buff, len_log);
		setLogAdmin(buff);
		fin.read((char*)&pass, sizeof(int));
		setPassAdmin(pass);
	}
	fin.close();
}
