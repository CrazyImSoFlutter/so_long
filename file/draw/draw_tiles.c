/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tiles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogeun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 01:11:15 by nogeun            #+#    #+#             */
/*   Updated: 2022/01/15 14:48:50 by noguen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_put_image_tile(t_all *s, int y, int x)
{
	if (s->map.sup[y][x] == '1')
        draw_two(s, s->tex.sand, s->tex.wall, y, x);
	else if (s->map.sup[y][x] == '0')
		draw_put_image(s, s->tex.sand, y * 64, x * 64);
    else if (s->map.sup[y][x] == 'C')
        draw_two(s, s->tex.sand, s->tex.object, y, x);
    else if (s->map.sup[y][x] == 'E')
        draw_two(s, s->tex.sand, s->tex.exit[s->map.exit_frame / 8], y, x);
	else
        draw_put_image(s, s->tex.sand, y * 64, x * 64);
}

void	draw_tiles(t_all *s)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 10)
	{
		j = -1;
		while (++j < 20)
			draw_put_image_tile(s, i, j);
	}
	s->win.tile_flag = 0;
}

void    draw_wall(t_all *s)
{
    int i;
    int j;

    i = 0;
    while (++i < 9)
    {
        j = 0;
        while (++j <19)
        	if (s->map.sup[y][x] == '1')
                draw_two(s, s->tex.sand, s->tex.wall, y, x);
    }
}
