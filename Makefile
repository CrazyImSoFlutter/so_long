NAME = so_long

CC = gcc

CFLAGS = -O3 -Wall -Wextra -Werror -I.

MLX = mlx

LXFLAGS = -Lmlx -lmlx -framework OpenGL -framework Appkit

HEADER = so_long.h

SRCS = gnl/get_next_line.c\
	   gnl/get_next_line_utils.c\
	   file/so_long.c\
	   file/tex.c\
	   file/init.c\
	   file/parse.c\
	   file/tool.c\
	   file/draw.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(MLX) $(OBJS)
		$(CC) $(CFLAGS) -g -o $(NAME) $(OBJS) $(LXFLAGS)

$(MLX):
		@$(MAKE) -C mlx

clean:
	rm -rf $(OBJS)

fclean:		clean
				rm -rf $(NAME)

re: fclean all
