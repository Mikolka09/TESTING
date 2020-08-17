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

User::User()
{
	login_ = ""; pass_ = 0; name_ = ""; email_ = ""; phone_ = "";
}

User::User(string lg, unsigned int ps, string n, string em, string ph)
{
	login_ = lg; pass_ = ps; name_ = n; email_ = em; phone_ = ph;
}

User::User(const User& obj)
{
	login_.clear(); login_ = obj.login_;
	pass_ = 0; pass_ = obj.pass_;
	name_.clear(); name_ = obj.name_;
	email_.clear(); email_ = obj.email_;
	phone_.clear(); phone_ = obj.phone_;
}

User& User::operator=(const User& obj)
{
	login_.clear(); login_ = obj.login_;
	pass_ = 0; pass_ = obj.pass_;
	name_.clear(); name_ = obj.name_;
	email_.clear(); email_ = obj.email_;
	phone_.clear(); phone_ = obj.phone_;
	return *this;
}
