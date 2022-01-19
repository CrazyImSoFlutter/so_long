/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noguen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 23:19:27 by noguen            #+#    #+#             */
/*   Updated: 2022/01/19 15:33:21 by noguen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include "mlx/mlx.h"
# include "gnl/get_next_line.h"

# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_ENTER 36
# define KEY_SPACE 49
# define KEY_Q 12
# define KEY_ESC 53
# define P_MOVE_SPEED 3
# define E_MOVE_SPEED 2
# define VERTICAL 0
# define HORIZONTAL 1
# define LEFT 0
# define RIGHT 1
# define UP 2
# define DOWN 3

typedef struct s_mlx {
	void		*ptr;
}				t_mlx;

typedef struct s_win {
	void		*ptr;
	int			x;
	int			y;
	int			frame;
	int			intro_flag;
	int			tile_flag;
}				t_win;

typedef struct s_img {
	void		*ptr;
	int			*data;
	int			width;
	int			height;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct s_map {
	char		**map;
	char		**sup;
	int			x;
	int			y;
	int			mapx;
	int			mapy;
	int			spr;
	int			exit_flag;
	int			exit_frame;
	int			exit_y;
	int			exit_x;
}				t_map;

typedef struct s_tex {
	int			*intro[8];
	int			*player_left[8];
	int			*player_right[8];
	int			*enemy_left[8];
	int			*enemy_right[8];
	int			*exit[8];
	int			*sand;
	int			*wall;
	int			*object;
	int			*black;
	int			*win;
	int			*lose;
}				t_tex;

typedef struct s_player {
	int			pos_y;
	int			pos_x;
	int			pos_map_y;
	int			pos_map_x;
	int			move;
	int			frame;
	int			direction;
	int			*img;
	int			win_flag;
}				t_player;

typedef struct s_enemy {
	int			pos_y;
	int			pos_x;
	int			base_direction;
	int			direction;
	int			move_speed;
	int			frame;
	int			*img;
}				t_enemy;

typedef struct s_key {
	int			w;
	int			a;
	int			s;
	int			d;
	int			n;
	int			q;
	int			space;
}				t_key;

typedef struct s_err {
	int			n;
}				t_err;

typedef struct s_pair {
	int			x;
	int			y;
}				t_pair;

typedef struct s_bfs {
	int			dy[4];
	int			dx[4];
	int			visit[10][20];
	t_pair		q[500];
	int			q_size;
	int			y;
	int			x;
	int			index;
}				t_bfs;

typedef struct s_all {
	t_mlx		mlx;
	t_win		win;
	t_img		img;
	t_map		map;
	t_tex		tex;
	t_player	player;
	t_key		key;
	t_err		err;
	t_enemy		enemy[3];
	t_bfs		bfs;
	int			object_count;
	int			init_max;
	long		holdrand;
}				t_all;

/************about draw directory************/
/*about draw_character*/
void			draw_player_tile(t_all *s);
void			draw_enemy_tile(t_all *s);
void			set_order(t_all *s, int *tmp);
void			draw_player_enemy(t_all *s);
void			draw_character(t_all *s);

/*about draw_exit*/
void			draw_exit(t_all *s);

/*about draw_tiles*/
void			draw_put_image_tile(t_all *s, int y, int x);
void			draw_tiles(t_all *s);

/*about set_img*/
void			set_player_image(t_all *s);
void			set_enemy_image(t_all *s, int n);

/*about draw_end*/
void			draw_end(t_all *s);
void			draw_result(t_all *s);

/*about draw_point*/
void			draw_point(t_all *s);

/*about draw_utils*/
void			draw_put_image(t_all *s, void *img_ptr, int x, int y);
void			draw_tile_again(t_all *s, int pos_y, int pos_x, int dir);
void			draw_check(t_all *s, int *a, int *visit, int i);

/************about game directory************/
/*about enemy*/
void			move_up_enemy(t_all *s, int n);
void			move_down_enemy(t_all *s, int n);
void			move_left_enemy(t_all *s, int n);
void			move_right_enemy(t_all *s, int n);

/*about exit*/
void			find_exit(t_all *s);
void			win_exit(t_all *s);

/*about main_loop*/
int				main_loop(t_all *s);
void			game_play(t_all *s);
void			game_end(t_all *s);

/*about enemy2*/
void			enemy_patrol(t_all *s, int n);
void			enemy_win(t_all *s);

/*about intro*/
void			intro(t_all *s);

/*about object*/
void			object_count(t_all *s);
void			object_get(t_all *s);

/************about init directory************/
/*about init*/
void			init_parse(t_all *s, char **argv);
void			init_element(t_all *s);
void			init_screen(t_all *s);
void			init_loop(t_all *s);
void			init_so_long(t_all *s, char **argv);

/*about init2*/
void			init_enemy(t_all *s);
void			init_set_enemy(t_all *s, int *n);
int				check_init_enemy(t_all *s, int *n);
void			init_set_enemy_var(t_all *s, int i);

/*about init_variable*/
void			init_win_var(t_all *s);
void			init_map_var(t_all *s);
void			init_player_var(t_all *s);
void			init_key_var(t_all *s);
void			init_variable(t_all *s);

/*about tex*/
void			*tex_input_xpm(t_all *s, char *file);
void			tex_input(t_all *s);
void			tex_input_player(t_all *s);
void			tex_input_enemy(t_all *s);
void			tex_input_exit(t_all *s);

/*about supplement*/
int				supplement_set_map(t_all *s);
void			supplement_input_map(t_all *s);

/*about pos*/
void			pos_player(t_all *s);

/************about key directory************/
/*about key*/
int				key_pressed(int k, t_all *s);
int				key_released(int k, t_all *s);
int				key_update(t_all *s);

/*about key_act*/
void			key_act_up(t_all *s);
void			key_act_left(t_all *s);
void			key_act_down(t_all *s);
void			key_act_right(t_all *s);
void			key_act_enter(t_all *s);

/*about key_act_support*/
void			key_act_support_y(t_all *s, int op, int i, int j);
void			key_act_support_x(t_all *s, int op, int i, int j);

/*about key_quit*/
void			key_act_quit(t_all *s);
int				key_red_button(t_all *s);

/************about parse directory************/
/*about parse*/
int				parse_longest_line(t_all *s, char *map);
int				parse_support(t_all *s, int fd, int *ret);
int				parse_set_map(t_all *s);
int				parse_intput_map(t_all *s, char *line, int *j);
int				parse(t_all *s, char *map);

/*about parse_check_map*/
int				parse_check_size(t_all *s);
int				parse_check_border(t_all *s);
int				parse_check_element(t_all *s, char c);
int				parse_check_space(t_all *s);
int				parse_check_all(t_all *s);

/*about parse_check_map2*/
int				parse_check_mulitple(t_all *s, char c);
void			parse_check_multiple_all(t_all *s);

/*about parse_check_win*/
void			set_bfs1(t_all *s);
void			set_bfs2(t_all *s);
void			set_bfs_x_y(t_all *s);
int				parse_check_win(t_all *s);
void			parse_check_bfs(t_all *s);

/*about check_arguement*/
void			check_argument(t_all *s, char **argv);

/************about tool directory************/
/*about tool*/
int				tool_strlen(char *line);
int				tool_get_digit_count(long int n);
char			*tool_itoa(int n);
void			support_itoa(char *str, long int *long_n);

/*about random*/
int				tool_rand(t_all *s);
void			tool_srand(t_all *s, int seed);

/*about error*/

int				tool_error1(int err);
int				tool_error2(int err);
int				tool_error3(int err);
int				tool_error4(int err);
int				tool_error(int err);

#endif
