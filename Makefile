NAME		=	spiral_gen

CC			=	c++
INCLUDE_DIR	=	include/
OBJ_DIR		=	build/
CFLAGS		=	-Wall -Wextra -Werror -std=c++98 -O3 -I$(INCLUDE_DIR)

SRCS		=	src/main.cpp src/Pixel.cpp src/ImageBuffer.cpp src/ColorConverter.cpp src/Renderer.cpp
OBJS		=	$(patsubst src/%.cpp,$(OBJ_DIR)%.o,$(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJ_DIR)%.o: src/%.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
