#include "Style.h"

Style::Style()
{
}

Style::~Style()
{
}

void Style::setDoFill(bool b)
{
	_doFill = b;
}

void Style::setDoStroke(bool b)
{
	_doStroke = b;
}

void Style::setFill(const Rgb & rgb)
{
	_doFill = true;
	_fill = rgb;
}

void Style::setStroke(const Rgb & rgb)
{
	_doStroke = true;
	_stroke = rgb;
}

void Style::setStrokeWidth(double w)
{
	_stroke_width = std::max(0.0, std::min(w, 1.0));
}

void Style::setDoStrokeFirst(bool b)
{
	_strokeFirst = b;
}

