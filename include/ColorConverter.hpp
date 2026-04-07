#ifndef COLORCONVERTER_HPP
# define COLORCONVERTER_HPP
# include <Pixel.hpp>

class	ColorConverter
{
	public:
		static Pixel	hsvToRgb(double h, double s, double v);
};

#endif
