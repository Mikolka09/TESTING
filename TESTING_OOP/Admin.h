#pragma once
#include"User.h"
#include"Tested.h"



class Admin 
{
private:
	
	string log_admin = "";  //����� ��������������
	int pass_admin = 0;     //������ ��������������
	
public:

	

	string getLogAdmin() { return log_admin; }
	int getPassAdmin() { return pass_admin; }
	void setLogAdmin(string log) { this->log_admin = log; }
	void setPassAdmin(int pas) { this->pass_admin = pas; }
	
	void chekInAdmin();                //����������� ��������������
	void menuAdmin(Tested& tes);       //���� ��������������
	void addTests();                   //���������� ������, ��������� ��� ��������
	void loadTests();                  //�������� ������ �� �����

	void changeLogin();                //��������� ������ � ������ ��������������
	void controlUser(Tested& tes);     //��������� ������ ������������ (������������)
	void dellUser(Tested& tes);        //�������� ������������
	void editUser(Tested& tes);        //�������������� ������������
	void printUserFile(Tested& tes);   //������ ������������� � ����
	void printUser(Tested& tes);       //������ ������������� �� �����
	void lookStatics();                //�������� ����������
	void saveStatics();                //���������� ���������� � ����
	void saveLoginPass();              //���������� ������ � ������ ��������������
	void loadLoginPass();              //�������� ������ � ������ ��������������
};
