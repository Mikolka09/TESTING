#pragma once
#include "User.h"
#include "Tests.h"

class Results
{
private:

	string log_;               //логин пользователя
	string cat_;               //категория тестов
	int kol_que_ = 0;          //процент правельных ответов
	int kol_righ_ans_ = 0;     //количество правильных ответов
	int kol_bal_ = 0;          //количество набраных баллов

public:

	string get_log() const { return log_; }
	string get_cat() const { return cat_; }
	int get_kol_que() const { return kol_que_; }
	int get_kol_righ_ans() const { return kol_righ_ans_; }
	int get_kol_bal() const { return kol_bal_; }

	void set_log(string lg) { log_ = lg; }
	void set_cat(string c) { cat_ = c; }
	void set_kol_que(int kq) { kol_que_ = kq; }
	void set_kol_righ_ans(int kra) { kol_righ_ans_ = kra; }
	void set_kol_bal(int kb) { kol_bal_ = kb; }

	friend ostream& operator<<(ostream& out, const Results& r);
	friend ostream& operator<<(ostream& out, const Results* r);

};
