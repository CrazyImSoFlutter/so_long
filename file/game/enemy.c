/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noguen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 23:38:58 by noguen            #+#    #+#             */
/*   Updated: 2022/01/15 23:56:01 by noguen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up_enemy(t_all *s, int n)
{
	int		i;
	int		j;
	int		precise_i;
	int		precise_j;

	i = (s->enemy[n].pos_y - 20 - E_MOVE_SPEED) / 64;
	j = s->enemy[n].pos_x / 64;
	s->enemy[n].frame = (s->enemy[n].frame + 1) % 32;
	if (s->map.sup[i][j] != '1')
		s->enemy[n].pos_y -= E_MOVE_SPEED;
	else
		s->enemy[n].direction = DOWN;
	precise_i = s->enemy[n].pos_y / 64;
	precise_j = s->enemy[n].pos_x / 64;
	if (s->enemy[n].pos_map_y != precise_i
		|| s->enemy[n].pos_map_x != precise_j)
	{
		s->enemy[n].pos_map_y = precise_i;
		s->enemy[n].pos_map_x = precise_j;
	}
	set_enemy_image(s, n);
}

void	move_down_enemy(t_all *s, int n)
{
	int		i;
	int		j;
	int		precise_i;
	int		precise_j;

	i = (s->enemy[n].pos_y + 20 + E_MOVE_SPEED) / 64;
	j = s->enemy[n].pos_x / 64;
	s->enemy[n].frame = (s->enemy[n].frame + 1) % 32;
	if (s->map.sup[i][j] != '1')
		s->enemy[n].pos_y += E_MOVE_SPEED;
	else
		s->enemy[n].direction = UP;
	precise_i = s->enemy[n].pos_y / 64;
	precise_j = s->enemy[n].pos_x / 64;
	if (s->enemy[n].pos_map_y != precise_i
		|| s->enemy[n].pos_map_x != precise_j)
	{
		s->enemy[n].pos_map_y = precise_i;
		s->enemy[n].pos_map_x = precise_j;
	}
	set_enemy_image(s, n);
}

void	move_left_enemy(t_all *s, int n)
{
	int		i;
	int		j;
	int		precise_i;
	int		precise_j;

	i = s->enemy[n].pos_y / 64;
	j = (s->enemy[n].pos_x - 20 - E_MOVE_SPEED) / 64;
	s->enemy[n].frame = (s->enemy[n].frame + 1) % 32;
	if (s->map.sup[i][j] != '1')
		s->enemy[n].pos_y += E_MOVE_SPEED;
	else
		s->enemy[n].direction = RIGHT;
	precise_i = s->enemy[n].pos_y / 64;
	precise_j = s->enemy[n].pos_x / 64;
	if (s->enemy[n].pos_map_y != precise_i
		|| s->enemy[n].pos_map_x != precise_j)
	{
		s->enemy[n].pos_map_y = precise_i;
		s->enemy[n].pos_map_x = precise_j;
	}
	set_enemy_image(s, n);
}

void	move_right_enemy(t_all *s, int n)
{
	int		i;
	int		j;
	int		precise_i;
	int		precise_j;

	i = s->enemy[n].pos_y / 64;
	j = (s->enemy[n].pos_x + 20 + E_MOVE_SPEED) / 64;
	s->enemy[n].frame = (s->enemy[n].frame + 1) % 32;
	if (s->map.sup[i][j] != '1')
		s->enemy[n].pos_y -= E_MOVE_SPEED;
	else
		s->enemy[n].direction = LEFT;
	precise_i = s->enemy[n].pos_y / 64;
	precise_j = s->enemy[n].pos_x / 64;
	if (s->enemy[n].pos_map_y != precise_i
		|| s->enemy[n].pos_map_x != precise_j)
	{
		s->enemy[n].pos_map_y = precise_i;
		s->enemy[n].pos_map_x = precise_j;
	}
	set_enemy_image(s, n);
}
