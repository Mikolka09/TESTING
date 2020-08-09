#pragma once
#include"Tests.h"

class Algebra;
class Geometry;

class Maths
{
private:

	list<Tests> base_alg;
	list<Tests> base_geo;

public:

	void menuMaths();
	void addTest();

};

class Algebra :public Maths
{
private:

	Tests test_alg;

public:

	void creatureTestAlg();
	void editTestAlg();

};

class Geometry :public Maths
{
private:

	Tests test_geo;

public:
	void creatureTestGeo();
	void editTestGeo();

};

