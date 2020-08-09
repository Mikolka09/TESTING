#pragma once
#include"User.h"

class Tested :public User
{
private:

	list<string> result;
	list<User*> base_tested; //������ ������ �������������
	map<unsigned int, list<User*>> base_users;  //���� ������ �������������

public:

	map<unsigned int, list<User*>>  getBaseUsers() { return base_users; }
	void setBase(list<User*>base) { base_tested = base; }

	void newTesting();    //����� ���� ������������
	void chekIn();        //����������� ������������
	void menuTested();    //���� ������������
	void printResult();   //�������� ���������� ������������
	void saveTesting();   //��������� ������������� ������������
	void loadTesting();   //��������� ��������� ����������� ������������
	void saveBase();      //���������� ���� �����������
	void loadBase();      //�������� ���� �����������
};
