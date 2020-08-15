#include "Results.h"

ostream& operator<<(ostream& out, const Results& r)
{
	out << right << setw(10) << r.log_ << endl;
	out << right << setw(15) << r.cat_ << setw(8) << r.kol_que_ << setw(8) << r.kol_righ_ans_ << setw(8) << r.kol_bal_ << endl;
	return out;
}

ostream& operator<<(ostream& out, const Results* r)
{
	out << right << setw(10) << r->log_ << endl;
	out << right << setw(15) << r->cat_ << setw(8) << r->kol_que_ << setw(8) << r->kol_righ_ans_ << setw(8) << r->kol_bal_ << endl;
	return out;
}
