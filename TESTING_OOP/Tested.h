#pragma once
#include"User.h"

class Tested :public User
{
private:

	list<string> result;
	list<User*> base_tested; //������ ������ �������������
	map<int, list<User*>> base_users;  //���� ������ �������������

public:

	map<int, list<User*>>  getBaseUsers() { return base_users; }
	void setBase(list<User*>base) { base_tested = base; }

	void chekIn();        //����������� ������������
	void menuTested();    //���� ������������
	void printResult();   //�������� ���������� ������������
	void saveTesting();   //��������� ������������� ������������
	void loadTesting();   //��������� ��������� ����������� ������������

};
