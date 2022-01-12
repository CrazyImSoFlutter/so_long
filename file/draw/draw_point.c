/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noguen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 23:25:52 by noguen            #+#    #+#             */
/*   Updated: 2022/01/12 21:03:45 by noguen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    draw_point(t_all *s)
{
    char *a;
    char *b;

    a = tool_itoa(s->player.move);
    b = "player move: ";
    draw_put_image(s, s->tex.black, 640, 0);
    draw_put_image(s, s->tex.black, 640, 64);
    draw_put_image(s, s->tex.black, 640, 128);
    mlx_string_put(s->mlx.ptr, s->win.ptr, 20, 700, 0xFFFFFF, b);
    mlx_string_put(s->mlx.ptr, s->win.ptr, 110, 700, 0xFFFFFF, a);
}
