#ifndef SVG_H
#define SVG_H

#include <fstream>
#include <string>
#include "Style.h"

class Svg
{
private:
	std::string _filename;
	std::ofstream _file;

public:
	Svg(std::string fn, double width, double height);
	~Svg();
	void addExample();
	void addCircle(double cx, double cy, double r, Style s);
	void addRect(double x, double y, double width, double height, Style s, double rx=0, double ry=0);

	Svg& operator= (const Svg&) = default;

private:

};


#endif // !SVG_H
