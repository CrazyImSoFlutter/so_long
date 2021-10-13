/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_act.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogeun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 12:48:25 by nogeun            #+#    #+#             */
/*   Updated: 2021/10/13 22:00:34 by nogeun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_act_up(t_all *s)
{
	int		i;
	int		j;

	i = (s->player.pos_y - 5 - s->player.move_speed) / 40;
	j = s->player.pos_x / 40;
	if (s->key.w == 1)
	{
		if (s->map.sup[i][j] != '1')
			s->player.pos_y -= s->player.move_speed;
	}
}

void	key_act_left(t_all *s)
{
	int		i;
	int		j;

	i = s->player.pos_y / 40;
	j = (s->player.pos_x - 15 - s->player.move_speed) / 40;
	if (s->key.a == 1)
	{
		if (s->map.sup[i][j] != '1')
			s->player.pos_x -= s->player.move_speed;
		if (s->player.frame % 8 == 0)
			s->player.img = s->tex.player_left[0];
		else if (s->player.frame % 8 == 1)
			s->player.img = s->tex.player_left[1];
		else if (s->player.frame % 8 == 2)
			s->player.img = s->tex.player_left[2];
		else if (s->player.frame % 8 == 3)
			s->player.img = s->tex.player_left[3];
		else if (s->player.frame % 8 == 4)
			s->player.img = s->tex.player_left[4];
		else if (s->player.frame % 8 == 5)
			s->player.img = s->tex.player_left[5];
		else if (s->player.frame % 8 == 6)
			s->player.img = s->tex.player_left[6];
		else if (s->player.frame % 8 == 7)
			s->player.img = s->tex.player_left[7];
	}
}

void	key_act_down(t_all *s)
{
	int		i;
	int		j;

	i = (s->player.pos_y + 5 + s->player.move_speed) / 40;
	j = s->player.pos_x / 40;
	if (s->key.s == 1)
	{
		if (s->map.sup[i][j] != '1')
			s->player.pos_y += s->player.move_speed;
	}
}

void	key_act_right(t_all *s)
{
	int		i;
	int		j;

	i = s->player.pos_y / 40;
	j = (s->player.pos_x + 15 + s->player.move_speed) / 40;
	if (s->key.d == 1)
	{
		if (s->map.sup[i][j] != '1')
			s->player.pos_x += s->player.move_speed;
	}
}

void	key_act_enter(t_all *s)
{
	if (s->win.intro_flag == 1 && s->key.n == 1)
	{
		if (s->win.frame >= 0 && s->win.frame < 250)
			s->win.frame = 250;
		else
			s->win.frame = 500;
		s->key.n = 0;
	}
}
