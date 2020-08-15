#include "Tests.h"

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
