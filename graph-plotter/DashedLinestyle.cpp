#include "DashedLinestyle.h"

void DashedLinestyle::plotLine(PointPair end_points)
{
		
//		PointPair newPoints{end_points.first(), end_points.second()/2.0};
	Point start = end_points.first();
	Point end=end_points.second();
	
	end.x=end.x-(end.x-start.x)/2;
	end.y=end.y-(end.y- start.y)/2;

	PointPair newPoints{start,end};
	auto display = getDisplay();
	display->drawLine(end_points, getColour());
}