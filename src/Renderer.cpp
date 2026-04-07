#include <Renderer.hpp>
#include <ColorConverter.hpp>
#include <cmath>
#include <fstream>
#include <iostream>

Renderer::Renderer(int width, int height, int ss)
	: _width(width), _height(height), _ss(ss)
{
	//
}

Renderer::~Renderer(void)
{
	//
}

void	Renderer::drawSpiral(ImageBuffer &img)
{
	double	scale = 50.0 * this->_ss;
	double	radius = 1.2 * this->_ss;
	int		W = img.getWidth();
	int		H = img.getHeight();

	for (double theta = 0; theta < 20 * M_PI; theta += 0.0008)
	{
		double	r = 4 * std::sin((240.0 / 25.0) * theta) + 10;
		double	fx = W / 2.0 + (r * std::cos(theta)) * scale;
		double	fy = H / 2.0 + (r * std::sin(theta)) * scale;

		Pixel	color = ColorConverter::hsvToRgb(std::fmod(theta / (2 * M_PI), 1.0), 0.90, 1.05);

		for (int py = (int)(fy - radius); py <= (int)(fy + radius); py++)
		{
			if (py < 0 || py >= H)
				continue ;

			for (int px = (int)(fx - radius); px <= (int)(fx + radius); px++)
			{
				if (px < 0 || px >= W)
					continue ;

				double	dx = px - fx;
				double	dy = py - fy;
				double	dist = std::sqrt(dx * dx + dy * dy);

				if (dist <= radius)
				{
					double	weight = 1.0 - (dist / radius);
					Pixel	&p = img.getPixel(px, py);

					p.r += color.r * weight;
					p.g += color.g * weight;
					p.b += color.b * weight;
				}
			}
		}
	}
}

void	Renderer::saveImage(ImageBuffer &hiRes, const std::string &filename)
{
	std::ofstream	file(filename.c_str());
	if (! file.is_open())
		return ;

	file << "P3\n" << this->_width << " " << this->_height << "\n255\n";

	double	norm = 1.0 / (this->_ss * this->_ss);

	for (int y = 0; y < this->_height; y++)
	{
		for (int x = 0; x < this->_width; x++)
		{
			double	r = 0;
			double	g = 0;
			double	b = 0;

			for (int dy = 0; dy < this->_ss; dy++)
			{
				for (int dx = 0; dx < this->_ss; dx++)
				{
					Pixel	&p = hiRes.getPixel(x * this->_ss + dx, y * this->_ss + dy);
					r += p.r; g += p.g; b += p.b;
				}
			}
			file << (int)std::min(r * norm * 1.05, 255.0) << " "
				 << (int)std::min(g * norm * 1.05, 255.0) << " "
				 << (int)std::min(b * norm * 1.05, 255.0) << " ";
		}
		file << "\n";
	}
	file.close();
}

void	Renderer::execute(const std::string &filename)
{
	std::cout
		<< "Rendering "
		<< this->_width
		<< "x"
		<< this->_height
		<< "..."
		<< std::endl;

	ImageBuffer	hiRes(this->_width * this->_ss, this->_height * this->_ss);

	this->drawSpiral(hiRes);
	this->saveImage(hiRes, filename);
}
