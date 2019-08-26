#define _USE_MATH_DEFINES
#include <math.h>
#include "Svg.h"
#include "Style.h"
#include <vector>
#include <iostream>
#include <cstdlib>

double radius = 13.5;
double radiusMinute = 11.25;
double radiusHour = 8.25;

void drawCircleSegments(Svg& s, double radius, int numPoints)
{
	Style st;

	std::vector<std::pair<double, double>> points_H(numPoints);
	std::vector<std::pair<double, double>> points_E(numPoints);

	for (size_t i = 0; i < numPoints; i++)
	{
		double t = (double(i)*M_PI*2)/numPoints;
		points_H[i].first  = 0*cos(t);
		points_H[i].second = 0*sin(t);
		points_E[i].first  = (radius)*cos(t);
		points_E[i].second = (radius)*sin(t);
	}

	/*	st.setDoFill(false);
	st.setStrokeWidth(.1);
	s.addPolygon(points_H, st);
	*/

	Rgb rgb(rand()%256, rand()%256, rand()%256);

	st.setDoFill(true);
	st.setDoStroke(false);
	st.setStrokeWidth(.01);
	st.setDoStrokeFirst(true);

	for (size_t i = 0; i < numPoints; i++)
	{
		std::vector<std::pair<double, double>> polygonP(4);
		polygonP[0] = points_E[i];
		polygonP[1] = points_H[i];
		polygonP[2] = points_H[(i+1) % numPoints];
		polygonP[3] = points_E[(i+1) % numPoints];

		st.setFill(rgb);
		st.setStroke(rgb);

		rgb._r += rand()%128;
		rgb._g += rand()%128;
		rgb._b += rand()%128;

		s.addPolygon(polygonP, st);
	}

}

int main()
{
	std::srand(0);

	double scale = 100;
	radius *= scale;
	radiusMinute*= scale;
	radiusHour *= scale;
	Svg s("test", radius*1.01, radius*1.01);
	Style st;

	int numPoints = 100;

	double r = radius;
	double dist = r/numPoints*M_PI*2;
	for (size_t i = 0; i < 100; i++)
	{
		if(r < .1)
			break;
		r -= dist;
		double U = 2*M_PI*r;
		numPoints = U / dist;
		drawCircleSegments(s, r, numPoints);
	}

//	st.setDoStroke(true);
//	st.setStrokeWidth(.01);
//	st.setFill(Rgb(255,255,255));
//	st.setDoFill(false);
//	s.addCircle(0, 0, radius, st);
//	s.addCircle(0, 0, radiusMinute, st);
//	s.addCircle(0, 0, radiusHour, st);
//	s.addCircle(0, 0, .05, st);

	return 0;
}