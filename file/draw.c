/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogeun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 01:11:15 by nogeun            #+#    #+#             */
/*   Updated: 2021/10/13 21:54:02 by nogeun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_put_image_tile(t_all *s, int y, int x)
{
	if (s->map.sup[y][x] == '1')
	{
		mlx_put_image_to_window(s->mlx.ptr, s->win.ptr, s->tex.sand, x * 40, y * 40);
		mlx_put_image_to_window(s->mlx.ptr, s->win.ptr, s->tex.wall, x * 40, (y - 1) * 40);
	}
	else if (s->map.sup[y][x] == '0')
	{
		mlx_put_image_to_window(s->mlx.ptr, s->win.ptr, s->tex.sand, x * 40, y * 40);
	}

	else {
		mlx_put_image_to_window(s->mlx.ptr, s->win.ptr, s->tex.sand, x * 40, y * 40);
	}
}

void	draw_put_image(t_all *s, void *img_ptr, int y, int x)
{
	mlx_put_image_to_window(s->mlx.ptr, s->win.ptr, img_ptr, x, y);
}

void	draw_tiles(t_all *s)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 18)
	{
		j = -1;
		while (++j < 30)
		{
			draw_put_image_tile(s, i, j);
		}
	}
	s->win.tile_flag = 0;
}

void	draw_player(t_all *s)
{
	int		pos_y;
	int		pos_x;

	pos_y = s->player.pos_y / 40;
	pos_x = s->player.pos_x / 40;
	if (s->player.pos_x % 40 >= 20)
	{
		for (int i = 0; i <= pos_y; i++) {
			draw_put_image_tile(s, i, pos_x);
			draw_put_image_tile(s, i, pos_x + 1);
		}
		draw_put_image(s, s->player.img, s->player.pos_y - 40, s->player.pos_x - 20);
		for (int i = pos_y + 1; i < 18; i++) {
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
		draw_put_image(s, s->player.img, s->player.pos_y - 40, s->player.pos_x - 20);
		for (int i = pos_y + 1; i < 18; i++) {
			draw_put_image_tile(s, i, pos_x);
			draw_put_image_tile(s, i, pos_x - 1);
		}
	}
}
