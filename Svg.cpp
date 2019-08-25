#include "Svg.h"
#include <fstream>
#include "Style.h"
#include "Rgb.h"
Svg::Svg(std::string fn, double width, double height)
	: _filename(fn + ".svg"),
	_file(_filename, std::fstream::out)
{
	_file << std::string("<svg xmlns=\"http://www.w3.org/2000/svg\" viewBox=\" -") + std::to_string(width) + " -" + std::to_string(height) + " " + std::to_string(width*2) + " " + std::to_string(height*2) +" \">\n";
	Style rectStyle;
	rectStyle.setFill(Rgb(128,128,128));
	rectStyle.setStroke(Rgb(0,0,0));
	rectStyle.setStrokeWidth(.1);
	addRect(-width, -height, width*2, height*2, rectStyle);
}

Svg::~Svg()
{
	_file << std::string("\n</svg>");
	_file.close();
}

void Svg::addExample()
{
	_file << std::string("\n"
		"\t<circle cx=\"5\" cy=\"5\" r=\"4\" stroke=\"green\" stroke-width=\"1\" fill=\"yellow\" />\n");
}

void Svg::addCircle(double cx, double cy, double r, Style s)
{
	_file << std::string("\n") +
	"\t<circle "
	"cx=\"" + std::to_string(cx) + "\" "
	"cy=\"" + std::to_string(cy) + "\" "
	"r=\""  + std::to_string(r) + "\" ";
	_file << s;
	_file <<"/>\n";
}

void Svg::addRect(double x, double y, double width, double height, Style s, double rx /* = 0 */, double ry /* = 0 */)
{
	_file <<
		"\t<rect "
		"x=\"" + std::to_string(x) + "\" "
		"y=\"" + std::to_string(y) + "\" "
		"width=\"" + std::to_string(width) + "\" "
		"height=\"" + std::to_string(height) + "\" "
		"rx=\"" + std::to_string(rx) + "\" "
		"ry=\"" + std::to_string(ry) + "\" ";
	_file << s;
	_file <<"/>\n";
}

