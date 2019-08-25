#ifndef RGB_H
#define RGB_H

#include <ostream>
#include <string>

class Rgb
{
private:
	uint8_t _r;
	uint8_t _g;
	uint8_t _b;
public:
	Rgb(uint8_t r=0, uint8_t g=0, uint8_t b=0)
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
