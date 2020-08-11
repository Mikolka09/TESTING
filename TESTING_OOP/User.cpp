#include "User.h"


ostream& operator<<(ostream& out, const User& us)
{
	out << right << setw(8) << us.login << setw(30) << us.name << setw(20) << us.email << setw(18) << us.phone << endl;
	return out;
}

ostream& operator<<(ostream& out, const User* us)
{
	out << right << setw(8) << us->login << setw(30) << us->name << setw(20) << us->email << setw(18) << us->phone << endl;
	return out;
}


