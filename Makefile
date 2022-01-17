NAME = so_long

CC = gcc

CFLAGS = -O1 -Wall -Wextra -Werror -I.

MLX = mlx

LXFLAGS = -Lmlx -lmlx -framework OpenGL -framework Appkit

HEADER = so_long.h

SRC_PATH = ./file/

SRC_GNL = get_next_line.c\
		  get_next_line_utils.c\

SRC_DRAW_MAIN = draw_tiles.c\
		   		draw_exit.c\
				draw_end.c\

SRC_DRAW = draw_character.c\
		   draw_point.c\
		   draw_utils.c\
		   set_img.c\

SRC_GAME_MAIN = intro.c\
				object.c\
				exit.c\
				so_long.c\

SRC_GAME = main_loop.c\

SRC_INIT_MAIN = pos.c\
				supplement.c\
				tex.c\

SRC_INIT = init.c\
		   init2.c\
		   init_variable.c\

SRC_KEY = key.c\
		  key_act.c\
		  key_quit.c\

SRC_PARSE = parse.c\
			parse_check_map.c\
			parse_check_win.c\
			check_argument.c\

SRC_TOOL = tool.c\
		   random.c\
		   error.c\

SRC_DRAW_BONUS = draw_character_bonus.c\
				 draw_point_bonus.c\
				 draw_utils_bonus.c\
				 set_img_bonus.c\

SRC_GAME_BONUS = enemy_bonus.c\
				 enemy2_bonus.c\
				 main_loop_bonus.c\

SRC_INIT_BONUS = init_bonus.c\
				 init2_bonus.c\
				 tex_bonus.c\

SRCS_MANDATORY = $(addprefix gnl/, $(SRC_GNL))\
				 $(addprefix $(SRC_PATH)draw/, $(SRC_DRAW_MAIN))\
				 $(addprefix $(SRC_PATH)draw/, $(SRC_DRAW))\
				 $(addprefix $(SRC_PATH)game/, $(SRC_GAME_MAIN))\
				 $(addprefix $(SRC_PATH)game/, $(SRC_GAME))\
				 $(addprefix $(SRC_PATH)init/, $(SRC_INIT_MAIN))\
				 $(addprefix $(SRC_PATH)init/, $(SRC_INIT))\
				 $(addprefix $(SRC_PATH)key/, $(SRC_KEY))\
				 $(addprefix $(SRC_PATH)tool/, $(SRC_TOOL))\
				 $(addprefix $(SRC_PATH)parse/, $(SRC_PARSE))\

SRCS_BONUS = $(addprefix gnl/, $(SRC_GNL))\
			 $(addprefix $(SRC_PATH)draw/, $(SRC_DRAW_MAIN))\
			 $(addprefix $(SRC_PATH)bonus_draw/, $(SRC_DRAW_BONUS))\
			 $(addprefix $(SRC_PATH)game/, $(SRC_GAME_MAIN))\
			 $(addprefix $(SRC_PATH)bonus_game/, $(SRC_GAME_BONUS))\
			 $(addprefix $(SRC_PATH)init/, $(SRC_INIT_MAIN))\
			 $(addprefix $(SRC_PATH)bonus_init/, $(SRC_INIT_BONUS))\
			 $(addprefix $(SRC_PATH)key/, $(SRC_KEY))\
			 $(addprefix $(SRC_PATH)tool/, $(SRC_TOOL))\
			 $(addprefix $(SRC_PATH)parse/, $(SRC_PARSE))\

OBJS_MANDATORY = $(SRCS_MANDATORY:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(MLX) $(OBJS_MANDATORY)
		$(CC) $(CFLAGS) -g -o $(NAME) $(OBJS_MANDATORY) $(LXFLAGS)

$(MLX):
		@$(MAKE) -C mlx

bonus: $(MLX) $(OBJS_BONUS)
		$(CC) $(CFLAGS) -g -o $(NAME) $(OBJS_BONUS) $(LXFLAGS)

clean:
	rm -rf $(OBJS_MANDATORY)
	rm -rf $(OBJS_BONUS)

fclean:		clean
				rm -rf $(NAME)

re: fclean all
