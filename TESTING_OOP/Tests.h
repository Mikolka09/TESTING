#pragma once
#include "Functions.h"


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




