/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_act.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogeun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 12:48:25 by nogeun            #+#    #+#             */
/*   Updated: 2022/01/14 22:26:25 by noguen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_act_up(t_all *s)
{
	int		i;
	int		j;
    int     precise_i;
    int     precise_j;

	i = (s->player.pos_y - 20 - P_MOVE_SPEED) / 64;
	j = s->player.pos_x / 64;
	if (s->key.w == 1 && s->key.a == 0 && s->key.d == 0 && s->key.s == 0)
	{
		s->player.frame = (s->player.frame + 1) % 32;
		if (s->map.sup[i][j] != '1')
			s->player.pos_y -= P_MOVE_SPEED;

        precise_i = s->player.pos_y / 64;
        precise_j = s->player.pos_x / 64;
        if (s->player.pos_map_y != precise_i || 
                s->player.pos_map_x != precise_j)
        {
            s->player.move++;
            printf("player_move: %d\n", s->player.move);
            s->player.pos_map_y = precise_i;
            s->player.pos_map_x = precise_j;
        }
        set_player_image(s);
	} else if (s->key.w == 1 && s->key.s == 0) {
		if (s->map.sup[i][j] != '1')
			s->player.pos_y -= P_MOVE_SPEED;
    }
}

void	key_act_left(t_all *s)
{
	int		i;
	int		j;
    int     precise_i;
    int     precise_j;

	i = s->player.pos_y / 64;
	j = (s->player.pos_x - 20 - P_MOVE_SPEED) / 64;
	if (s->key.a == 1 && s->key.d == 0)
	{
        s->player.direction = 0;
		s->player.frame = (s->player.frame + 1) % 32;
		if (s->map.sup[i][j] != '1')
			s->player.pos_x -= P_MOVE_SPEED;
        precise_i = s->player.pos_y / 64;
        precise_j = s->player.pos_x / 64;
        if (s->player.pos_map_y != precise_i || 
                s->player.pos_map_x != precise_j) {
            s->player.move++;
            printf("player_move: %d\n", s->player.move);
            s->player.pos_map_y = precise_i;
            s->player.pos_map_x = precise_j;
        }
        set_player_image(s);
	}
}

void	key_act_down(t_all *s)
{
	int		i;
	int		j;
    int     precise_i;
    int     precise_j;

	i = (s->player.pos_y + 20 + P_MOVE_SPEED) / 64;
	j = s->player.pos_x / 64;
	if (s->key.w == 0 && s->key.a == 0 && s->key.d == 0 && s->key.s == 1)
	{
		s->player.frame = (s->player.frame + 1) % 32;
		if (s->map.sup[i][j] != '1')
			s->player.pos_y += P_MOVE_SPEED;
        precise_i = s->player.pos_y / 64;
        precise_j = s->player.pos_x / 64;
        if (s->player.pos_map_y != precise_i || 
                s->player.pos_map_x != precise_j) {
            s->player.move++;
            printf("player_move: %d\n", s->player.move);
            s->player.pos_map_y = precise_i;
            s->player.pos_map_x = precise_j;
        }
        set_player_image(s);
	} else if (s->key.w == 0 && s->key.s == 1) {
		if (s->map.sup[i][j] != '1')
			s->player.pos_y += P_MOVE_SPEED;
    }
}

void	key_act_right(t_all *s)
{
	int		i;
	int		j;
    int     precise_i;
    int     precise_j;

	i = s->player.pos_y / 64;
	j = (s->player.pos_x + 20 + P_MOVE_SPEED) / 64;
	if (s->key.d == 1)
	{
        s->player.direction = 1;
		s->player.frame = (s->player.frame + 1) % 32;
		if (s->map.sup[i][j] != '1')
			s->player.pos_x += P_MOVE_SPEED;
        precise_i = s->player.pos_y / 64;
        precise_j = s->player.pos_x / 64;
        if (s->player.pos_map_y != precise_i || 
                s->player.pos_map_x != precise_j) {
            s->player.move++;
            printf("player_move: %d\n", s->player.move);
            s->player.pos_map_y = precise_i;
            s->player.pos_map_x = precise_j;
        }
        set_player_image(s);
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
