#ifndef SINUSOID_H
#define SINUSOID_H

#include "Function.h"

class Sinusoid: public Function
{
public:
	Sinusoid(float amplitude=1.0, float frequency = 1.0, float phase=0.0):
	_amplitude(amplitude),
	_frequency(frequency),
	_phase(phase)
	{}

	virtual float evaluate(float x) const override;

private:
	float _amplitude;
	float _frequency;
	float _phase;
};

#endif