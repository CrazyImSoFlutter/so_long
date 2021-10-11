/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogeun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 23:24:35 by nogeun            #+#    #+#             */
/*   Updated: 2021/10/12 00:47:14 by nogeun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
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

typedef struct		s_mlx {
	void			*ptr;
}					t_mlx;

typedef struct		s_win {
	void			*ptr;
	int				x;
	int				y;
	int				frame;
	int				intro_flag;
}					t_win;

typedef struct		s_img {
	void			*ptr;
	int				*data;

	int				width;
	int				height;
	int				size_l;
	int				bpp;
	int				endian;
}					t_img;

typedef struct		s_map {
	char			**map;
	char			**sup;
	int				x;
	int				y;
	int				mapx;
	int				mapy;
	int				spr;
}					t_map;

typedef struct		s_tex {
	int				*intro[4];
	int				*player_left[4];
	int				*player_right[4];
	int				*enemy_left[4];
	int				*enemy_right[4];
	int				*sand;
	int				*wall;
}					t_tex;

typedef struct		s_player {
	int				pos_y;
	int				pos_x;
	int				move_speed;
}					t_player;

typedef struct		s_key {
	int				w;
	int				a;
	int				s;
	int				d;
}					t_key;

typedef struct		s_err {
	int				n;
	int				p;
}					t_err;

typedef struct		s_all {
	t_mlx			mlx;
	t_win			win;
	t_img			img;
	t_map			map;
	t_tex			tex;
	t_player		player;
	t_key			key;
	t_err			err;
}					t_all;

/*about init*/
void			init_variables(t_all *s);
void			init_screen(t_all *s, char **argv);
void			init_loop(t_all *s);
void			init_so_long(t_all *s, char** argv);

/*about tex*/
void			*tex_input_xpm(t_all *s, char *file);
void			tex_input(t_all *s);

/*about parse*/
void			parse_longest_line(t_all *s, char *map);
int				parse_set_map(t_all *s);
int				parse_intput_map(t_all *s, char *line, int *j);
int				parse(t_all *s, char *map);

/*about tool*/
int				tool_strlen(char* line);

/*about draw*/
void			draw_put_image_tile(t_all *s, void *img_ptr, int x, int y);
void			draw_put_image(t_all *s, void *img_ptr, int x, int y);
void			draw_tiles(t_all *s);

/*about intro*/
void			intro(t_all *s);

/*about supplement*/
int				supplement_set_map(t_all *s);
void			supplement_input_map(t_all *s);

/*about key*/
int				key_pressed(int k, t_all *s);
int				key_released(int k, t_all *s);
int				key_update(t_all *s);
#endif
