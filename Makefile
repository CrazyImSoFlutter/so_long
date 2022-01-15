NAME = so_long

CC = gcc

CFLAGS = -O1 -Wall -Wextra -Werror -I.

MLX = mlx

LXFLAGS = -Lmlx -lmlx -framework OpenGL -framework Appkit

HEADER = so_long.h

SRC_PATH = ./file/

SRC_GNL = get_next_line.c\
		  get_next_line_utils.c\

SRC_DRAW = draw_player.c\
		   draw_tiles.c\
		   draw_utils.c\
		   draw_exit.c\
		   draw_point.c\
		   draw_end.c\
		   draw_enemy.c\
		   set_img.c\

SRC_GAME = intro.c\
		   object.c\
		   exit.c\
		   so_long.c\
		   enemy.c\
		   enemy2.c\

SRC_INIT = init.c\
		   parse.c\
		   pos.c\
		   supplement.c\
		   tex.c\

SRC_KEY = key.c\
		  key_act.c\
		  key_quit.c\

SRC_TOOL = tool.c\
		   random.c\

SRCS = $(addprefix gnl/, $(SRC_GNL))\
	   $(addprefix $(SRC_PATH)draw/, $(SRC_DRAW))\
	   $(addprefix $(SRC_PATH)game/, $(SRC_GAME))\
	   $(addprefix $(SRC_PATH)init/, $(SRC_INIT))\
	   $(addprefix $(SRC_PATH)key/, $(SRC_KEY))\
	   $(addprefix $(SRC_PATH)tool/, $(SRC_TOOL))\

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
