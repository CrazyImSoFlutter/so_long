/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noguen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 22:37:30 by noguen            #+#    #+#             */
/*   Updated: 2022/01/14 23:02:45 by noguen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    enemy_patrol(t_all *s)
{
    int i;

    i = 3;
    while (i--)
    {
        if (s->enemy[i - 1].base_direction == VERTICAL)
        {
            if (s->enemy[i - 1].direction == UP)
                move_up_enemy(s, i - 1);
            else if (s->enemy[i - 1].direction == DOWN)
                move_down_enemy(s, i - 1);
        }
        else if (s->enemy[i - 1].base_direction == HORIZONTAL)
        {
            if (s->enemy[i - 1].direction == LEFT)
                move_left_enemy(s, i - 1);
            else if (s->enemy[i - 1].direction == RIGHT)
                move_right_enemy(s, i - 1);
        }
    }
}
