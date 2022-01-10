/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noguen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 18:55:10 by noguen            #+#    #+#             */
/*   Updated: 2021/12/29 21:30:50 by noguen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_put_image(t_all *s, void *img_ptr, int y, int x)
{
	mlx_put_image_to_window(s->mlx.ptr, s->win.ptr, img_ptr, x, y);
}

void    draw_two(t_all *s, void *first, void *second, int y, int x)
{
    if (second != s->tex.wall)
    {
        draw_put_image(s, first, y * 64, x * 64);
        draw_put_image(s, second, y * 64, x * 64);
    }
    else
    {
        draw_put_image(s, first, y * 64, x * 64);
        draw_put_image(s, second, (y - 1) * 64, x * 64);
    }
}
