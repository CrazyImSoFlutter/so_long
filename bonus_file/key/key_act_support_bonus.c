/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_act_support_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noguen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 00:12:44 by noguen            #+#    #+#             */
/*   Updated: 2022/01/18 00:48:14 by noguen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_include/so_long_bonus.h"

void	key_act_support_y(t_all *s, int op, int i, int j)
{
	int	precise_i;
	int	precise_j;

	s->player.frame = (s->player.frame + 1) % 32;
	if (s->map.sup[i][j] != '1')
		s->player.pos_y += (P_MOVE_SPEED * op);
	precise_i = s->player.pos_y / 64;
	precise_j = s->player.pos_x / 64;
	if (s->player.pos_map_y != precise_i
		|| s->player.pos_map_x != precise_j)
	{
		s->player.move++;
		printf("player_move: %d\n", s->player.move);
		s->player.pos_map_y = precise_i;
		s->player.pos_map_x = precise_j;
	}
	set_player_image(s);
}

void	key_act_support_x(t_all *s, int op, int i, int j)
{
	int	precise_i;
	int	precise_j;

	s->player.frame = (s->player.frame + 1) % 32;
	if (s->map.sup[i][j] != '1')
		s->player.pos_x += (P_MOVE_SPEED * op);
	precise_i = s->player.pos_y / 64;
	precise_j = s->player.pos_x / 64;
	if (s->player.pos_map_y != precise_i
		|| s->player.pos_map_x != precise_j)
	{
		s->player.move++;
		printf("player_move: %d\n", s->player.move);
		s->player.pos_map_y = precise_i;
		s->player.pos_map_x = precise_j;
	}
	set_player_image(s);
}
