/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noguen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 23:45:55 by noguen            #+#    #+#             */
/*   Updated: 2022/01/10 22:38:02 by noguen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void object_count(t_all *s)
{
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 20; j++)
            if (s->map.sup[i][j] == 'C')
                s->object_count++;
}

void object_get(t_all *s)
{
    int y[2];
    int x[2];

    y[0] = (s->player.pos_y - 5) / 64;
    y[1] = (s->player.pos_y + 5) / 64;
    x[0] = (s->player.pos_x - 5) / 64;
    x[1] = (s->player.pos_x + 5) / 64;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if ( s->map.sup[y[i]][x[j]] == 'C') {
                s->map.sup[y[i]][x[j]] = '0';
                s->object_count--;
                if (s->object_count == 0)
                    s->map.exit_flag = 1;
            }
        }
    }
}
