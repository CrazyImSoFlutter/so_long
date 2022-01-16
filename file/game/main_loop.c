/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noguen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 00:21:09 by noguen            #+#    #+#             */
/*   Updated: 2022/01/17 02:06:31 by noguen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main_loop(t_all *s)
{
	if (s->win.intro_flag)
	{
		intro(s);
		key_act_enter(s);
	}
	else
	{
		draw_point(s);
		if (s->win.tile_flag)
			draw_tiles(s);
		if (s->map.exit_flag)
			draw_exit(s);
		if (s->player.win_flag == 0)
			game_play(s);
		else if (s->player.win_flag == 1 || s->player.win_flag == 2)
			game_end(s);
		else if (s->player.win_flag == 3)
			key_act_quit(s);
	}
	return (0);
}

void	game_play(t_all *s)
{
	draw_character(s);
	enemy_patrol(s);
	key_update(s);
	object_get(s);
	enemy_win(s);
	win_exit(s);
}

void	game_end(t_all *s)
{
	if (s->win.frame != 200)
		draw_end(s);
	else
		draw_result(s);
	key_act_quit(s);
}
