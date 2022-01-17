/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_end_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noguen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 21:04:13 by noguen            #+#    #+#             */
/*   Updated: 2022/01/18 00:46:08 by noguen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_include/so_long_bonus.h"

void	draw_end(t_all *s)
{
	int	i;
	int	j;

	i = s->win.frame;
	j = i / 20;
	i %= 20;
	draw_put_image(s, s->tex.black, j * 64, i * 64);
	s->win.frame++;
}

void	draw_result(t_all *s)
{
	if (s->player.win_flag == 1)
	{
		draw_put_image(s, s->tex.win, 120, 280);
		s->player.win_flag = 3;
	}
	else if (s->player.win_flag == 2)
	{
		draw_put_image(s, s->tex.lose, 120, 280);
		s->player.win_flag = 3;
	}
}
