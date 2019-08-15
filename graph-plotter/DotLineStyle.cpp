#include "DotLineStyle.h"

void DotLineStyle::plotLine(PointPair end_points)
{
		auto display = getDisplay();
		display->drawDot(end_points.first(), getColour());
}