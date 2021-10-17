/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_jump.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogeun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 23:46:38 by nogeun            #+#    #+#             */
/*   Updated: 2021/10/17 14:49:49 by nogeun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	wall_jump(t_all *s)
{
	if (s->player.skill_flag == 1 && s->player.skill_direction == 1)
	{
		s->player.skill_frame++;
		if (s->player.skill_frame >= 0 && s->player.skill_frame < 4)
			s->player.img = s->tex.jump[0];
		else if (s->player.skill_frame >= 4 && s->player.skill_frame < 7)
			s->player.img = s->tex.jump[1];
		else if (s->player.skill_frame >= 7 && s->player.skill_frame < 10)
			s->player.img = s->tex.jump[2];
		else if (s->player.skill_frame >= 10 && s->player.skill_frame < 13)
			s->player.img = s->tex.jump[3];
		else if (s->player.skill_frame >= 13 && s->player.skill_frame < 16)
			s->player.img = s->tex.jump[4];
		else if (s->player.skill_frame >= 16 && s->player.skill_frame < 19)
			s->player.img = s->tex.jump[5];
		else if (s->player.skill_frame >= 19 && s->player.skill_frame < 22)
			s->player.img = s->tex.jump[6];
		else if (s->player.skill_frame >= 22 && s->player.skill_frame < 25)
			s->player.img = s->tex.jump[7];
		else if (s->player.skill_frame >= 25 && s->player.skill_frame < 28)
			s->player.img = s->tex.jump[8];
		else if (s->player.skill_frame >= 28 && s->player.skill_frame < 32)
			s->player.img = s->tex.jump[9];
		s->player.pos_x -= 4;
		if (s->player.skill_frame > 32)
		{
			s->player.skill_flag = 0;
			s->player.skill_direction = 0;
			s->player.skill_frame = 0;
			s->player.img = s->tex.jump[10];
		}
		s->key.a = 0;
	}
}
