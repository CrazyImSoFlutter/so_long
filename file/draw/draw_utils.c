/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noguen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 23:14:59 by noguen            #+#    #+#             */
/*   Updated: 2022/01/18 00:40:35 by noguen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	draw_put_image(t_all *s, void *img_ptr, int y, int x)
{
	mlx_put_image_to_window(s->mlx.ptr, s->win.ptr, img_ptr, x, y);
}

void	draw_tile_again(t_all *s, int pos_y, int pos_x, int dir)
{
	if (pos_y + 1 < 20)
	{
		draw_put_image_tile(s, pos_y + 1, pos_x);
		draw_put_image_tile(s, pos_y + 1, pos_x + dir);
	}
	if (pos_y - 1 >= 0)
	{
		draw_put_image_tile(s, pos_y - 1, pos_x);
		draw_put_image_tile(s, pos_y - 1, pos_x + dir);
	}
	if (pos_y - 2 >= 0)
	{
		draw_put_image_tile(s, pos_y - 2, pos_x);
		draw_put_image_tile(s, pos_y - 2, pos_x + dir);
	}
}
