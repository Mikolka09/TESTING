#pragma once
#include "Functions.h"

class User
{
private:

	string login_;              //логин пользователя
	unsigned int pass_ = 0;     //пароль пользователя

	string name_;               //ФИО пользователя
	string email_;              //электронный адресс пользователя
	string phone_;              //номер телефона пользователя

public:
	

	string get_login() const { return login_; };
	string get_name() const { return name_; };
	string get_email() const { return email_; };
	string get_phone() const { return phone_; };
	unsigned int get_pass() const { return pass_; };

	void set_login(string log) { login_ = log; }
	void set_name(string n) { name_ = n; }
	void set_email(string em) { email_ = em; }
	void set_phone(string ph) { phone_ = ph; }
	void set_pass(unsigned int p) { pass_ = p; }
	
	friend ostream& operator<<(ostream& out, const User& us);
	friend ostream& operator<<(ostream& out, const User* us);
	
};




