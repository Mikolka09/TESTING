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
//	cout << "Введите ЛОГИН: ";   in >> us->login;
//	cout << "Введите ПАРОЛЬ: ";   in >> us->pass;
//	cout << "Введите ФИО: ";       in >> us->name;
//	cout << "ВВедите email: ";   in >> us->email;
//	cout << "Введите номер телефона: ";	in >> us->phone;
//	return in;
//}
