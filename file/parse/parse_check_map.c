/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noguen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 22:18:20 by noguen            #+#    #+#             */
/*   Updated: 2022/01/17 01:19:06 by noguen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	parse_check_size(t_all *s)
{
	if (s->map.y < 5 || s->map.y > 10)
		return (tool_error(-5));
	if (s->map.x < 5 || s->map.x > 20)
		return (tool_error(-5));
	return (1);
}

int	parse_check_boarder(t_all *s)
{
	int	i;
	int	j;

	i = -1;
	while (++i < s->map.y)
	{
		if (i == 0 || i == s->map.y - 1)
		{
			j = -1;
			while (++j < s->map.x)
				if (s->map.map[i][j] != '1')
					return (tool_error(-6));
		}
		else
			if (s->map.map[i][0] != '1'
				|| s->map.map[i][s->map.x - 1] != '1')
				return (tool_error(-6));
	}
	return (1);
}

int	parse_check_element(t_all *s, char c)
{
	int	i;
	int	j;

	i = 0;
	while (++i < s->map.y - 1)
	{
		j = 0;
		while (++j < s->map.x)
		{
			if (s->map.map[i][j] == c)
				return (0);
		}
	}
	if (c == 'E')
		return (-7);
	else if (c == 'C')
		return (-8);
	else if (c == 'P')
		return (-9);
	return (0);
}

int	parse_check_space(t_all *s)
{
	int	i;
	int	j;

	i = 0;
	while (++i < s->map.y - 1)
	{
		j = 0;
		while (++j < s->map.x)
		{
			if (s->map.map[i][j] == '1')
				continue ;
			else
				return (1);
		}
	}
	return (tool_error(-10));
}

int	parse_check_all(t_all *s)
{
	int	err;

	err = 0;
	s->err.n = parse_check_size(s);
	s->err.n = parse_check_boarder(s);
	err += parse_check_element(s, 'E');
	err += parse_check_element(s, 'C');
	err += parse_check_element(s, 'P');
	if (err != 0)
		return (tool_error(err));
	s->err.n = parse_check_space(s);
	return (1);
}
