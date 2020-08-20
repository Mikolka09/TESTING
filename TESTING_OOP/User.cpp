#include "User.h"


ostream& operator<<(ostream& out, const User& us)
{
	out << right << setw(10) << us.login_ << setw(25) << us.name_ << setw(20) << us.email_ << setw(18) << us.phone_ << endl;
	return out;
}

ostream& operator<<(ostream& out, const User* us)
{
	SetColor(13, 0);
	out << right << setw(10) << us->login_ << "  #" << setw(25) << us->name_ << "  #"
		<< setw(20) << us->email_ << "  #" << setw(18) << us->phone_ << "  #" << endl;
	return out;
}

//для сохранения в текстовый фаил
ofstream& operator<<(ofstream& out, const User& us)
{
	out << us.login_ << " " << us.pass_ << " " << us.name_ << " " << us.email_ << " " << us.phone_ << endl;
	return out;
}
//для выгрузки из фаила
ifstream& operator>>(ifstream& in, User* us)
{
	while (true)
	{
		in >> us->login_;
		in >> us->pass_;
		getline(in, us->name_);
		in >> us->email_;
		in >> us->phone_;
		if (in.eof())
			break;
	}
	return in;
}


User::User(const User& obj)
{
	login_ = obj.login_;
	pass_ = obj.pass_;
	name_ = obj.name_;
	email_ = obj.email_;
	phone_ = obj.phone_;
}

User& User::operator=(const User& obj)
{
	login_ = obj.login_;
	pass_ = obj.pass_;
	name_ = obj.name_;
	email_ = obj.email_;
	phone_ = obj.phone_;
	return *this;
}
