/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noguen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 23:02:21 by noguen            #+#    #+#             */
/*   Updated: 2022/01/18 00:40:25 by noguen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	set_player_image(t_all *s)
{
	if (s->player.direction == LEFT)
		s->player.img = s->tex.player_left;
	else
		s->player.img = s->tex.player_right;
}
