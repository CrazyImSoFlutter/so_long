/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noguen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 00:11:36 by noguen            #+#    #+#             */
/*   Updated: 2022/01/16 00:28:54 by noguen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_screen(t_all *s, char **argv)
{
	int	i;

	s->mlx.ptr = mlx_init();
	i = parse(s, argv[1]);
	if (i == -1)
		exit(0);
	supplement_input_map(s);
	pos_player(s);
	tex_input(s);
	object_count(s);
	find_exit(s);
	init_enemy(s);
	s->player.img = s->tex.player_left[0];
	s->win.ptr = mlx_new_window(s->mlx.ptr, s->win.x, s->win.y, "so_long");
	s->img.ptr = mlx_new_image(s->mlx.ptr, s->win.x, s->win.y);
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
	init_variable(s);
	init_screen(s, argv);
	init_loop(s);
}
