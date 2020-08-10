#include "Testing.h"

//���������������� ����
void Testing::enterSystem()
{
	admin.loadLoginPass();
	tested.loadBase();
	while (true)
	{
		system("cls");
		cout << "����� � �������:\n" << endl;
		cout << "1. ����� ��� ������ �������\n"
			<< "2. ����������� ������������\n"
			<< "3. �����\n" << endl;
		int var1;
		cin >> var1;
		switch (var1)
		{
		case 1:
			system("cls");
			cout << "���� ������:\n" << endl;
			cout << "1. ���� ��������������\n"
				<< "2. ���� �������������\n"
				<< "3. ������� � ���������� ����\n" << endl;
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
					cout << "������� �����: ";
					cin >> log;
					string pas;
					cout << "������� ������: ";
					cin >> pas;
					hash<string> cod;
					int pass = cod(pas);
					if (admin.getLogAdmin() == log && admin.getPassAdmin() == pass)
						admin.menuAdmin();
					else
					{
						cout << "����� ��� ������ ������� �� �����!!!" << endl;
						Sleep(2000);
						enterSystem();
					}
				}
				break;
			case 2:
			{
				system("cls");
				cout << "������� ���� �����: ";
				string log;
				cin >> log;
				cout << "������� ���� ������: ";
				string pas;
				cin >> pas;
				hash<string> cod;
				int pass = cod(pas);
				if (tested.getBaseUsers().count(pass) == 1 && (*tested.getBaseUsers().find(pass)).second.front()->getLogin() == log)
					tested.menuTested();
				else
				{
					cout << "����� ��� ������ ������� �� �����!!!" << endl;
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

//���� ������������
void Testing::menu()
{
	system("cls");
	cout << "����� ���������� �� ������������!!!" << endl;
	cout << "����:\n" << endl;
	cout << "1. ���� � �������\n" << "2. �����";
}
