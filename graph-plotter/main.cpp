#include "Graph.h"
#include "Sinusoid.h"
#include "Sampler.h"
#include "Display.h"
#include "SolidLineStyle.h"
#include "Points.h"
#include "DotLineStyle.h"
#include "DashedLinestyle.h"
#include "Exponential.h"
#include "Polynomial.h"
#include "Absolute.h"
#include <memory>

using std::shared_ptr;
using std::make_shared;

const float PI = 3.14159265359;

int main()
{
	// setup Graph with Display
	const int WIDTH = 800;
	const int HEIGHT = 600;
	shared_ptr<Display> display = make_shared<Display>(WIDTH, HEIGHT);
	Graph graph(display);

	// create sine and cosine functions
	float amplitude = 1.0;
	float frequency = 1.0;
	float phase = 0;
	Sinusoid sine_function{amplitude, frequency, phase};
	Sinusoid cosine_function{amplitude, frequency, phase + PI/2};

	// generate range and plot graphs
	Range range{0, 6*PI};
	SolidLineStyle solid_red{Colour::Red, display};
	graph.plot(generateDataPoints(sine_function, range), solid_red);
	
	DashedLinestyle dashedGreen{Colour::Green, display};
	graph.plot(generateDataPoints(sine_function, range), dashedGreen);

	DotLineStyle dotBlue{Colour::Blue, display};
	graph.plot(generateDataPoints(cosine_function, range), dotBlue);
	
	double A=1;
	double b=1.5;
	Range range2{-3,1.5};
	Exponential exp{A,b};
	graph.plot(generateDataPoints(exp, range2), dotBlue);
	
	std::vector<float> coeff{1,2,1};
	int order=2;
	Range range3{-3,1.5};
	Polynomial poly{coeff, order};
	graph.plot(generateDataPoints(poly, range3), dotBlue);
	
	std::vector<float> coeff2{1,-3,-4};
	Range range4{-4,7};
	std::shared_ptr <Polynomial> poly2= std::make_shared <Polynomial> (coeff2, order);
	Absolute abs{poly2};
	graph.plot(generateDataPoints(abs, range4), dotBlue);

	return 0;
}

// The number of points used to plot the graph is too few (ie. the resolution is poor) leading to
// graphs that are not smooth. This is imporved by increasing the total number of points in the 
// sampler class.

// Question 3.5:
// Rendering of Fourier transforms and bode plots
// Object for x axis, object for y-axis

// Question 3.6:
// The screen is updated each time you render and the display function overwrites everything that 
// was previously on the screen