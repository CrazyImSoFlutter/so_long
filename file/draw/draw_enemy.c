/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noguen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:21:14 by noguen            #+#    #+#             */
/*   Updated: 2022/01/14 22:55:42 by noguen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_enemy(t_all *s, int n)
{
	int		pos_y;
	int		pos_x;

	pos_y = s->enemy[n].pos_y / 64;
	pos_x = s->enemy[n].pos_x / 64;
	if (s->enemy[n].pos_x % 64 >= 32)
	{
		for (int i = 0; i <= pos_y; i++) {
			draw_put_image_tile(s, i, pos_x);
			draw_put_image_tile(s, i, pos_x + 1);
		}
		draw_put_image(s, s->enemy[n].img, s->enemy[n].pos_y - 64, s->enemy[n].pos_x - 32);
		for (int i = pos_y + 1; i < 10; i++) {
			draw_put_image_tile(s, i, pos_x);
			draw_put_image_tile(s, i, pos_x + 1);
		}
	}
	else
	{
		for (int i = 0; i <= pos_y; i++) {
			draw_put_image_tile(s, i, pos_x);
			draw_put_image_tile(s, i, pos_x - 1);
		}
		draw_put_image(s, s->enemy[n].img, s->enemy[n].pos_y - 64, s->enemy[n].pos_x - 32);
		for (int i = pos_y + 1; i < 10; i++) {
			draw_put_image_tile(s, i, pos_x);
			draw_put_image_tile(s, i, pos_x - 1);
		}
	}
}
