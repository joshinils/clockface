#include "Svg.h"
#include "Style.h"

int main()
{
	double radius = 13.5;
	double radiusMinute = 11.25;
	double radiusHour = 8.25;

	Svg s("test", radius*1.01, radius*1.01);
	Style st;
	st.setDoFill(false);
	st.setDoStroke(true);
	st.setStrokeWidth(.01);
	st.setDoFill(true);
	st.setFill(Rgb(255,255,255));
	s.addCircle(0, 0, radius, st);
	s.addCircle(0, 0, radiusMinute, st);
	s.addCircle(0, 0, radiusHour, st);
	s.addCircle(0, 0, .05, st);

	return 0;
}