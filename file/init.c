/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogeun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 23:47:03 by nogeun            #+#    #+#             */
/*   Updated: 2021/10/11 18:27:28 by nogeun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_variables(t_all *s)
{
	s->map.x = 0;
	s->map.y = 0;
	s->map.map = NULL;
	s->player.pos_y = 0;
	s->player.pos_x = 0;
}

void	init_screen(t_all *s, char **argv)
{
	int	i;
	int j;

	j = -1;
	i = -1;
	s->mlx.ptr = mlx_init();
	if (parse(s, argv[1]) == -1)
		exit(0);
	s->win.x = 1280;
	s->win.y = 720;
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
	s->img.ptr = mlx_new_image(s->mlx.ptr, s->win.x, s->win.y);
	tex_input(s);
}

int		main_loop(t_all *s)
{
	test_draw(s);
	return 0;
}

void	init_loop(t_all *s)
{
	mlx_loop_hook(s->mlx.ptr, &main_loop, s);
	mlx_loop(s->mlx.ptr);
}

void	init_so_long(t_all *s, char **argv)
{
	init_variables(s);
	init_screen(s, argv);
	init_loop(s);
}
