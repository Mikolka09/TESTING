#include "Results.h"

ostream& operator<<(ostream& out, const Results& r)
{
	//out << right << setw(10) << r.log_ << endl;
	out << right << setw(15) << r.cat_ << setw(8) << r.kol_righ_ans_ << setw(8) << r.kol_que_ << setw(8) << r.kol_bal_ << endl;
	return out;
}

ostream& operator<<(ostream& out, const Results* r)
{
	//out << right << setw(10) << r->log_ << endl;
	out << right << setw(15) << r->cat_ << setw(8) << r->kol_righ_ans_ << setw(8) << r->kol_que_<< setw(8) << r->kol_bal_ << endl;
	return out;
}

Results::Results(const Results& ob)
{
	log_ = ob.log_;
	cat_ = ob.cat_;
	kol_que_ = ob.kol_que_;
	kol_righ_ans_ = ob.kol_righ_ans_;
	kol_bal_ = ob.kol_bal_;
}

Results& Results::operator=(const Results& ob)
{
	log_ = ob.log_;
	cat_ = ob.cat_;
	kol_que_ = ob.kol_que_;
	kol_righ_ans_ = ob.kol_righ_ans_;
	kol_bal_ = ob.kol_bal_;
	return *this;
}
