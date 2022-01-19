/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check_map2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noguen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:18:41 by noguen            #+#    #+#             */
/*   Updated: 2022/01/19 15:41:50 by noguen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	parse_check_multiple(t_all *s, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (++i < s->map.y - 1)
	{
		j = 0;
		while (++j < s->map.x)
		{
			if (s->map.map[i][j] == c)
				count++;
		}
	}
	if (count != 1 && c == 'P')
		return (tool_error(-13));
	if (count != 1 && c == 'E')
		return (tool_error(-14));
	return (1);
}

void	parse_check_multiple_all(t_all *s)
{
	s->err.n = parse_check_multiple(s, 'P');
	s->err.n = parse_check_multiple(s, 'E');
}
