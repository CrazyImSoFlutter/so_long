/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noguen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 23:40:21 by noguen            #+#    #+#             */
/*   Updated: 2022/01/15 23:46:50 by noguen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	object_count(t_all *s)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 10)
	{
		j = -1;
		while (++j < 20)
			if (s->map.sup[i][j] == 'C')
				s->object_count++;
	}
}

void	object_get(t_all *s)
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
			if (s->map.sup[y[i]][x[j]] == 'C')
			{
				s->map.sup[y[i]][x[j]] = '0';
				s->object_count--;
				if (s->object_count == 0)
					s->map.exit_flag = 1;
			}
		}
	}
}
