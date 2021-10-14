/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_skill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogeun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 23:12:00 by nogeun            #+#    #+#             */
/*   Updated: 2021/10/15 00:20:34 by nogeun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_act_wall_jump_left(t_all *s)
{
	int		i;
	int		j;

	i = s->player.pos_y / 64;
	j = (s->player.pos_x - 32) / 64;
	if (s->key.space == 1 && s->key.a == 1)
	{
		if (s->map.sup[i][j] == '1' && s->map.sup[i][j - 1] != '1')
		{
			s->player.skill_flag = 1;
			s->player.skill_direction = 1;
			s->key.space = 0;
			s->key.a = 0;
		}
	}
}
