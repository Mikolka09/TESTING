#include "User.h"


ostream& operator<<(ostream& out, const User& us)
{
	out << setw(2) << us.login << setw(20) << us.name << setw(30) << us.email << setw(20) << us.phone << endl;
	return out;
}

ostream& operator<<(ostream& out, const User* us)
{
	out << setw(2) << us->login << setw(20) << us->name << setw(30) << us->email << setw(20) << us->phone << endl;
	return out;
}


