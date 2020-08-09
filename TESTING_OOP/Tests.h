#pragma once
#include<iostream>
#include <string>
#include<list>
#include<map>


using namespace std;

class Tests
{
private:

	string category = "";      //категория теста
	string id = "";            //номер вопроса
	string question = "";      //текст вопроса
	string answers = "";       //варианты ответов
	string rightAnswer = "";   //правельный ответ
	string balls = "";         //количество балов за вопрос

public:

	void printTest();  //вывод теста на экран

};




