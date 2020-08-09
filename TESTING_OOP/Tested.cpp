#include"Tested.h"


//�������� ������ �� ������
bool checkSize(string p)
{
	if (p.size() < 8)
	{
		cout << "������ ������� ��������, ���������� ��� ���!!!" << endl;
		Sleep(2500);
		return true;
	}
	else
		return false;
}

//����������� ������������
void Tested::chekIn()
{
	system("cls");
	cout << "����������� ������������:\n" << endl;
	User* user = new User;
	if (base_users.empty())
	{
		string log;
		cout << "������� �����: ";
		cin >> log;
		user->setLogin(log);
		string pas;
		bool ad = true;
		//�������� ������ �� ������
		while (ad)
		{
			cout << "������� ������ (�� ����� 8-�� ��������): ";
			cin >> pas;
			ad = checkSize(pas);
		}
		hash<string> cod;
		unsigned int pass = cod(pas);
		user->setPass(pass);
		char* n = new char;
		cin.ignore();
		cout << "������� ���: ";
		cin.getline(n, 100);
		string name = n;
		user->setName(name);
		string email;
		cout << "������� ����������� �����: ";
		cin >> email;
		user->setEmail(email);
		string phone;
		cout << "������� ����� ��������: ";
		cin >> phone;
		user->setPhone(phone);
		base_tested.push_back(user);
		base_users.insert(make_pair(pass, base_tested));
		cout << "������������ ��������!!!" << endl;
		Sleep(2500);
		saveBase();
		menuTested();
	}
	else
	{
		string log;
		bool lp = true;
		//��������� ����� �� ����������
		while (lp)
		{
			cout << "������� �����: ";
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
				cout << "����� ����� ��� ����, ������� ������ �����!!!" << endl;
				Sleep(2500);
			}
			else
				lp = false;
		}
		user->setLogin(log);
		string pas;
		bool ad = true;
		//�������� ������ �� ������
		while (ad)
		{
			cout << "������� ������ (�� ����� 8-�� ��������): ";
			cin >> pas;
			ad = checkSize(pas);
		}
		hash<string> cod;
		unsigned int pass = cod(pas);
		bool ps = true;
		while (ps)
		{
			if (base_users.count(pass) != 0)
			{
				cout << "����� ������ ��� ����, ������� ������ ������!!!" << endl;
				Sleep(2500);
				system("cls");
				while (ad)
				{
					cout << "������� ������ (�� ����� 8-�� ��������): ";
					cin >> pas;
					ad = checkSize(pas);
				}
				hash<string> cod;
				unsigned int pass = cod(pas);
			}
			else
				ps = false;
		}
		user->setPass(pass);
		char* n = new char;
		cin.ignore();
		cout << "������� ���: ";
		cin.getline(n, 100);
		string name = n;
		user->setName(name);
		string email;
		cout << "������� ����������� �����: ";
		cin >> email;
		user->setEmail(email);
		string phone;
		cout << "������� ����� ��������: ";
		cin >> phone;
		user->setPhone(phone);
		base_tested.push_back(user);
		base_users.insert(make_pair(pass, base_tested));
		cout << "������������ ��������!!!" << endl;
		Sleep(2500);
		saveBase();
		menuTested();
	}
}

//���� ������������
void Tested::menuTested()
{
	system("cls");
	cout << "���� ������������:\n" << endl;
	cout << "1. ����� ����� ������������\n"
		<< "2. ��������� ����������� �������������\n"
		<< "3. ��������� ������������� ������������\n"
		<< "4. ��������� ��������� ����������� ������������\n"
		<< "5. �����\n" << endl;
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

//�������� ���������� ������������
void Tested::printResult()
{
}

//��������� ������������� ������������
void Tested::saveTesting()
{
}

//��������� ��������� ����������� ������������
void Tested::loadTesting()
{
}


//���������� ���� �����������
void Tested::saveBase()
{
	ofstream fout("BaseTasted.bin", ios::binary | ios::out);
	int length = base_tested.size();
	User* user = new User;
	fout.write((char*)&length, sizeof(int));
	fout.write((char*)&base_tested, sizeof(User));
	for (size_t i = 0; i < length; i++)
	{
		user = base_tested.front();
		unsigned int pas = user->getPass();
		fout.write((char*)&pas, sizeof(unsigned int));
		//string log = user->getLogin().c_str();
		int l_log = user->getLogin().size() + 1;
		fout.write((char*)&l_log, sizeof(int));
		fout.write((char*)user->getLogin().c_str(), l_log);
		//string n = user->getName().c_str();
		int l_n = user->getName().size() + 1;
		fout.write((char*)&l_n, sizeof(int));
		fout.write((char*)user->getName().c_str(), l_n);
		//string em = user->getEmail().c_str();
		int l_em = user->getEmail().size() + 1;
		fout.write((char*)&l_em, sizeof(int));
		fout.write((char*)user->getEmail().c_str(), l_em);
		//string ph = user->getPhone().c_str();
		int l_ph = user->getPhone().size() + 1;
		fout.write((char*)&l_ph, sizeof(int));
		fout.write((char*)user->getPhone().c_str(), l_ph);
	}
	fout.close();

}

//�������� ���� �����������
void Tested::loadBase()
{
	ifstream fin("BaseTasted.bin", ios::binary | ios::in);
	if (fin.is_open())
	{
		int length;
		User* user = new User;
		fin.read((char*)&length, sizeof(int));
		fin.read((char*)&this->base_tested, sizeof(User));
		for (size_t i = 0; i < length; i++)
		{
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
