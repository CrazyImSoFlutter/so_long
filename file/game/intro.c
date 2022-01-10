/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogeun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 19:41:32 by nogeun            #+#    #+#             */
/*   Updated: 2021/10/14 01:04:43 by nogeun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	intro(t_all *s)
{
	void	*img;
	int		index;

	index = 0;
	if (s->win.frame >= 0 && s->win.frame < 250)
		index = 0;
	else if (s->win.frame >= 250 && s->win.frame < 500)
		index = 1;
	else if (s->win.frame >= 500 && s->win.frame < 750)
		index = 2;
	else if (s->win.frame >= 750 && s->win.frame < 1000)
		index = 3;
	else if (s->win.frame >= 1000 && s->win.frame < 1250)
		index = 4;
	else if (s->win.frame >= 1250 && s->win.frame < 1500)
		index = 5;
	else if (s->win.frame >= 1500 && s->win.frame < 1750)
		index = 6;

	img = s->tex.intro[index];
	draw_put_image(s, img, 120, 280);
	s->win.frame++;
	if (s->win.frame >= 1750)
		s->win.intro_flag = 0;
}
