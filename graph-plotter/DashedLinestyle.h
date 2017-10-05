#ifndef DASHEDLINESTYLE_H
#define DASHEDLINESTYLE_H

#include "LineStyle.h"

class DashedLinestyle: public LineStyle
{
public:
	DashedLinestyle(Colour colour, shared_ptr<Display> display_ptr):
	  LineStyle(colour,display_ptr)
	  {}
	virtual void plotLine(PointPair end_points) override;

};

#endif // DASHEDLINESTYLE_H
