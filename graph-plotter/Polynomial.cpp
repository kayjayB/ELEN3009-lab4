#include "Polynomial.h"

Polynomial::Polynomial(std::vector<float> coefficients, int order):
 _coeffs{coefficients},
 _order{order}
{
	for (int i=_order; i!=-1; i--)
	{
		_powerOfX.push_back(i);
	}
}

Polynomial::~Polynomial()
{
}

float Polynomial::evaluate(float x) const
{
	float ans=0;
	
	std::vector<float> powerVec;
	
	for (auto i=begin(_powerOfX); i!=end(_powerOfX);i++)
	{
		powerVec.push_back(pow(x,*i));
	}
	
	for (int i=0; i!=_order; i++)
	{
		ans= ans+powerVec[i]*_coeffs[i];
	}
	
	return ans;
}
