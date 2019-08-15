#include "Sampler.h"

DataPoints Sampler::generateSamples(const Function& funct, const Range& range) const
{
	// divide by TOTAL_POINTS-1 to ensure that x_max is included in the range as the last point
	auto increment = range.size()/(TOTAL_POINTS-1);
	auto current_x = range.getStart();
	vector<Point> points;

	for (int i = 0 ; i != TOTAL_POINTS ; i++)
	{
		Point newpoint{current_x, funct.evaluate(current_x)};
		points.push_back(newpoint);
		current_x = current_x + increment;
	}

	DataPoints data_points(points);
	return data_points;
}

// standalone function generating data points
DataPoints generateDataPoints(const Function& funct, const Range& range, const Sampler& sampler)
{
	DataPoints data_points(sampler.generateSamples(funct, range));
	return data_points;
}
