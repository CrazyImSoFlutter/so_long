/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_act.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogeun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 12:48:25 by nogeun            #+#    #+#             */
/*   Updated: 2021/12/20 17:57:28 by noguen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_act_up(t_all *s)
{
	int		i;
	int		j;
    int     precise_i;
    int     precise_j;
    int     **tex;

	i = (s->player.pos_y - 20 - s->player.move_speed) / 64;
	j = s->player.pos_x / 64;

    if (s->player.direction == 0)
        tex = s->tex.player_left;
    else
        tex = s->tex.player_right;
	if (s->key.w == 1 && s->key.a == 0 && s->key.d == 0 && s->key.s == 0)
	{
		s->player.frame++;
		if (s->player.frame >= 32)
			s->player.frame = 0;
		if (s->map.sup[i][j] != '1')
			s->player.pos_y -= s->player.move_speed;

        precise_i = s->player.pos_y / 64;
        precise_j = s->player.pos_x / 64;
        if (s->player.pos_map_y != precise_i || 
                s->player.pos_map_x != precise_j) {
            s->player.move++;
            printf("player_move: %d\n", s->player.move);
            s->player.pos_map_y = precise_i;
            s->player.pos_map_x = precise_j;
        }

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
	} else if (s->key.w == 1 && s->key.s == 0) {
		if (s->map.sup[i][j] != '1')
			s->player.pos_y -= s->player.move_speed;
    }
}

void	key_act_left(t_all *s)
{
	int		i;
	int		j;
    int     precise_i;
    int     precise_j;

	i = s->player.pos_y / 64;
	j = (s->player.pos_x - 20 - s->player.move_speed) / 64;
	if (s->key.a == 1 && s->key.d == 0)
	{
        s->player.direction = 0;
		s->player.frame++;
		if (s->player.frame >= 32)
			s->player.frame = 0;
		if (s->map.sup[i][j] != '1')
			s->player.pos_x -= s->player.move_speed;

        precise_i = s->player.pos_y / 64;
        precise_j = s->player.pos_x / 64;
        if (s->player.pos_map_y != precise_i || 
                s->player.pos_map_x != precise_j) {
            s->player.move++;
            printf("player_move: %d\n", s->player.move);
            s->player.pos_map_y = precise_i;
            s->player.pos_map_x = precise_j;
        }

		if (s->player.frame % 32 >= 0 && s->player.frame < 4)
			s->player.img = s->tex.player_left[0];
		else if (s->player.frame % 32 >= 4 && s->player.frame < 8)
			s->player.img = s->tex.player_left[1];
		else if (s->player.frame % 32 >= 8 && s->player.frame < 12)
			s->player.img = s->tex.player_left[2];
		else if (s->player.frame % 32 >= 12 && s->player.frame < 16)
			s->player.img = s->tex.player_left[3];
		else if (s->player.frame % 32 >= 16 && s->player.frame < 20)
			s->player.img = s->tex.player_left[4];
		else if (s->player.frame % 32 >= 20 && s->player.frame < 24)
			s->player.img = s->tex.player_left[5];
		else if (s->player.frame % 32 >= 24 && s->player.frame < 28)
			s->player.img = s->tex.player_left[6];
		else if (s->player.frame % 32 >= 28 && s->player.frame < 32)
			s->player.img = s->tex.player_left[7];
	}
}

void	key_act_down(t_all *s)
{
	int		i;
	int		j;
    int     precise_i;
    int     precise_j;
    int     **tex;

	i = (s->player.pos_y + 20 + s->player.move_speed) / 64;
	j = s->player.pos_x / 64;

    if (s->player.direction == 0)
        tex = s->tex.player_left;
    else
        tex = s->tex.player_right;
	if (s->key.w == 0 && s->key.a == 0 && s->key.d == 0 && s->key.s == 1)
	{
		s->player.frame++;
		if (s->player.frame >= 32)
			s->player.frame = 0;
		if (s->map.sup[i][j] != '1')
			s->player.pos_y += s->player.move_speed;

        precise_i = s->player.pos_y / 64;
        precise_j = s->player.pos_x / 64;
        if (s->player.pos_map_y != precise_i || 
                s->player.pos_map_x != precise_j) {
            s->player.move++;
            printf("player_move: %d\n", s->player.move);
            s->player.pos_map_y = precise_i;
            s->player.pos_map_x = precise_j;
        }

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
	} else if (s->key.w == 0 && s->key.s == 1) {
		if (s->map.sup[i][j] != '1')
			s->player.pos_y += s->player.move_speed;
    }

}

void	key_act_right(t_all *s)
{
	int		i;
	int		j;
    int     precise_i;
    int     precise_j;

	i = s->player.pos_y / 64;
	j = (s->player.pos_x + 20 + s->player.move_speed) / 64;

	if (s->key.d == 1)
	{
        s->player.direction = 1;
		s->player.frame++;
		if (s->player.frame >= 32)
			s->player.frame = 0;
		if (s->map.sup[i][j] != '1')
			s->player.pos_x += s->player.move_speed;

        precise_i = s->player.pos_y / 64;
        precise_j = s->player.pos_x / 64;
        if (s->player.pos_map_y != precise_i || 
                s->player.pos_map_x != precise_j) {
            s->player.move++;
            printf("player_move: %d\n", s->player.move);
            s->player.pos_map_y = precise_i;
            s->player.pos_map_x = precise_j;
        }

		if (s->player.frame % 32 >= 0 && s->player.frame < 4)
			s->player.img = s->tex.player_right[0];
		else if (s->player.frame % 32 >= 4 && s->player.frame < 8)
			s->player.img = s->tex.player_right[1];
		else if (s->player.frame % 32 >= 8 && s->player.frame < 12)
			s->player.img = s->tex.player_right[2];
		else if (s->player.frame % 32 >= 12 && s->player.frame < 16)
			s->player.img = s->tex.player_right[3];
		else if (s->player.frame % 32 >= 16 && s->player.frame < 20)
			s->player.img = s->tex.player_right[4];
		else if (s->player.frame % 32 >= 20 && s->player.frame < 24)
			s->player.img = s->tex.player_right[5];
		else if (s->player.frame % 32 >= 24 && s->player.frame < 28)
			s->player.img = s->tex.player_right[6];
		else if (s->player.frame % 32 >= 28 && s->player.frame < 32)
			s->player.img = s->tex.player_right[7];
	}
}

void	key_act_enter(t_all *s)
{
	if (s->win.intro_flag == 1 && s->key.n == 1)
	{
		if (s->win.frame >= 0 && s->win.frame < 250)
			s->win.frame = 250;
		else if (s->win.frame >= 250 && s->win.frame < 500)
			s->win.frame = 500;
		else if (s->win.frame >= 500 && s->win.frame < 750)
			s->win.frame = 750;
		else if (s->win.frame >= 750 && s->win.frame < 1000)
			s->win.frame = 1000;
		else if (s->win.frame >= 1000 && s->win.frame < 1250)
			s->win.frame = 1250;
		else if (s->win.frame >= 1250 && s->win.frame < 1500)
			s->win.frame = 1500;
		else if (s->win.frame >= 1500 && s->win.frame < 1750)
			s->win.frame = 1750;
		s->key.n = 0;
	}
}
