/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noguen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 23:14:59 by noguen            #+#    #+#             */
/*   Updated: 2022/01/17 18:18:28 by noguen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	draw_check(t_all *s, int *a, int *visit, int i)
{
	if (a[i] == s->player.pos_y && visit[3] == 0)
	{
		draw_put_image(s, s->player.img,
			s->player.pos_y - 64, s->player.pos_x - 32);
		visit[3] = 1;
	}
	else if (a[i] == s->enemy[0].pos_y && visit[0] == 0)
	{
		draw_put_image(s, s->enemy[0].img,
			s->enemy[0].pos_y - 64, s->enemy[0].pos_x - 32);
		visit[0] = 1;
	}
	else if (a[i] == s->enemy[1].pos_y && visit[1] == 0)
	{
		draw_put_image(s, s->enemy[1].img,
			s->enemy[1].pos_y - 64, s->enemy[1].pos_x - 32);
		visit[1] = 1;
	}
	else if (a[i] == s->enemy[2].pos_y && visit[2] == 0)
	{
		draw_put_image(s, s->enemy[2].img,
			s->enemy[2].pos_y - 64, s->enemy[2].pos_x - 32);
		visit[2] = 1;
	}
}
