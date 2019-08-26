#ifndef RGB_H
#define RGB_H

#include <ostream>
#include <string>

class Rgb
{
public:
	std::uint8_t _r;
	std::uint8_t _g;
	std::uint8_t _b;

public:
	Rgb(std::uint8_t r=0, std::uint8_t g=0, std::uint8_t b=0)
		: _r(r), _g(g), _b(b)
	{ }

	friend std::ostream& operator << (std::ostream& ostr, const Rgb& rgb)
	{
		ostr << std::string("\"rgb(") + std::to_string(rgb._r) + ", ";
		ostr <<			   std::to_string(rgb._g) + ", ";
		ostr <<			   std::to_string(rgb._b) +")\"";
		return ostr;
	}

};


#endif // !RGB_H
