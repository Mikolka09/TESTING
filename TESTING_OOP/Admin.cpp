#include"Admin.h"


//����������� ��������������
void Admin::chekInAdmin()
{
	system("cls");
	cout << "����������� ��������������:\n" << endl;
	string log;
	cout << "������� �����: ";
	cin >> log;
	string pas;
	bool ad = true;
	while (ad)
	{
		cout << "������� ������ (�� ����� 8-�� ��������): ";
		cin >> pas;
		if (pas.size() < 8)
		{
			cout << "������ ������� ��������, ���������� ��� ���!!!" << endl;
			Sleep(2500);
		}
		else
			ad = false;
	}
	hash<string> cod;
	int pass = cod(pas);
	this->log_admin = log;
	this->pass_admin = pass;
	cout << "������ �������������� ���������!!!" << endl;
	Sleep(2000);
	saveLoginPass();
}

//���� ��������������
void Admin::menuAdmin(Tested& tes)
{
	while (true)
	{
		system("cls");
		cout << "���� ��������������:\n" << endl;
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

//���������� ������, ��������� ��� ��������
void Admin::addTests()
{
}

//�������� ������ �� �����
void Admin::loadTests()
{
}

//��������� ������ � ������ ��������������
void Admin::changeLogin()
{
}

//��������� ������ ������������ (������������)
void Admin::controlUser(Tested& tes)
{
	while (true)
	{
		system("cls");
		cout << "���������� ��������������:\n" << endl;
		cout << "1. �������� �������������\n"
			<< "2. �������� �������������\n"
			<< "3. �������������� �������������\n"
			<< "4. ������ ��������������\n"
			<< "5. ������� � ���������� ����\n" << endl;
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
				cout << "������ �������������:\n" << endl;
				cout << "1. ������ � ���� ��������������\n"
					<< "2. ������ �� ����� ��������������\n"
					<< "3. ������� � ���������� ����\n" << endl;
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

//�������� ������������
void Admin::dellUser(Tested& tes)
{
}

//�������������� ������������
void Admin::editUser(Tested& tes)
{
}

//������ ������������� � ����
void Admin::printUserFile(Tested& tes)
{
}

//������ ������������� �� �����
void Admin::printUser(Tested& tes)
{
	system("cls");
	cout << "������ �������������:\n" << endl;
	auto it = tes.base_tested.begin();
	for (it; it != tes.base_tested.end(); ++it)
		cout << *it;
	cout << endl;
	system("pause");

}

//�������� ����������
void Admin::lookStatics()
{
}

//���������� ���������� � ����
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
