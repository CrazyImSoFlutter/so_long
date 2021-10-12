/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_act.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogeun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 12:48:25 by nogeun            #+#    #+#             */
/*   Updated: 2021/10/12 13:01:36 by nogeun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_act_up(t_all *s)
{
	if (s->key.w == 1)
	{
		s->player.pos_y -= s->player.move_speed;
	}
}

void	key_act_left(t_all *s)
{
	if (s->key.a == 1)
	{
		s->player.pos_x -= s->player.move_speed;
	}

}

void	key_act_down(t_all *s)
{
	if (s->key.s == 1)
	{
		s->player.pos_y += s->player.move_speed;
	}

}

void	key_act_right(t_all *s)
{
	if (s->key.d == 1)
	{
		s->player.pos_x += s->player.move_speed;
	}
}
