/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noguen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 23:41:38 by noguen            #+#    #+#             */
/*   Updated: 2022/01/18 01:22:13 by noguen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	intro(t_all *s)
{
	void	*img;
	int		index;

	if (s->win.frame == 1750)
	{
		s->win.intro_flag = 0;
		destroy_intro(s);
		return ;
	}
	index = s->win.frame / 250;
	img = s->tex.intro[index];
	draw_put_image(s, img, 120, 280);
	s->win.frame++;
}

void	destroy_intro(t_all *s)
{
	int	i;

	i = -1;
	while (++i < 7)
		mlx_destroy_image(s->mlx.ptr, s->tex.intro[i]);
}
