/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noguen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 23:51:45 by noguen            #+#    #+#             */
/*   Updated: 2022/01/17 20:54:32 by noguen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_enemy(t_all *s)
{
	int	i;

	s->init_max = 0;
	i = -1;
	tool_srand(s, s->object_count);
	while (++i < 3)
		init_set_enemy(s, &i);
}

void	init_set_enemy(t_all *s, int *n)
{
	int	y;
	int	x;
	int	pos;
	int	i;

	if (++(s->init_max) == 100)
		tool_error(-30);
	i = *n;
	pos = tool_rand(s) % 200;
	y = pos / 20;
	x = pos % 20;
	if ((s->player.pos_y / 64 == y && s->player.pos_x / 64 == x)
		|| s->map.sup[y][x] != '0')
	{
		(*n)--;
		return ;
	}
	s->enemy[i].pos_y = y * 64 + 32;
	s->enemy[i].pos_x = x * 64 + 32;
	if (check_init_enemy(s, n) == 0)
		return ;

	init_set_enemy_var(s, i);
}

int	check_init_enemy(t_all *s, int *n)
{
	int	i;

	i = *n;
	while (--i >= 0)
	{
		if (s->enemy[*n].pos_y == s->enemy[i].pos_y
			&& s->enemy[*n].pos_x == s->enemy[i].pos_x)
		{
			(*n)--;
			return (0);
		}
	}
	return (1);
}

void	init_set_enemy_var(t_all *s, int i)
{
	s->enemy[i].base_direction = tool_rand(s) % 2;
	s->enemy[i].direction = tool_rand(s) % 2;
	if (s->enemy[i].base_direction == VERTICAL)
	{
		if (s->enemy[i].direction == LEFT)
			s->enemy[i].direction = UP;
		else
			s->enemy[i].direction = DOWN;
	}
	s->enemy[i].move_speed = 3;
	s->enemy[i].frame = 0;
	s->enemy[i].img = s->tex.enemy_left[0];
}
