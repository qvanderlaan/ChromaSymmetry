#include <ColorConverter.hpp>

Pixel	ColorConverter::hsvToRgb(double h, double s, double v)
{
	if (s <= 0.0)
		return (Pixel(v * 255.0, v * 255.0, v * 255.0));

	double	hh = (h >= 1.0 ? 0.0 : h) * 6.0;
	int		i  = (int)hh;
	double	ff = hh - i;

	double	p = v * (1.0 - s);
	double	q = v * (1.0 - (s * ff));
	double	t = v * (1.0 - (s * (1.0 - ff)));

	double	r;
	double	g;
	double	b;

	switch (i)
	{
		case 0:		r = v; g = t; b = p; break;
		case 1:		r = q; g = v; b = p; break;
		case 2:		r = p; g = v; b = t; break;
		case 3:		r = p; g = q; b = v; break;
		case 4:		r = t; g = p; b = v; break;
		default:	r = v; g = p; b = q; break;
	}

	return (Pixel(r * 255.0, g * 255.0, b * 255.0));
}
