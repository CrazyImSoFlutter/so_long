/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noguen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:06:30 by noguen            #+#    #+#             */
/*   Updated: 2022/01/12 21:14:12 by noguen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    find_exit(t_all *s)
{
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 20; j++)
            if (s->map.sup[i][j] == 'E')
            {
                s->map.exit_y = i;
                s->map.exit_x = j;
                return ;
            }
}

void    win_exit(t_all *s)
{
    int y[2];
    int x[2];

    y[0] = (s->player.pos_y - 5) / 64;
    y[1] = (s->player.pos_y + 5) / 64;
    x[0] = (s->player.pos_x - 5) / 64;
    x[1] = (s->player.pos_x + 5) / 64;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if ( s->map.sup[y[i]][x[j]] == 'E' && s->map.exit_frame == 63) {
                s->player.win_flag = 1;
                s->win.frame = 0;
            }
        }
    }
}
