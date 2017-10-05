#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <vector>
#include "Function.h"
#include <cmath>

class Polynomial: public Function
{
public:
	Polynomial(std::vector<float> coefficients, int order);
	~Polynomial();
float evaluate(float x) const override;
private:
std::vector<float> _coeffs;
int _order;
std::vector<int> _powerOfX;
};

#endif // POLYNOMIAL_H
