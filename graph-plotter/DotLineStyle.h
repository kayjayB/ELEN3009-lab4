#ifndef DOTLINESTYLE_H
#define DOTLINESTYLE_H

#include "LineStyle.h"

class DotLineStyle: public LineStyle
{
public:
	DotLineStyle(Colour colour, shared_ptr<Display> display_ptr):
	  LineStyle(colour,display_ptr)
	  {}
	virtual void plotLine(PointPair end_points) override;

};

#endif // DOTLINESTYLE_H
