#include "Tests.h"

void Tests::print_test() const
{
}

ostream& operator<<(ostream& out, const Tests& ts)
{
	out << setw(4) << ts.id_ << "." << "  " << ts.question_ << endl << endl;
	out << "\t\t" << ts.balls_ <<" "<<"балов" << endl;
	out << "\n" << endl;
	out << "  " << ts.answers_ << endl;
	return out;
}

ostream& operator<<(ostream& out, const Tests* ts)
{
	out << setw(4) << ts->id_ << "." << "  " << ts->question_ << endl << endl;
	out << "\t\t" << ts->balls_ << " " << "балов" << endl;
	out << "\n" << endl;
	out << "  " << ts->answers_ << endl;
	return out;
}
