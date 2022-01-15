/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_character.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noguen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 18:53:12 by noguen            #+#    #+#             */
/*   Updated: 2022/01/15 16:14:51 by noguen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_player_tile(t_all *s)
{
	int		pos_y;
	int		pos_x;

    pos_y = s->player.pos_y / 64;
    pos_x = s->player.pos_x / 64;
    if (s->player.pos_x % 64 >= 32)
    {
        draw_put_image_tile(s, pos_y, pos_x);
        draw_put_image_tile(s, pos_y, pos_x + 1);
        if (pos_y - 1 >= 0)
        {
            draw_put_image_tile(s, pos_y - 1, pos_x);
            draw_put_image_tile(s, pos_y - 1, pos_x + 1);
        }
    } 
    else
    {
        draw_put_image_tile(s, pos_y, pos_x);
        draw_put_image_tile(s, pos_y, pos_x - 1);
        if (pos_y - 1 >= 0)
        {
            draw_put_image_tile(s, pos_y - 1, pos_x);
            draw_put_image_tile(s, pos_y - 1, pos_x - 1);
        }
    }
}

void	draw_enemy_tile(t_all *s)
{
	int		pos_y;
	int		pos_x;
    int     i;

    i = -1;
    while (i++ < 3)
    {
        pos_y = s->enemy[i].pos_y / 64;
        pos_x = s->enemy[i].pos_x / 64;
        if (s->enemy[i].pos_x % 64 >= 32)
        {
            draw_put_image_tile(s, pos_y, pos_x);
            draw_put_image_tile(s, pos_y, pos_x + 1);
            if (pos_y - 1 >= 0)
            {
                draw_put_image_tile(s, pos_y - 1, pos_x);
                draw_put_image_tile(s, pos_y - 1, pos_x + 1);
            }
        }
        else
        {
            draw_put_image_tile(s, pos_y, pos_x);
            draw_put_image_tile(s, pos_y, pos_x + 1);
            if (pos_y - 1 >= 0)
            {
                draw_put_image_tile(s, pos_y - 1, pos_x);
                draw_put_image_tile(s, pos_y - 1, pos_x - 1);
            }
        }
    }
}

void    set_order(t_all *s, int *tmp)
{
    int t;
    int i;
    int j;

    tmp[0] = s->player.pos_y;
    tmp[1] = s->enemy[0].pos_y;
    tmp[2] = s->enemy[1].pos_y;
    tmp[3] = s->enemy[2].pos_y;
    i = -1;
    while (++i < 4)
    {
        j = -1;
        while (++j < 4)
        {
            if (tmp[i] < tmp[j])
            {
                t = tmp[i];
                tmp[i] = tmp[j];
                tmp[j] = t;
            }
        }
    }       
}

void    draw_player_enemy(t_all *s)
{
    int i;
    int a[4];
    int visit[4];

    i = -1;
    while (++i < 4)
        visit[i] = 0;
    set_order(s, a);
    i = -1;
    while (++i < 4)
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
}

void    draw_character(t_all *s)
{
    draw_player_tile(s);
    draw_enemy_tile(s);
    draw_player_enemy(s);
}
