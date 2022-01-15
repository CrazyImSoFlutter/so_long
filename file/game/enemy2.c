/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noguen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 22:37:30 by noguen            #+#    #+#             */
/*   Updated: 2022/01/15 16:16:22 by noguen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    enemy_patrol(t_all *s)
{
    int i;

    i = -1;
    while (++i < 3)
    {
        if (s->enemy[i].base_direction == VERTICAL)
        {
            if (s->enemy[i].direction == UP)
                move_up_enemy(s, i);
            else if (s->enemy[i].direction == DOWN)
                move_down_enemy(s, i);
        }
        else if (s->enemy[i].base_direction == HORIZONTAL)
        {
            if (s->enemy[i].direction == LEFT)
                move_left_enemy(s, i);
            else if (s->enemy[i].direction == RIGHT)
                move_right_enemy(s, i);
        }
    }
}
