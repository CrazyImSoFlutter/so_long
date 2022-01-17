/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_variable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noguen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 00:15:40 by noguen            #+#    #+#             */
/*   Updated: 2022/01/18 00:41:39 by noguen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	init_win_var(t_all *s)
{
	s->win.y = 720;
	s->win.x = 1280;
	s->win.intro_flag = 1;
	s->win.tile_flag = 1;
	s->win.frame = 0;
}

void	init_map_var(t_all *s)
{
	s->map.x = 0;
	s->map.y = 0;
	s->map.map = NULL;
	s->map.sup = NULL;
	s->map.exit_flag = 0;
	s->object_count = 0;
}

void	init_player_var(t_all *s)
{
	s->player.pos_y = 0;
	s->player.pos_x = 0;
	s->player.move = 0;
	s->player.win_flag = 0;
	s->player.direction = 0;
}

void	init_key_var(t_all *s)
{
	s->key.w = 0;
	s->key.s = 0;
	s->key.a = 0;
	s->key.d = 0;
	s->key.n = 0;
	s->key.q = 0;
}

void	init_variable(t_all *s)
{
	init_win_var(s);
	init_map_var(s);
	init_player_var(s);
	init_key_var(s);
}
