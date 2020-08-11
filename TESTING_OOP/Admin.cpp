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
	int pass = hashing(pas);
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
		default:;
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
		if (getLogAdmin() == log)
		{
			cout << "Такой ЛОГИН уже есть, введите другой ЛОГИН!!!" << endl;
			Sleep(2000);
		}
		else
			l = false;
	}
	setLogAdmin(log);
	cout << "ЛОГИН ИЗМЕНЕН!!" << endl;
	Sleep(2000);
	bool ad = true;
	string pas;
	//проверка пороля на размер
	while (ad)
	{
		system("cls");
		cout << "РЕДАКТИРОВАНИЕ ДАННЫХ АДМИНИСТРАТОРА:\n" << endl;
		cout << "Введите ПАРОЛЬ (не менее 8-ми символов): ";
		cin >> pas;
		ad = checkSize(pas);
	}
	int pass = hashing(pas);
	bool p = true;
	//проверка пароля на повторение
	while (p)
	{
		if (getPassAdmin() == pass)
		{
			cout << "Такой ПАРОЛЬ уже есть, введите другой ПАРОЛЬ!!!" << endl;
			Sleep(2000);
			system("cls");
			cout << "РЕДАКТИРОВАНИЕ ДАННЫХ АДМИНИСТРАТОРА:\n" << endl;
			cout << "Введите новый ПАРОЛЬ: ";
			cin >> pas;
			pass = hashing(pas);
			if (getLogAdmin() != log)
				p = false;
		}
		else
			p = false;
	}
	setPassAdmin(pass);
	cout << "ПАРОЛЬ ИЗМЕНЕН!!" << endl;
	Sleep(2000);
	saveLoginPass();
}

//изменение данных пользователя (тестируемого)
void Admin::controlUser(Tested& tes)
{
	while (true)
	{
		system("cls");
		cout << "УПРАВЛЕНИЕ ПОЛЬЗОВАТЕЛЯМИ:\n" << endl;
		cout << "1. Создание ПОЛЬЗОАВАТЕЛЯ\n"
			<< "2. Удаление ПОЛЬЗОВАТЕЛЯ\n"
			<< "3. Редактирование ПОЛЬЗОВАТЕЛЯ\n"
			<< "4. Печать ПОЛЬЗОВАТЕЛЕЙ\n"
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
				cout << "1. Печать в файл ПОЛЬЗОВАТЕЛЕЙ\n"
					<< "2. Печать на экран ПОЛЬЗОВАТЕЛЕЙ\n"
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
					system(("pause"));
					break;
				case 3:
					controlUser(tes);
					break;
				default:;
				}
			}
		case 5:
			menuAdmin(tes);
			break;
		default:
			break;
		}
	}
}

//удаление пользователя
void Admin::dellUser(Tested& tes)
{
	system("cls");
	cout << "УДАЛЕНИЕ ПОЛЬЗОВАТЕЛЯ:\n" << endl;
	printUser(tes);
	cout << "\n\n";
	string ld;
	cout << "Введите ЛОГИН ПОЛЬЗОВАТЕЛЯ для УДАЛЕНИЯ: ";
	cin >> ld;
	bool set = false;
	auto it = tes.base_tested.begin();
	for(it; it!=tes.base_tested.end();++it)
	{
		if((*it)->getLogin()==ld)
		{
			it = tes.base_tested.erase(it);
			set = true;
		}
	}
	if(set)
	{
		system("cls");
		cout << "ПОЛЬЗОВАТЕЛЬ УДАЛЕН!!!" << endl;
		Sleep(2000);
		tes.saveBase();
	}
	else
	{
		system("cls");
		cout << "ТАКОГО ПОЛЬЗОВАТЕЛЯ НЕТ!!!" << endl;
		Sleep(2000);
	}
}

//редактирование пользователя
void Admin::editUser(Tested& tes)
{
	system("cls");
	cout << "РЕДАКТИРОВАННИЕ ДАННЫХ ПОЛЬЗОВАТЕЛЯ:\n" << endl;
	printUser(tes);
	cout << "\n\n";
	string ld;
	cout << "Введите ЛОГИН ПОЛЬЗОВАТЕЛЯ для РЕДАКТИРОВАНИЯ: ";
	cin >> ld;
	bool set = false;
	auto it_r= tes.base_tested.end();
	auto it = tes.base_tested.begin();
	for (it; it != tes.base_tested.end(); ++it)
	{
		if ((*it)->getLogin() == ld)
		{
			it_r = it;
			set = true;
		}
	}
	if (set)
	{
		while (true)
		{
			system("cls");
			int var;
				cout << "РЕДАКТИРОВАНИЕ ПРОФИЛЯ:\n" << endl;
				cout << "1. Редактировать ЛОГИН\n" << "2. Редактировать ПАРОЛЬ\n" << "3. Редактировать ФИО\n"
					<< "4. Редактировать EMAIL\n" << "5. Редактировать номер ТЕЛЕФОНА\n" << "6. Возврат в предыдущее меню\n" << endl;
				cin >> var;
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
						int count = 0;
						//поиск одинаковых логинов со счетчиком
						auto it = tes.base_tested.begin();
						for (it; it != tes.base_tested.end(); ++it)
						{
							if ((*it)->getLogin() == log)
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
					(*it_r)->setLogin(log);
					cout << "ЛОГИН ИЗМЕНЕН!!!" << endl;
					Sleep(2000);
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
						ad = checkSize(pas);
					}
					int pp = hashing(pas);
					bool ps = true;
					while (ps)
					{
						if (tes.base_users.count(pp) != 0)  //проверяем есть ли еще такой пароль в базе
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
								d = checkSize(pas);
							}
							pp = hashing(pas);
							if (tes.base_users.count(pp) == 0)
								ps = false;
						}
						else
							ps = false;
					}
					(*it_r)->setPass(pp);
					cout << "ПАРОЛЬ ИЗМЕНЕН!!!" << endl;
					Sleep(2000);
					break;
				}
				case 3:
				{
					system("cls");
					char* n = new char;
					cin.ignore();
					cout << "Редактирование ФИО:\n" << endl;
					cout << "Введите новые ФИО:";
					cin.getline(n, 100);
					string name = n;
					(*it_r)->setName(name);
					cout << "ФИО ИЗМЕНЕН!!!" << endl;
					Sleep(2000);
					break;
				}
				case 4:
				{
					system("cls");
					cout << "Редактирование EMAIL:\n" << endl;
					cout << "Введите новый EMAIL:";
					string em;
					cin >> em;
					(*it_r)->setEmail(em);
					cout << "EMAIL ИЗМЕНЕН!!!" << endl;
					Sleep(2000);
					break;
				}
				case 5:
				{
					system("cls");
					cout << "Редактирование номера ТЕЛЕФОНА:\n" << endl;
					cout << "Введите новый номер ТЕЛЕФОНА:";
					string ph;
					cin >> ph;
					(*it_r)->setPhone(ph);
					cout << "ТЕЛЕФОН ИЗМЕНЕН!!!" << endl;
					Sleep(2000);
					break;
				}
				case 6:
					controlUser(tes);
					break;
				default:
					break;
				}
			tes.saveBase();
		}
	}
	else
	{
		system("cls");
		cout << "ТАКОГО ПОЛЬЗОВАТЕЛЯ НЕТ!!!" << endl;
		Sleep(2000);
	}
}

//печать пользователей в файл
void Admin::printUserFile(Tested& tes)
{
	ofstream out("ListUsers.txt", ios::out);
	out << "СПИСОК ПОЛЬЗОВАТЕЛЕЙ:\n" << endl;
	int i = 1;
	tes.base_tested.sort();
	auto it = tes.base_tested.begin();
	for (it; it != tes.base_tested.end(); ++it, i++)
		out << setw(4) << i << *it;
	out << endl;
	out.close();
	system("cls");
	cout << "СПИСОК ПОЛЬЗОВАТЕЛЕЙ НАПЕЧАТАН В ФАЙЛ!!!\n" << endl;
	Sleep(2000);
	
}

//печать пользователей на экран
void Admin::printUser(Tested& tes)
{
	system("cls");
	cout << "СПИСОК ПОЛЬЗОВАТЕЛЕЙ:\n" << endl;
	int i = 1;
	tes.base_tested.sort();
	auto it = tes.base_tested.begin();
	for (it; it != tes.base_tested.end(); ++it, i++)
		cout << setw(4) << i << *it;
	cout << endl;
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
