/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noguen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 19:08:25 by noguen            #+#    #+#             */
/*   Updated: 2022/01/14 22:58:10 by noguen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    set_player_image(t_all *s)
{
    int **tex;

    if (s->player.direction == 0)
        tex = s->tex.player_left;
    else
        tex = s->tex.player_right;
    if (s->player.frame % 32 >= 0 && s->player.frame < 4)
		s->player.img = tex[0];
	else if (s->player.frame % 32 >= 4 && s->player.frame < 8)
		s->player.img = tex[1];
	else if (s->player.frame % 32 >= 8 && s->player.frame < 12)
		s->player.img = tex[2];
	else if (s->player.frame % 32 >= 12 && s->player.frame < 16)
		s->player.img = tex[3];
	else if (s->player.frame % 32 >= 16 && s->player.frame < 20)
		s->player.img = tex[4];
	else if (s->player.frame % 32 >= 20 && s->player.frame < 24)
		s->player.img = tex[5];
	else if (s->player.frame % 32 >= 24 && s->player.frame < 28)
		s->player.img = tex[6];
	else if (s->player.frame % 32 >= 28 && s->player.frame < 32)
		s->player.img = tex[7];
}

void    set_enemy_image(t_all *s, int n)
{
    int **tex;

    if (s->enemy[n].direction == 0)
        tex = s->tex.enemy_left;
    else
        tex = s->tex.enemy_right;
    if (s->enemy[n].frame % 32 >= 0 && s->enemy[n].frame < 4)
		s->enemy[n].img = tex[0];
	else if (s->enemy[n].frame % 32 >= 4 && s->enemy[n].frame < 8)
		s->enemy[n].img = tex[1];
	else if (s->enemy[n].frame % 32 >= 8 && s->enemy[n].frame < 12)
		s->enemy[n].img = tex[2];
	else if (s->enemy[n].frame % 32 >= 12 && s->enemy[n].frame < 16)
		s->enemy[n].img = tex[3];
	else if (s->enemy[n].frame % 32 >= 16 && s->enemy[n].frame < 20)
		s->enemy[n].img = tex[4];
	else if (s->enemy[n].frame % 32 >= 20 && s->enemy[n].frame < 24)
		s->enemy[n].img = tex[5];
	else if (s->enemy[n].frame % 32 >= 24 && s->enemy[n].frame < 28)
		s->enemy[n].img = tex[6];
	else if (s->player.frame % 32 >= 28 && s->enemy[n].frame < 32)
		s->enemy[n].img = tex[7];
}

