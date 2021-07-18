/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogeun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 15:43:04 by nogeun            #+#    #+#             */
/*   Updated: 2021/07/17 16:10:46 by nogeun           ###   ########.fr       */
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

typedef struct		s_all {
	t_mlx			mlx;
	t_win			win;
	t_err			err;
	t_map			map;
}					t_all;

void		longest_line(t_all *s, char *map);
int			set_map(t_all *s);
int			input_map(t_all *s, char *line, int *j);
int			parse(t_all *s, char *map);

int			tool_strlen(char *line);

#endif
