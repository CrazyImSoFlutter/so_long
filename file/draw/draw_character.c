/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_character.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noguen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 23:29:15 by noguen            #+#    #+#             */
/*   Updated: 2022/01/18 00:40:13 by noguen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	draw_player_tile(t_all *s)
{
	int	pos_y;
	int	pos_x;

	pos_y = s->player.pos_y / 64;
	pos_x = s->player.pos_x / 64;
	if (s->player.pos_x % 64 > 32)
	{
		draw_put_image_tile(s, pos_y, pos_x);
		draw_put_image_tile(s, pos_y, pos_x + 1);
		draw_tile_again(s, pos_y, pos_x, 1);
	}
	else
	{
		draw_put_image_tile(s, pos_y, pos_x);
		draw_put_image_tile(s, pos_y, pos_x - 1);
		draw_tile_again(s, pos_y, pos_x, -1);
	}
}

void	draw_character(t_all *s)
{
	draw_player_tile(s);
	draw_put_image(s, s->player.img,
		s->player.pos_y - 64, s->player.pos_x - 32);
}
