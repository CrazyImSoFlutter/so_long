/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogeun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 00:28:14 by nogeun            #+#    #+#             */
/*   Updated: 2021/10/13 21:55:08 by nogeun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		key_pressed(int k, t_all *s)
{
	if (k == KEY_W)
		s->key.w = 1;
	else if (k == KEY_A)
		s->key.a = 1;
	else if (k == KEY_S)
		s->key.s = 1;
	else if (k == KEY_D)
		s->key.d = 1;
	else if (k == KEY_ENTER)
		s->key.n = 1;
	if (k != KEY_ENTER)
		s->player.frame++;
	if (s->player.frame >= 8)
		s->player.frame = 0;
	return (0);
}

int		key_released(int k, t_all *s)
{
	if (k == KEY_W)
		s->key.w = 0;
	else if (k == KEY_A)
		s->key.a = 0;
	else if (k == KEY_S)
		s->key.s = 0;
	else if (k == KEY_D)
		s->key.d = 0;
	s->player.frame = 0;
	return (0);
}

int		key_update(t_all *s)
{
	key_act_up(s);
	key_act_left(s);
	key_act_down(s);
	key_act_right(s);
	key_act_enter(s);
	return (0);
}
