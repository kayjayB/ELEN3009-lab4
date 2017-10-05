#include "Exponential.h"

Exponential::Exponential(double A, double b):
_A{A},
_b{b}
{
}

Exponential::~Exponential()
{
}

float Exponential::evaluate(float x) const
{
	return _A*exp(_b*x);
}