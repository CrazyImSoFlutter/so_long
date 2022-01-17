/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noguen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 23:38:58 by noguen            #+#    #+#             */
/*   Updated: 2022/01/18 00:46:45 by noguen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_include/so_long_bonus.h"

void	move_up_enemy(t_all *s, int n)
{
	int		i;
	int		j;

	i = (s->enemy[n].pos_y - 10 - E_MOVE_SPEED) / 64;
	j = s->enemy[n].pos_x / 64;
	s->enemy[n].frame = (s->enemy[n].frame + 1) % 32;
	if (s->map.sup[i][j] != '1')
		s->enemy[n].pos_y -= E_MOVE_SPEED;
	else
		s->enemy[n].direction = DOWN;
	set_enemy_image(s, n);
}

void	move_down_enemy(t_all *s, int n)
{
	int		i;
	int		j;

	i = (s->enemy[n].pos_y + 10 + E_MOVE_SPEED) / 64;
	j = s->enemy[n].pos_x / 64;
	s->enemy[n].frame = (s->enemy[n].frame + 1) % 32;
	if (s->map.sup[i][j] != '1')
		s->enemy[n].pos_y += E_MOVE_SPEED;
	else
		s->enemy[n].direction = UP;
	set_enemy_image(s, n);
}

void	move_left_enemy(t_all *s, int n)
{
	int		i;
	int		j;

	i = s->enemy[n].pos_y / 64;
	j = (s->enemy[n].pos_x - 10 - E_MOVE_SPEED) / 64;
	s->enemy[n].frame = (s->enemy[n].frame + 1) % 32;
	if (s->map.sup[i][j] != '1')
		s->enemy[n].pos_x -= E_MOVE_SPEED;
	else
		s->enemy[n].direction = RIGHT;
	set_enemy_image(s, n);
}

void	move_right_enemy(t_all *s, int n)
{
	int		i;
	int		j;

	i = s->enemy[n].pos_y / 64;
	j = (s->enemy[n].pos_x + 10 + E_MOVE_SPEED) / 64;
	s->enemy[n].frame = (s->enemy[n].frame + 1) % 32;
	if (s->map.sup[i][j] != '1')
		s->enemy[n].pos_x += E_MOVE_SPEED;
	else
		s->enemy[n].direction = LEFT;
	set_enemy_image(s, n);
}
