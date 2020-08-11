#include"Tested.h"




void Tested::newTesting()
{
}

//регестрация пользователя
void Tested::chekIn()
{
	system("cls");
	cout << "РЕГЕСТРАЦИЯ ПОЛЬЗОВАТЕЛЯ:\n" << endl;
	User* user = new User;
	if (base_users.empty())  //проверка на пустоту
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
			ad = checkSize(pas);  //проверка на размер пароля
		}
		unsigned int pass = hashing(pas);  //шифрование пароля
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
		saveBase();
		menuTested();
	}
	else
	{
		string log;
		bool lp = true;
		//проверяем логин на повторение
		while (lp)
		{
			system("cls");
			cout << "РЕГЕСТРАЦИЯ ПОЛЬЗОВАТЕЛЯ:\n" << endl;
			cout << "Введите ЛОГИН: ";
			cin >> log;
			int count = 0;
			//поиск одинаковых логинов со счетчиком
			auto it = base_tested.begin();
			for (it; it != base_tested.end(); ++it)
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
		//шифрование пароля
		int pass = hashing(pas);
		bool ps = true;
		while (ps)
		{
			if (base_users.count(pass) != 0)  //проверяем есть ли еще такой пароль в базе
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
					d = checkSize(pas);
				}
				pass = hashing(pas);
				if (base_users.count(pass) == 0)
					ps = false;
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
		saveBase();
		menuTested();
	}
}

//меню тестируемого
void Tested::menuTested()
{
	while (true)
	{
		system("cls");
		cout << "МЕНЮ ПОЛЬЗОВАТЕЛЯ:\n" << endl;
		cout << "1. Сдать новое ТЕСТИРОВАНИЕ\n"
			<< "2. Просмотор результатов ТЕСТИРОВАНИЯЕ\n"
			<< "3. Сохранить промежуточное ТЕСТИРОВАНИЕ\n"
			<< "4. Загрузить последнее сохраненное ТЕСТИРОВАНИЕ\n"
			<< "5. Выход\n" << endl;
		int var1;
		cin >> var1;
		switch (var1)
		{
		case 1:
			//controlUser();
			break;
		case 2:
			print();
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
}

//просмотр результата тестирования
void Tested::printResult()
{
}

//печать списка тестируемых
void Tested::print()
{
	auto it = this->base_tested.begin();
	for (it; it != this->base_tested.end(); ++it)
		cout << *it << " ";
	cout << endl;
}

//сохранить промежуточное тестирование
void Tested::saveTesting()
{
}

//загрузить последнее сохраненное тестирование
void Tested::loadTesting()
{
}


//сохранение базы тестируемых
void Tested::saveBase()
{
	ofstream fout("BaseTasted.bin", ios::binary | ios::out);
	int length = base_tested.size();
	User* user = new User;
	fout.write((char*)&length, sizeof(int));
	for (int i = 0; i < length; i++)
	{
		user = base_tested.front();
		unsigned int pas = user->getPass();
		fout.write((char*)&pas, sizeof(unsigned int));
		int l_log = user->getLogin().size() + 1;
		fout.write((char*)&l_log, sizeof(int));
		fout.write((char*)user->getLogin().c_str(), l_log);
		int l_n = user->getName().size() + 1;
		fout.write((char*)&l_n, sizeof(int));
		fout.write((char*)user->getName().c_str(), l_n);
		int l_em = user->getEmail().size() + 1;
		fout.write((char*)&l_em, sizeof(int));
		fout.write((char*)user->getEmail().c_str(), l_em);
		int l_ph = user->getPhone().size() + 1;
		fout.write((char*)&l_ph, sizeof(int));
		fout.write((char*)user->getPhone().c_str(), l_ph);
		base_tested.pop_front();
	}
	fout.close();

}

//загрузка базы тестируемых
void Tested::loadBase()
{
	ifstream fin("BaseTasted.bin", ios::binary | ios::in);
	if (fin.is_open())
	{
		int length;
		fin.read((char*)&length, sizeof(int));
		for (int i = 0; i < length; i++)
		{
			User* user = new User;
			unsigned int pas;
			fin.read((char*)&pas, sizeof(unsigned int));
			user->setPass(pas);
			int l_log;
			fin.read((char*)&l_log, sizeof(int));
			char* buff = new char(l_log + 1);
			fin.read(buff, l_log);
			user->setLogin(buff);
			int l_n;
			fin.read((char*)&l_n, sizeof(int));
			char* buff1 = new char(l_n + 1);
			fin.read(buff1, l_n);
			user->setName(buff1);
			int l_em;
			fin.read((char*)&l_em, sizeof(int));
			char* buff2 = new char(l_em + 1);
			fin.read(buff2, l_em);
			user->setEmail(buff2);
			int l_ph;
			fin.read((char*)&l_ph, sizeof(int));
			char* buff3 = new char(l_ph + 1);
			fin.read(buff3, l_ph);
			user->setPhone(buff3);

			this->base_tested.push_back(user);
			this->base_users.insert(make_pair(user->getPass(), base_tested));
		}
	}
	fin.close();
}
