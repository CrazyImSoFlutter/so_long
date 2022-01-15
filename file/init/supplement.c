/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supplement.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noguen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 00:12:43 by noguen            #+#    #+#             */
/*   Updated: 2022/01/16 00:14:20 by noguen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	supplement_set_map(t_all *s)
{
	int	i;
	int	j;

	i = -1;
	s->map.sup = malloc(sizeof(char *) * 10);
	if (!s->map.sup)
		return (-1);
	while (++i < 10)
	{
		s->map.sup[i] = malloc(sizeof(char) * 20);
		if (!s->map.sup)
			return (-1);
	}
	i = -1;
	while (++i < 10)
	{
		j = -1;
		while (++j < 20)
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
	space_x = (20 - s->map.x) / 2;
	space_y = (10 - s->map.y) / 2;
	i = -1;
	while (++i < s->map.y)
	{
		j = -1;
		while (++j < s->map.x)
			s->map.sup[i + space_y][j + space_x] = s->map.map[i][j];
	}
}
