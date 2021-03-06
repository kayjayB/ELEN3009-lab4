#ifndef SAMPLER_H
#define SAMPLER_H

#include "DataPoints.h"
#include "Sinusoid.h"
#include "Exponential.h"
#include "Function.h"

class Sampler
{
public:
	// performs uniform sampling
	DataPoints generateSamples(const Function& funct, const Range& range) const;

private:
	static const int TOTAL_POINTS = 500;
};

// standalone function for generating data points, a default uniform sampler is provided
DataPoints generateDataPoints(const Function& funct, const Range& range, const Sampler& sampler = Sampler{});

#endif
