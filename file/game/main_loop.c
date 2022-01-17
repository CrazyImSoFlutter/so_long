/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noguen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 00:21:09 by noguen            #+#    #+#             */
/*   Updated: 2022/01/18 01:19:30 by noguen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	main_loop(t_all *s)
{
	if (s->win.intro_flag)
	{
		intro(s);
		key_act_enter(s);
	}
	else
	{
		if (s->win.tile_flag)
			draw_tiles(s);
		if (s->player.win_flag == 0)
			game_play(s);
		else if (s->player.win_flag == 1)
			game_end(s);
		else if (s->player.win_flag == 3)
			key_act_quit(s);
	}
	return (0);
}

void	game_play(t_all *s)
{
	draw_character(s);
	key_update(s);
	object_get(s);
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
