#ifndef IMAGEBUFFER_HPP
# define IMAGEBUFFER_HPP
# include <Pixel.hpp>

class	ImageBuffer
{
	private:
		int		_width;
		int		_height;
		Pixel	*_data;

	public:
		ImageBuffer(int width, int height);
		~ImageBuffer(void);

		Pixel	&getPixel(int x, int y);
		int		getWidth(void) const;
		int		getHeight(void) const;
};

#endif
