#pragma once
#include <iostream>
#include"Tests.h"
#include"Admin.h"
#include"Tested.h"
#include<Windows.h>

using namespace std;

class Testing
{
private:

	Admin admin;  //�������������
	Tested tested;  //�����������
	
public:

	
	void enterSystem();  //���������������� ����
	void menu();         //���� ������������

};
