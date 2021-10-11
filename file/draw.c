/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogeun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 01:11:15 by nogeun            #+#    #+#             */
/*   Updated: 2021/10/10 21:12:52 by nogeun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_put_image(t_all *s, void *img_ptr, int x, int y)
{
	mlx_put_image_to_window(s->mlx.ptr, s->win.ptr, img_ptr, y * 40, x * 40);
}

void	draw(t_all *s)
{
	int	i;
	int	j;

	i = -1;
	while (++i < s->map.y)
	{
		j = -1;
		while (++j < s->map.x)
		{
			if (s->map.map[i][j] == '0')
				draw_put_image(s, s->tex.sand, i, j);
			else
			{
				draw_put_image(s, s->tex.sand, i, j);
				draw_put_image(s, s->tex.wall, i - 1, j);
			}
		}
	}
}
