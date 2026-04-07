#include <ImageBuffer.hpp>

ImageBuffer::ImageBuffer(int width, int height)
	: _width(width), _height(height)
{
	this->_data = new Pixel[width * height];
}

ImageBuffer::~ImageBuffer(void)
{
	delete[]	this->_data;
}

Pixel	&ImageBuffer::getPixel(int x, int y)
{
	return (this->_data[y * this->_width + x]);
}

int	ImageBuffer::getWidth(void) const
{
	return (this->_width);
}

int	ImageBuffer::getHeight(void) const
{
	return (this->_height);
}
