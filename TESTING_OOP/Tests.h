#pragma once
#include "Functions.h"


class Tests
{
private:

	string category_;           //категория теста
	int id_ = 0;                //номер вопроса
	string question_;           //текст вопроса
	string answers_;            //варианты ответов
	int right_answer_ = 0;      //номер правельного ответ
	int balls_ = 0;             //количество балов за вопрос

public:

	string get_category() const { return category_; }
	string get_question() const { return question_; }
	string get_answer() const { return answers_; }
	int get_right_answer() const { return right_answer_; }
	int get_balls() const { return balls_; }
	int get_id() const { return id_; }

	void set_category(string cat) { category_ = cat; }
	void set_question(string q) { question_ = q; }
	void set_answer(string an) { answers_ = an; }
	void set_right_answer(int r_an) { right_answer_ = r_an; }
	void set_balls(int bl) { balls_ = bl; }
	void set_id(int d) { id_ = d; }

	friend ostream& operator<<(ostream& out, const Tests& ts);
	friend ostream& operator<<(ostream& out, const Tests* ts);

	void print_test() const;      //вывод теста на экран

};




