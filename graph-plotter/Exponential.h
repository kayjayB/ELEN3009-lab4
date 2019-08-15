#ifndef EXPONENTIAL_H
#define EXPONENTIAL_H

#include <cmath>
#include "Function.h"

class Exponential: public Function
{
public:
	Exponential(double A, double b);
	~Exponential();
	

	virtual float evaluate(float x) const override;

private:
double _A;
double _b;
};

#endif // EXPONENTIAL_H
