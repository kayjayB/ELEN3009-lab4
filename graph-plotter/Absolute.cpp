#include "Absolute.h"

Absolute::Absolute(std::shared_ptr<Function> functPtr):
 _functPtr{functPtr}
{
}

Absolute::~Absolute()
{
}

float Absolute::evaluate(float x) const
{
	float y=_functPtr->evaluate(x);
	return abs(y);
}