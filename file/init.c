/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogeun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 23:47:03 by nogeun            #+#    #+#             */
/*   Updated: 2021/10/12 13:47:50 by nogeun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_variables(t_all *s)
{
	s->map.x = 0;
	s->map.y = 0;
	s->map.map = NULL;
	s->map.sup = NULL;
	s->win.y = 720;
	s->win.x = 1280;
	s->win.intro_flag = 1;
	s->win.frame = 0;
	s->player.pos_y = 0;
	s->player.pos_x = 0;
	s->player.move_speed = 3;
}

void	init_screen(t_all *s, char **argv)
{
	s->mlx.ptr = mlx_init();
	if (parse(s, argv[1]) == -1)
		exit(0);
	supplement_input_map(s);
	pos_player(s);
	s->win.ptr = mlx_new_window(s->mlx.ptr, s->win.x, s->win.y, "so_long");
	s->img.ptr = mlx_new_image(s->mlx.ptr, s->win.x, s->win.y);
	tex_input(s);
}

int		main_loop(t_all *s)
{
	/*
	if (s->win.intro_flag)
		intro(s);
	else {
		draw_tiles(s);
		draw_player(s);
		key_update(s);
	}*/
	draw_player(s);
	key_update(s);
	return 0;
}

void	init_loop(t_all *s)
{
	mlx_hook(s->win.ptr, 2, 0, &key_pressed, s);
	mlx_hook(s->win.ptr, 3, 0, &key_released, s);
	mlx_loop_hook(s->mlx.ptr, &main_loop, s);
	mlx_loop(s->mlx.ptr);
}

void	init_so_long(t_all *s, char **argv)
{
	init_variables(s);
	init_screen(s, argv);
	draw_tiles(s);
	init_loop(s);
}
