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

double B = 52.5 * M_PI / 180;
double L = 13.5;

std::pair<double, double> colFromCoord(double x, double horizonthoehe)
{
	double T = x;
	double deklination = 0.4095 * sin(0.016906 * (T - 80.086) );
	double zeitgleichung = -0.171 * sin( 0.0337 * T  + 0.465 ) - 0.1299 * sin( 0.01787 * T - 0.168 );
	double h = horizonthoehe * M_PI / 180; // horizonthöhe
	double arg = (sin(h) - sin(B)*sin(deklination)) / (cos(B)*cos(deklination));
	if (arg < -1)
		arg = -1;
	else if (arg > 1)
		arg = 1;
	double Zeitdifferenz = 12 * acos(arg)/M_PI ;
	double aufgangOrtszeit = 12 - Zeitdifferenz - zeitgleichung;
	double untergangOrtszeit = 12 + Zeitdifferenz - zeitgleichung;
	double zeitzone = 1;
	double aufgang = aufgangOrtszeit - L/15 + zeitzone;
	double untergang = untergangOrtszeit - L/15 + zeitzone;

	std::cout << "aufgang " << aufgang << " untergang " << untergang << std::endl;

	if(aufgang != aufgang)
	{
		double a = 0;
	}

	return std::make_pair(aufgang, untergang);
}

const int y = 366;
const int x = 366;
std::vector<std::vector<Rgb>> Image(x, std::vector<Rgb>(y));

void drawCircleSegments(Svg& s, double rad, int xAxis)
{
	Style st;

	std::vector<std::pair<double, double>> points_H(xAxis);
	std::vector<std::pair<double, double>> points_E(xAxis);

	for (size_t i = 0; i < xAxis; i++)
	{
		double t = (double(i)*M_PI*2)/xAxis;
		points_H[i].first  = 0*cos(t);
		points_H[i].second = 0*sin(t);
		points_E[i].first  = (rad)*cos(t);
		points_E[i].second = (rad)*sin(t);
	}

	/*	st.setDoFill(false);
	st.setStrokeWidth(.1);
	s.addPolygon(points_H, st);
	*/


	st.setDoFill(true);
	st.setDoStroke(false);
	st.setStrokeWidth(.01);
	st.setDoStrokeFirst(true);

	for (size_t i = 0; i < xAxis; i++)
	{
		std::vector<std::pair<double, double>> polygonP(4);
		polygonP[0] = points_E[i];
		polygonP[1] = points_H[i];
		polygonP[2] = points_H[(i+1) % xAxis];
		polygonP[3] = points_E[(i+1) % xAxis];


		double j = rad * y / radius -1;
		if(j < 0 || j >= y)
		{
			// breakpoint fuck up spot
			double a = 0;
		}
		Rgb rgb = Image[std::max(0.0,floor(j))][ (i + xAxis -xAxis/4) % xAxis ];
		st.setFill(rgb);
		st.setStroke(rgb);

		s.addPolygon(polygonP, st);
	}
}


int main()
{
	std::srand(0);

//	bool checker = false;
	for (size_t i = 0; i < x; i++)
	{
		for (size_t j = 0; j < y; j++)
		{
//			Image[i][j] = Rgb(100 + checker * 100, 0, checker * 200);
			Image[i][j] = Rgb(135, 206, 235);//(220,234,255)
//			checker = !checker;
		}
//		checker = !checker;
	}

	// h-loop
	std::vector<double> horizons;
	std::vector<Rgb> colours;
	horizons.push_back(1);
	colours.push_back(Rgb(255, 204, 51));

	horizons.push_back(-50/60);
	colours.push_back(Rgb(136,166,212));

	horizons.push_back(-6);
	colours.push_back(Rgb(69,116,188));

	horizons.push_back(-12);
	colours.push_back(Rgb(33,60,102));

	horizons.push_back(-18);
	colours.push_back(Rgb(25,32,41));


	for (size_t hIndex = 0; hIndex < horizons.size(); hIndex++)
	{
		double h = horizons[hIndex];
		for (size_t i = 0; i < x; i++)
		{
			auto uhrzeiten = colFromCoord(i, h);
			int aufgang = std::min(floor(uhrzeiten.first * y / 24), y-1.0);
			int untergang = std::min(floor(uhrzeiten.second * y / 24), y-1.0);

//			std::cout << uhrzeiten.first << " " << uhrzeiten.second << " ";
//			std::cout << "aufgang " << aufgang << " untergang " << untergang << std::endl;

			for (size_t j = 0; j < aufgang; j++)
			{
				Image[i][j] = colours[hIndex];
			}
			for (size_t j = untergang; j < y; j++)
			{
				Image[i][j] = colours[hIndex];
			}
		}
	}


	// drawing
	double scale = 100;
	radius *= scale;
	radiusMinute*= scale;
	radiusHour *= scale;
	Svg s("test", radius*1.01, radius*1.01);
	Style st;

	double r = radius;
	double dist = r/y;
	for (size_t i = 0; i < y; i++)
	{
		std::cout <<"i"<< i << "	r" << r << "	d" << dist << "	x" << x << std::endl;

		if(r <= 0)
			break;

		double U = 2*M_PI*r;
//		numPoints = U / dist;

		if(x > 5000)
			break;

//		dist *= 1.05;
		drawCircleSegments(s, r, x);
		r -= dist;
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