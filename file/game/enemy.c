/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noguen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:10:27 by noguen            #+#    #+#             */
/*   Updated: 2022/01/15 16:30:09 by noguen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    set_enemy(t_all *s)
{
    int i;
    int pos;
    int y;
    int x;

    i = 3;
    tool_srand(s, s->object_count);
    for (i = 0; i < 3; i++)
    {
        pos = tool_rand(s) % 200;
        printf("%d\n", pos);
        y = pos / 20;
        x = pos % 20;
        if ((s->player.pos_y / 64 == y && s->player.pos_x / 64 == x) ||
                s->map.sup[y][x] != '0')
        {
            i--;
            continue;
        }
        s->enemy[i].pos_y = y * 64 + 32;
        s->enemy[i].pos_x = x * 64 + 32;
        s->enemy[i].base_direction = tool_rand(s) % 2;
        s->enemy[i].direction = tool_rand(s) % 2;
        if (s->enemy[i].base_direction == 0)
        {
            if (s->enemy[i].direction == 0)
                s->enemy[i].direction = UP;
            else
                s->enemy[i].direction = DOWN;
        }
        s->enemy[i].move_speed = 3;
        s->enemy[i].frame = 0;
        s->enemy[i].img = s->tex.enemy_left[0];
    }
}

void    move_up_enemy(t_all *s, int n)
{
    int     i;
    int     j;
    int     precise_i;
    int     precise_j;

    i = (s->enemy[n].pos_y - 20 - E_MOVE_SPEED) / 64;
    j = s->enemy[n].pos_x / 64;
    s->enemy[n].frame = (s->enemy[n].frame + 1) % 32;
    if (s->map.sup[i][j] != '1')
        s->enemy[n].pos_y -= E_MOVE_SPEED;
    else
        s->enemy[n].direction = DOWN;
    precise_i = s->enemy[n].pos_y / 64;
    precise_j = s->enemy[n].pos_x / 64;
    if (s->enemy[n].pos_map_y != precise_i ||
            s->enemy[n].pos_map_x != precise_j)
    {
        s->enemy[n].pos_map_y = precise_i;
        s->enemy[n].pos_map_x = precise_j;
    }
    set_enemy_image(s, n);
}

void    move_down_enemy(t_all *s, int n)
{
    int     i;
    int     j;
    int     precise_i;
    int     precise_j;

    i = (s->enemy[n].pos_y + 20 + E_MOVE_SPEED) / 64;
    j = s->enemy[n].pos_x / 64;
    s->enemy[n].frame = (s->enemy[n].frame + 1) % 32;
    if (s->map.sup[i][j] != '1')
        s->enemy[n].pos_y += E_MOVE_SPEED;
    else
        s->enemy[n].direction = UP;
    precise_i = s->enemy[n].pos_y / 64;
    precise_j = s->enemy[n].pos_x / 64;
    if (s->enemy[n].pos_map_y != precise_i ||
            s->enemy[n].pos_map_x != precise_j)
    {
        s->enemy[n].pos_map_y = precise_i;
        s->enemy[n].pos_map_x = precise_j;
    }
    set_enemy_image(s, n);
}

void    move_left_enemy(t_all *s, int n)
{
    int     i;
    int     j;
    int     precise_i;
    int     precise_j;

    i = s->enemy[n].pos_y / 64;
    j = (s->enemy[n].pos_x - 20 - E_MOVE_SPEED) / 64;
    s->enemy[n].frame = (s->enemy[n].frame + 1) % 32;
    if (s->map.sup[i][j] != '1')
        s->enemy[n].pos_y += E_MOVE_SPEED;
    else
        s->enemy[n].direction = RIGHT;
    precise_i = s->enemy[n].pos_y / 64;
    precise_j = s->enemy[n].pos_x / 64;
    if (s->enemy[n].pos_map_y != precise_i ||
            s->enemy[n].pos_map_x != precise_j)
    {
        s->enemy[n].pos_map_y = precise_i;
        s->enemy[n].pos_map_x = precise_j;
    }
    set_enemy_image(s, n);
}

void    move_right_enemy(t_all *s, int n)
{
    int     i;
    int     j;
    int     precise_i;
    int     precise_j;

    i = s->enemy[n].pos_y / 64;
    j = (s->enemy[n].pos_x + 20 + E_MOVE_SPEED) / 64;
    s->enemy[n].frame = (s->enemy[n].frame + 1) % 32;
    if (s->map.sup[i][j] != '1')
        s->enemy[n].pos_y -= E_MOVE_SPEED;
    else
        s->enemy[n].direction = LEFT;
    precise_i = s->enemy[n].pos_y / 64;
    precise_j = s->enemy[n].pos_x / 64;
    if (s->enemy[n].pos_map_y != precise_i ||
            s->enemy[n].pos_map_x != precise_j)
    {
        s->enemy[n].pos_map_y = precise_i;
        s->enemy[n].pos_map_x = precise_j;
    }
    set_enemy_image(s, n);
}
