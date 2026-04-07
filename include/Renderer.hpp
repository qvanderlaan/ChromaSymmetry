#ifndef RENDERER_HPP
# define RENDERER_HPP
# include <string>
# include <ImageBuffer.hpp>

class	Renderer
{
	private:
		int	_width;
		int	_height;
		int	_ss;

		void	drawSpiral(ImageBuffer &hiRes);
		void	saveImage(ImageBuffer &hiRes, const std::string &filename);

	public:
		Renderer(int width, int height, int ss);
		~Renderer(void);

		void	execute(const std::string &filename);
};

#endif
