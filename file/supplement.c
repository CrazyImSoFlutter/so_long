/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supplement.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogeun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 23:39:42 by nogeun            #+#    #+#             */
/*   Updated: 2021/10/12 00:15:00 by nogeun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		supplement_set_map(t_all *s)
{
	int		i;
	int		j;

	i = -1;
	s->map.sup = malloc(sizeof(char *) * 18);
	if (!s->map.sup)
		return (-1);
	while (++i < 18)
	{
		s->map.sup[i] = malloc(sizeof(char) * 30);
		if (!s->map.sup)
			return (-1);
	}
	i = -1;
	while (++i < 18)
	{
		j = -1;
		while (++j < 30)
			s->map.sup[i][j] = '9';
	}
	return (0);
}

void	supplement_input_map(t_all *s)
{
	int		i;
	int		j;
	int		space_x;
	int		space_y;

	supplement_set_map(s);
	space_x = (30 - s->map.x) / 2;
	space_y = (18 - s->map.y) / 2;
	i = -1;
	while (++i < s->map.y)
	{
		j = -1;
		while (++j < s->map.x)
			s->map.sup[i + space_y][j + space_x] = s->map.map[i][j];
	}
}
