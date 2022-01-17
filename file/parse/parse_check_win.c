/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check_win.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noguen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 00:02:55 by noguen            #+#    #+#             */
/*   Updated: 2022/01/17 02:37:49 by noguen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_bfs1(t_all *s)
{
	s->bfs.dy[0] = 0;
	s->bfs.dy[1] = 0;
	s->bfs.dy[2] = -1;
	s->bfs.dy[3] = 1;
	s->bfs.dx[0] = -1;
	s->bfs.dx[1] = 1;
	s->bfs.dx[2] = 0;
	s->bfs.dx[3] = 0;
	s->bfs.index = 0;
	s->bfs.q_size = 0;
}

void	set_bfs2(t_all *s)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 10)
	{
		j = -1;
		while (++j < 20)
			s->bfs.visit[i][j] = 0;
	}
	i = -1;
	while (++i < 500)
	{
		s->bfs.q[i].x = -1;
		s->bfs.q[i].y = -1;
	}
}

void	set_bfs_x_y(t_all *s)
{
	int	i;
	int	j;

	i = -1;
	while (++i < s->map.y)
	{
		j = -1;
		while (++j < s->map.x)
		{
			if (s->map.map[i][j] == 'P')
			{
				s->bfs.y = i;
				s->bfs.x = j;
				s->bfs.visit[i][j] = 1;
			}
		}
	}
}

int	parse_check_win(t_all *s)
{
	int	i;
	int	j;

	set_bfs1(s);
	set_bfs2(s);
	set_bfs_x_y(s);
	s->bfs.q[s->bfs.q_size].y = s->bfs.y;
	s->bfs.q[s->bfs.q_size].x = s->bfs.x;
	s->bfs.q_size++;
	parse_check_bfs(s);
	i = -1;
	while (++i < s->map.y)
	{
		j = -1;
		while (++j < s->map.x)
		{
			if ((s->map.map[i][j] == 'E'
				|| s->map.map[i][j] == 'C')
				&& s->bfs.visit[i][j] == 0)
				return (tool_error(-11));
		}
	}
	return (1);
}

void	parse_check_bfs(t_all *s)
{
	int	x;
	int	y;
	int	i;

	while (s->bfs.index < s->bfs.q_size)
	{
		y = s->bfs.q[s->bfs.index].y;
		x = s->bfs.q[s->bfs.index].x;
		s->bfs.index++;
		i = -1;
		while (++i < 4)
		{
			if (y + s->bfs.dy[i] < 0 || y + s->bfs.dy[i] >= s->map.y
				|| x + s->bfs.dx[i] < 0 || x + s->bfs.dx[i] >= s->map.x)
				continue ;
			if (s->bfs.visit[y + s->bfs.dy[i]][x + s->bfs.dx[i]] == 0
				&& s->map.map[y + s->bfs.dy[i]][x + s->bfs.dx[i]] != '1')
			{
				s->bfs.visit[y + s->bfs.dy[i]][x + s->bfs.dx[i]] = 1;
				s->bfs.q[s->bfs.q_size].y = y + s->bfs.dy[i];
				s->bfs.q[s->bfs.q_size].x = x + s->bfs.dx[i];
				s->bfs.q_size++;
			}
		}
	}
}
