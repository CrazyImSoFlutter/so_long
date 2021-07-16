NAME = so_long

CC = gcc

CFLAGS = -O3 -Wall -Wextra -Werror -I.

MLX = mlx

LXFLAGS = -Lmlx -lmlx -framework OpenGL -framework Appkit

HEADER = cub3d.h

SRCS = file/so_long.c\
	   file/parse.c\

OBJS = $(SRCS: .c=.o)

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
