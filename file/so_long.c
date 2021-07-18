/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogeun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 15:50:04 by nogeun            #+#    #+#             */
/*   Updated: 2021/07/18 15:18:39 by nogeun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_variable(t_all *s)
{
	s->map.x = 0;
	s->map.y = 0;
	s->map.map = NULL;
	s->win.x = 1280;
	s->win.y = 720;
	s->err.n = 0;
}

void	init_screen(t_all *s, char **argv)
{
	int		i;
	int		j;
	
	i = -1;
	s->mlx.ptr = mlx_init();
	if (parse(s, argv[1]) == -1)
		exit(0);
	s->win.buf = malloc(sizeof(int *) * s->win.y);
	while (++i < s->win.y)
		s->win.buf[i] = malloc(sizeof(int) * s->win.x);
	i = -1;
	while (++i < s->win.y)
	{
		j = -1;
		while (++j < s->win.x)
			s->win.buf[i][j] = 0;
	}
	s->win.ptr = mlx_new_window(s->mlx.ptr, s->win.x, s->win.y, "so_long");
}

void	init_loop(t_all *s)
{
	mlx_loop(s->mlx.ptr);
}

void	init_so_long(t_all *s, char **argv)
{
	init_variable(s);
	init_screen(s, argv);
	init_loop(s);
}

int		main (int argc, char **argv)
{
	t_all	s;
	int i;

	i = argc;

	init_so_long(&s, argv);
	
	for (int i = 0; i < s.map.y; i++)
	{
		for (int j = 0; j < s.map.x; j++)
		{
			printf("%c", s.map.map[i][j]);
		}
		printf("\n");
	}
}
