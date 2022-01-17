/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_exit_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noguen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 22:19:18 by noguen            #+#    #+#             */
/*   Updated: 2022/01/18 00:46:19 by noguen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_include/so_long_bonus.h"

void	draw_exit(t_all *s)
{
	s->map.exit_frame++;
	if (s->map.exit_frame == 64)
	{
		s->map.exit_flag = 0;
		s->map.exit_frame--;
		return ;
	}
	draw_put_image(s, s->tex.exit[s->map.exit_frame / 8],
		s->map.exit_y * 64, s->map.exit_x * 64);
}
