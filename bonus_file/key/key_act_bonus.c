/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_act_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noguen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 00:34:58 by noguen            #+#    #+#             */
/*   Updated: 2022/01/18 00:51:11 by noguen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_include/so_long_bonus.h"

void	key_act_up(t_all *s)
{
	int		i;
	int		j;

	i = (s->player.pos_y - 10 - P_MOVE_SPEED) / 64;
	j = s->player.pos_x / 64;
	if (s->key.w == 1 && s->key.a == 0 && s->key.d == 0 && s->key.s == 0)
		key_act_support_y(s, -1, i, j);
	else if (s->key.w == 1 && s->key.s == 0)
		if (s->map.sup[i][j] != '1')
			s->player.pos_y -= P_MOVE_SPEED;
}

void	key_act_left(t_all *s)
{
	int	i;
	int	j;

	i = s->player.pos_y / 64;
	j = (s->player.pos_x - 10 - P_MOVE_SPEED) / 64;
	if (s->key.a == 1 && s->key.d == 0)
	{
		s->player.direction = 0;
		key_act_support_x(s, -1, i, j);
	}
}

void	key_act_down(t_all *s)
{
	int		i;
	int		j;

	i = (s->player.pos_y + 10 + P_MOVE_SPEED) / 64;
	j = s->player.pos_x / 64;
	if (s->key.w == 0 && s->key.a == 0 && s->key.d == 0 && s->key.s == 1)
		key_act_support_y(s, 1, i, j);
	else if (s->key.w == 0 && s->key.s == 1)
	{
		if (s->map.sup[i][j] != '1')
			s->player.pos_y += P_MOVE_SPEED;
	}
}

void	key_act_right(t_all *s)
{
	int		i;
	int		j;

	i = s->player.pos_y / 64;
	j = (s->player.pos_x + 10 + P_MOVE_SPEED) / 64;
	if (s->key.d == 1)
	{
		s->player.direction = 1;
		key_act_support_x(s, 1, i, j);
	}
}

void	key_act_enter(t_all *s)
{
	if (s->win.intro_flag == 1 && s->key.n == 1)
	{
		if (s->win.frame >= 0 && s->win.frame < 250)
			s->win.frame = 250;
		else if (s->win.frame >= 250 && s->win.frame < 500)
			s->win.frame = 500;
		else if (s->win.frame >= 500 && s->win.frame < 750)
			s->win.frame = 750;
		else if (s->win.frame >= 750 && s->win.frame < 1000)
			s->win.frame = 1000;
		else if (s->win.frame >= 1000 && s->win.frame < 1250)
			s->win.frame = 1250;
		else if (s->win.frame >= 1250 && s->win.frame < 1500)
			s->win.frame = 1500;
		s->key.n = 0;
	}
}
