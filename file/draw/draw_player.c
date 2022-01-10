/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noguen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 18:53:12 by noguen            #+#    #+#             */
/*   Updated: 2021/12/29 18:53:57 by noguen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_player(t_all *s)
{
	int		pos_y;
	int		pos_x;

	pos_y = s->player.pos_y / 64;
	pos_x = s->player.pos_x / 64;
	if (s->player.pos_x % 64 >= 32)
	{
		for (int i = 0; i <= pos_y; i++) {
			draw_put_image_tile(s, i, pos_x);
			draw_put_image_tile(s, i, pos_x + 1);
		}
		draw_put_image(s, s->player.img, s->player.pos_y - 64, s->player.pos_x - 32);
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
		draw_put_image(s, s->player.img, s->player.pos_y - 64, s->player.pos_x - 32);
		for (int i = pos_y + 1; i < 10; i++) {
			draw_put_image_tile(s, i, pos_x);
			draw_put_image_tile(s, i, pos_x - 1);
		}
	}
}
