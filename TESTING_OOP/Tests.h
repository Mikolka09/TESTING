#pragma once
#include<iostream>
#include <string>
#include<list>
#include<map>


using namespace std;

class Tests
{
private:

	string category = "";      //��������� �����
	string id = "";            //����� �������
	string question = "";      //����� �������
	string answers = "";       //�������� �������
	string rightAnswer = "";   //���������� �����
	string balls = "";         //���������� ����� �� ������

public:

	void printTest();  //����� ����� �� �����

};




