/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noguen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 23:40:44 by noguen            #+#    #+#             */
/*   Updated: 2022/01/18 00:46:40 by noguen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_include/so_long_bonus.h"

void	enemy_patrol(t_all *s, int i)
{
	if (s->enemy[i].base_direction == VERTICAL)
	{
		if (s->enemy[i].direction == UP)
			move_up_enemy(s, i);
		else if (s->enemy[i].direction == DOWN)
			move_down_enemy(s, i);
	}
	else if (s->enemy[i].base_direction == HORIZONTAL)
	{
		if (s->enemy[i].direction == LEFT)
			move_left_enemy(s, i);
		else if (s->enemy[i].direction == RIGHT)
			move_right_enemy(s, i);
	}
}

void	enemy_win(t_all *s)
{
	int	i;

	i = -1;
	while (++i < 3)
	{
		if (s->player.pos_y >= s->enemy[i].pos_y - 32
			&& s->player.pos_y <= s->enemy[i].pos_y
			&& s->player.pos_x >= s->enemy[i].pos_x - 32
			&& s->player.pos_x <= s->enemy[i].pos_x + 32)
		{
			s->player.win_flag = 2;
			s->win.frame = 0;
			break ;
		}
	}
}
