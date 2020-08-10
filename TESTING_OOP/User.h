#pragma once
#include<iostream>
#include <string>
#include<list>
#include<map>
#include<fstream>
#include<functional>
#include<Windows.h>
#include<iomanip>
#include<fstream>

using namespace std;

class User
{
private:

	string login;// = "";  //логин пользователя
	unsigned int pass = 0;       //пароль пользователя

	string name;// = "";   //ФИО пользователя
	string email;// = "";  //электронный адресс пользователя
	string phone;// = "";  //номер телефона пользователя

public:
	

	string getLogin() { return login; };
	string getName() { return name; };
	string getEmail() { return email; };
	string getPhone() { return phone; };
	unsigned int getPass() { return pass; };

	void setLogin(string log) { login = log; }
	void setName(string n) { name = n; }
	void setEmail(string em) { email = em; }
	void setPhone(string ph) { phone = ph; }
	void setPass(unsigned int p) { pass = p; }
	
	friend ostream& operator<<(ostream& out, const User& us);
	friend ostream& operator<<(ostream& out, const User* us);
	
};




