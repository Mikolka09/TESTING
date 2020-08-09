#include "User.h"


ostream& operator<<(ostream& out, const User& us)
{
	out << setw(10) << us.login << setw(14) << us.name << setw(8) << us.email << setw(12)
		<< us.phone << endl;
	return out;
}

ostream& operator<<(ostream& out, const User* us)
{
	out << setw(10) << us->login << setw(14) << us->name << setw(8) << us->email << setw(12)
		<< us->phone << endl;
	return out;
}

//istream& operator>>(istream& in, User* us)
//{
//
//	cout << "������� �����: ";   in >> us->login;
//	cout << "������� ������: ";   in >> us->pass;
//	cout << "������� ���: ";       in >> us->name;
//	cout << "������� email: ";   in >> us->email;
//	cout << "������� ����� ��������: ";	in >> us->phone;
//	return in;
//}
