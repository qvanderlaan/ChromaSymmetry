#include <Renderer.hpp>

int	main(void)
{
	Renderer	engine(5120, 2880, 5);

	engine.execute("output.ppm");

	return (0);
}
