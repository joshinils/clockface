#include "Svg.h"
#include "Style.h"

int main()
{
	double radius = 13.5;
	double radiusMinute = 11.25;
	double radiusHour = 8.25;

	Svg s("test", radius*1.1, radius*1.1);
	Style st;
	st.setDoFill(false);
	st.setDoStroke(true);
	s.addCircle(0, 0, .5, st);

	return 0;
}