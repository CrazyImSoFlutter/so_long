/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check_map2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noguen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:18:41 by noguen            #+#    #+#             */
/*   Updated: 2022/01/19 16:40:33 by hnoh             ###   ########.fr       */
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

int	parse_check_character(t_all *s)
{
	int	i;
	int	j;

	i = -1;
	while (++i < s->map.y)
	{
		j = -1;
		while (++j < s->map.x)
		{
			if (s->map.map[i][j] == '1'
				|| s->map.map[i][j] == '0'
				|| s->map.map[i][j] == 'E'
				|| s->map.map[i][j] == 'C'
				|| s->map.map[i][j] == 'P')
				continue ;
			else
				return (tool_error(-18));
		}
	}
	return (1);
}

void	parse_check_multiple_all(t_all *s)
{
	s->err.n = parse_check_multiple(s, 'P');
	s->err.n = parse_check_multiple(s, 'E');
}
