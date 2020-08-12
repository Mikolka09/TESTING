#include "User.h"


ostream& operator<<(ostream& out, const User& us)
{
	out << right << setw(10) << us.login_ << setw(25) << us.name_ << setw(20) << us.email_ << setw(18) << us.phone_ << endl;
	return out;
}

ostream& operator<<(ostream& out, const User* us)
{
	out << right << setw(10) << us->login_ << setw(25) << us->name_ << setw(20) << us->email_ << setw(18) << us->phone_ << endl;
	return out;
}


