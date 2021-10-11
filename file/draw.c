/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogeun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 01:11:15 by nogeun            #+#    #+#             */
/*   Updated: 2021/10/12 01:04:32 by nogeun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_put_image_tile(t_all *s, void *img_ptr, int y, int x)
{
	mlx_put_image_to_window(s->mlx.ptr, s->win.ptr, img_ptr, x * 40, y * 40);
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
			if (s->map.sup[i][j] == '0')
				draw_put_image_tile(s, s->tex.sand, i, j);
			else if (s->map.sup[i][j] == '1')
			{
				draw_put_image_tile(s, s->tex.sand, i, j);
				draw_put_image_tile(s, s->tex.wall, i - 1, j);
			}
			else
			{
				draw_put_image_tile(s, s->tex.sand, i, j);
			}
		}
	}
	if (s->win.frame >= 600)
		s->win.frame = -1;
	s->win.frame++;
}
