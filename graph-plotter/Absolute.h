#ifndef ABSOLUTE_H
#define ABSOLUTE_H

#include <cmath>
#include <memory>
#include "Function.h"

class Absolute: public Function
{
public:
	Absolute(std::shared_ptr<Function> functPtr);
	~Absolute();
	
float evaluate(float x) const;

private:
std::shared_ptr<Function> _functPtr;

};

#endif // ABSOLUTE_H
