/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogeun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 19:41:32 by nogeun            #+#    #+#             */
/*   Updated: 2021/10/12 22:41:03 by nogeun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	intro(t_all *s)
{
	void	*img;
	int		index;

	if (s->win.frame >= 0 && s->win.frame < 250)
		index = 0;
	else
		index = 1;

	img = s->tex.intro[index];
	draw_put_image(s, img, 120, 280);
	s->win.frame++;
	if (s->win.frame >= 500)
		s->win.intro_flag = 0;
}
