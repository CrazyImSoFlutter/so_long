/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noguen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 23:39:21 by noguen            #+#    #+#             */
/*   Updated: 2022/01/18 00:46:50 by noguen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_include/so_long_bonus.h"

void	find_exit(t_all *s)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 10)
	{
		j = -1;
		while (++j < 20)
		{
			if (s->map.sup[i][j] == 'E')
			{
				s->map.exit_y = i;
				s->map.exit_x = j;
				return ;
			}
		}
	}
}

void	win_exit(t_all *s)
{
	int	i;
	int	j;
	int	y[2];
	int	x[2];

	y[0] = (s->player.pos_y - 5) / 64;
	y[1] = (s->player.pos_y + 5) / 64;
	x[0] = (s->player.pos_x - 5) / 64;
	x[1] = (s->player.pos_x + 5) / 64;
	i = -1;
	while (++i < 2)
	{
		j = -1;
		while (++j < 2)
		{
			if (s->map.sup[y[i]][x[j]] == 'E' && s->map.exit_frame == 63)
			{
				s->player.win_flag = 1;
				s->win.frame = 0;
			}
		}
	}
}
