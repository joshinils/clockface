#ifndef STYLE_H
#define STYLE_H

#include "Rgb.h"
#include <ostream>
#include <string>

#include <algorithm>

class Style
{
private:
	bool _doFill = true;
	Rgb _fill = {0,0,0}; // color or none

	double _fill_opacity; // [0,1] default 1

	bool _doStroke = false;
	Rgb _stroke = {0,0,0}; // color

	double _stroke_opacity = 1; // [0,1] default 1
	double _stroke_width = 1; // length, default 1

	bool _strokeFirst = false;

public:
	Style();
	~Style();

	void setDoFill(bool b);
	void setDoStroke(bool b);
	void setFill(const Rgb& rgb);
	void setStroke(const Rgb& rgb);
	void setStrokeWidth(double w);
	void setDoStrokeFirst(bool b);

	friend std::ostream& operator << (std::ostream& ostr, const Style& style)
	{
		if(style._doStroke)
		{
			ostr << "stroke=" << style._stroke << " ";
			ostr << "stroke-width=\"" << std::to_string(style._stroke_width) << "\" ";
		}
		else
			ostr << "stroke=\"none\" ";


		if(style._doFill)
			ostr << "fill=" << style._fill << " ";
		else
			ostr << "fill=\"none\" ";

		if(style._strokeFirst)
			ostr << "paint-order=\"stroke\" ";
		else
			ostr << "paint-order=\"fill\" ";
		return ostr;
	}
};


#endif // !STYLE_H
