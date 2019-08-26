#ifndef SVG_H
#define SVG_H

#include <fstream>
#include <string>
#include "Style.h"
#include <vector>

class Svg
{
private:
	std::string _filename;
	std::ofstream _file;

public:
	Svg(std::string fn, double width, double height);
	~Svg();
	void addExample();
	void addCircle(double cx, double cy, double r, const Style& s);
	void addRect(double x, double y, double width, double height, const Style& s, double rx=0, double ry=0);
	void addPolygon(const std::vector<std::pair<double, double>>& p, const Style& s);

	Svg& operator= (const Svg&) = default;

private:

};


#endif // !SVG_H
