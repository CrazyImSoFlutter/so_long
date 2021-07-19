/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogeun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 15:43:04 by nogeun            #+#    #+#             */
/*   Updated: 2021/07/19 11:23:43 by nogeun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include "mlx/mlx.h"
# include "gnl/get_next_line.h"

typedef struct		s_mlx {
	void			*ptr;
}					t_mlx;

typedef struct		s_win {
	void			*ptr;
	int				x;
	int				y;
	int				**buf;
}					t_win;

typedef struct		s_err {
	int				n;
	int				p;
}					t_err;

typedef struct		s_map {
	char			**map;
	int				x;
	int				y;
}					t_map;

typedef struct		s_img {
	void			*ptr;
	int				*data;

	int				width;
	int				height;
	int				size_l;
	int				bpp;
	int				endian;
}					t_img;

typedef struct		s_tex {
	int				*player[4];
	int				*tile;
	int				*wall;
	int				*enemy;
}					t_tex;

typedef struct		s_all {
	t_mlx			mlx;
	t_win			win;
	t_err			err;
	t_map			map;
	t_img			img;
	t_tex			tex;
}					t_all;

void		longest_line(t_all *s, char *map);
int			set_map(t_all *s);
int			input_map(t_all *s, char *line, int *j);
int			parse(t_all *s, char *map);

int			tool_strlen(char *line);

void		input_xpm(t_all *s, int **adr, char *file, int *flag);
int			input_texture(t_all *s);
#endif
