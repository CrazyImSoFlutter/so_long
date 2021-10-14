/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_jump.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogeun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 23:46:38 by nogeun            #+#    #+#             */
/*   Updated: 2021/10/15 00:20:39 by nogeun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	wall_jump(t_all *s)
{
	if (s->player.skill_flag == 1 && s->player.skill_direction == 1)
	{
		s->player.skill_frame++;
		s->player.pos_x -= 4;
		if (s->player.skill_frame >= 32)
		{
			s->player.skill_flag = 0;
			s->player.skill_direction = 0;
			s->player.skill_frame = 0;
		}
		s->key.a = 0;
	}
}
