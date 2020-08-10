#pragma once
#include"User.h"
#include"Tested.h"



class Admin :public User
{
private:

	string log_admin = "";  //����� ��������������
	int pass_admin = 0;     //������ ��������������
	Tested user;            //������������
public:

	

	string getLogAdmin() { return log_admin; }
	int getPassAdmin() { return pass_admin; }
	void setLogAdmin(string log) { this->log_admin = log; }
	void setPassAdmin(int pas) { this->pass_admin = pas; }
	
	void chekInAdmin();     //����������� ��������������
	void menuAdmin();       //���� ��������������
	void addTests();        //���������� ������, ��������� ��� ��������
	void loadTests();       //�������� ������ �� �����

	void changeLogin();     //��������� ������ � ������ ��������������
	void controlUser();     //��������� ������ ������������ (������������)
	void dellUser();        //�������� ������������
	void editUser();        //�������������� ������������
	void printUserFile();   //������ ������������� � ����
	void printUser();       //������ ������������� �� �����
	void lookStatics();     //�������� ����������
	void saveStatics();     //���������� ���������� � ����
	void saveLoginPass();   //���������� ������ � ������ ��������������
	void loadLoginPass();   //�������� ������ � ������ ��������������
};
