#include "Tests.h"

Tests::Tests(const Tests& ob)
{
	category_ = ob.category_;
	id_ = ob.id_;
	question_ = ob.question_;
	answers_ = ob.answers_;
	right_answer_ = ob.right_answer_;
	balls_ = ob.balls_;
}

Tests& Tests::operator=(const Tests& ob)
{
	category_ = ob.category_;
	id_ = ob.id_;
	question_ = ob.question_;
	answers_ = ob.answers_;
	right_answer_ = ob.right_answer_;
	balls_ = ob.balls_;
	return *this;
}

void Tests::print_test() const
{
}

ostream& operator<<(ostream& out, const Tests& ts)
{
	out << right<<setw(4) << ts.id_ << "." << "  " << ts.question_ << endl << endl;
	out << right << setw(50) << "Количество балов: " << ts.balls_ <<" "<<"балов" << endl;
	out << "\n" << endl;
	out << right << setw(4) << ts.answers_ << endl;
	return out;
}

ostream& operator<<(ostream& out, const Tests* ts)
{
	out << right << setw(4) << ts->id_ << "." << "  " << ts->question_ << endl << endl;
	out << right << setw(50) << "Количество балов: " << ts->balls_ << " " << "балов" << endl;
	out << "\n" << endl;
	out << right << setw(4) << ts->answers_ << endl;
	return out;
}

ofstream& operator<<(ofstream& out, const Tests& ts)
{
	out <<ts.get_category()<<" "<< ts.get_id() << " " << ts.get_question() << " " << ts.get_answer() << " "
	<< ts.get_balls() << " " << ts.get_right_answer() << endl;
	return out;
}

ifstream& operator>>(ifstream& in, Tests* ts)
{
	while (true)
	{
		in >> ts->category_;
		in >> ts->id_;
		in >> ts->question_;
		in >> ts->answers_;
		in >> ts->balls_;
		in >> ts->right_answer_;
		if (in.eof())
			break;
	}
	return in;
}
