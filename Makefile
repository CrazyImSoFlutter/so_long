NAME = so_long
NAME_BONUS = so_long_bonus

CC = gcc

CFLAGS = -O1 -Wall -Wextra -Werror -I.

MLX = mlx

LXFLAGS = -Lmlx -lmlx -framework OpenGL -framework Appkit

HEADER = so_long.h

SRC_PATH = ./file/
BNS_PATH = ./bonus_file/
C = .c
S = _bonus.c

SRC_GNL = get_next_line\
		  get_next_line_utils\

SRC_DRAW = draw_tiles\
		   draw_end\
		   draw_character\
		   draw_utils\
		   set_img\

SRC_GAME = intro\
		   object\
		   exit\
		   so_long\
		   main_loop\

SRC_INIT = pos\
		   supplement\
		   init_variable\
		   init\
		   tex\

SRC_KEY = key\
		  key_act\
		  key_act_support\
		  key_quit\

SRC_PARSE = parse\
			parse_check_map\
			parse_check_win\
			check_argument\

SRC_TOOL = tool\
		   random\
		   error\

BNS_DRAW = draw_exit\
		   draw_point\

BNS_GAME = enemy\
		   enemy2\

BNS_INIT = init2\

SRCS = $(addsuffix $(C), $(addprefix gnl/, $(SRC_GNL)))\
	   $(addsuffix $(C), $(addprefix $(SRC_PATH)draw/, $(SRC_DRAW)))\
	   $(addsuffix $(C), $(addprefix $(SRC_PATH)game/, $(SRC_GAME)))\
	   $(addsuffix $(C), $(addprefix $(SRC_PATH)init/, $(SRC_INIT)))\
	   $(addsuffix $(C), $(addprefix $(SRC_PATH)key/, $(SRC_KEY)))\
	   $(addsuffix $(C), $(addprefix $(SRC_PATH)tool/, $(SRC_TOOL)))\
	   $(addsuffix $(C), $(addprefix $(SRC_PATH)parse/, $(SRC_PARSE)))\

SRCS_BONUS = $(addsuffix $(C), $(addprefix gnl/, $(SRC_GNL)))\
			 $(addsuffix $(S), $(addprefix $(BNS_PATH)draw/, $(SRC_DRAW)))\
			 $(addsuffix $(S), $(addprefix $(BNS_PATH)game/, $(SRC_GAME)))\
			 $(addsuffix $(S), $(addprefix $(BNS_PATH)init/, $(SRC_INIT)))\
			 $(addsuffix $(S), $(addprefix $(BNS_PATH)key/, $(SRC_KEY)))\
			 $(addsuffix $(S), $(addprefix $(BNS_PATH)tool/, $(SRC_TOOL)))\
			 $(addsuffix $(S), $(addprefix $(BNS_PATH)parse/, $(SRC_PARSE)))\
			 $(addsuffix $(S), $(addprefix $(BNS_PATH)draw/, $(BNS_DRAW)))\
			 $(addsuffix $(S), $(addprefix $(BNS_PATH)game/, $(BNS_GAME)))\
			 $(addsuffix $(S), $(addprefix $(BNS_PATH)init/, $(BNS_INIT)))\

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(MLX) $(OBJS)
		$(CC) $(CFLAGS) -g -o $(NAME) $(OBJS) $(LXFLAGS)

$(MLX):
		@$(MAKE) -C mlx

clean:
	rm -rf $(OBJS)
	rm -rf $(OBJS_BONUS)

fclean:		clean
				rm -rf $(NAME)
				rm -rf $(NAME_BONUS)

re: fclean all

bonus: $(NAME_BONUS)
	
$(NAME_BONUS): $(MLX) $(OBJS_BONUS)
			$(CC) $(CFLAGS) -g -o $(NAME_BONUS) $(OBJS_BONUS) $(LXFLAGS)
