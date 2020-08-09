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
		int pass = cod(pas);
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
		int pass = cod(pas);
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
				int pass = cod(pas);
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
		menuTested();
	}
}

//���� ������������
void Tested::menuTested()
{
	system("cls");
	cout << "���� ������������:\n" << endl;
	cout << "1. ���������� ���������������\n"
		<< "2. ���������� �����������\n"
		<< "3. ���������� �������\n"
		<< "4. ���������� ������� ��������������\n"
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