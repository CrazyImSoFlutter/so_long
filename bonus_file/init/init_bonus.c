/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noguen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 00:11:36 by noguen            #+#    #+#             */
/*   Updated: 2022/01/18 00:47:33 by noguen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_include/so_long_bonus.h"

void	init_parse(t_all *s, char **argv)
{
	s->err.n = parse(s, argv[1]);
	s->err.n = parse_check_all(s);
	supplement_input_map(s);
	s->err.n = parse_check_win(s);
}

void	init_element(t_all *s)
{
	pos_player(s);
	tex_input(s);
	object_count(s);
	find_exit(s);
	init_enemy(s);
	s->player.img = s->tex.player_left[0];
}

void	init_screen(t_all *s)
{
	s->mlx.ptr = mlx_init();
	s->win.ptr = mlx_new_window(s->mlx.ptr, s->win.x, s->win.y, "so_long");
	s->img.ptr = mlx_new_image(s->mlx.ptr, s->win.x, s->win.y);
}

void	init_loop(t_all *s)
{
	mlx_hook(s->win.ptr, 2, 0, &key_pressed, s);
	mlx_hook(s->win.ptr, 3, 0, &key_released, s);
	mlx_hook(s->win.ptr, 17, 0, &key_red_button, s);
	mlx_loop_hook(s->mlx.ptr, &main_loop, s);
	mlx_loop(s->mlx.ptr);
}

void	init_so_long(t_all *s, char **argv)
{
	init_variable(s);
	init_screen(s);
	init_parse(s, argv);
	init_element(s);
	init_loop(s);
}
