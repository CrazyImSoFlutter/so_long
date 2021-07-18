/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogeun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 15:51:40 by nogeun            #+#    #+#             */
/*   Updated: 2021/07/17 17:21:27 by nogeun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	longest_line(t_all *s, char *map)
{
	char	*line;
	int		fd;
	int		ret;

	ret = 1;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		printf("error");
	while (ret == 1)
	{
		ret = get_next_line(fd, &line);
		if (line[0] == ' ' || line[0] == '1')
		{
			if (s->map.x <= tool_strlen(line))
				s->map.x = tool_strlen(line);
			s->map.y++;
		}
		free(line);
	}
	close(fd);
}

int		set_map(t_all *s)
{
	int		j;

	j = -1;
	if (!(s->map.map = malloc(sizeof(char *) * (s->map.y + 1))))
		return (-1);
	while (++j < s->map.y + 2)
	{
		if (!(s->map.map[j] = malloc(sizeof(char) * (s->map.x + 1))))
			return (-1);
	}
	j = -1;
	while (++j < s->map.y + 2)
	{
		s->map.map[j][0] = '\0';
	}
	return (0);
}

int		input_map(t_all *s, char *line, int *j)
{
	int		k;

	k = 0;
	while (k < s->map.x)
	{
		s->map.map[*j][k] = line[k];
		k++;
	}
	*j = *j + 1;
	return (0);
}

int		parse(t_all *s, char *map)
{
	char	*line;
	int		fd;
	int		ret;
	int		j;

	longest_line(s, map);
	set_map(s);
	ret = 1;
	fd = open(map, O_RDONLY);
	j = 0;
	if (fd == -1)
		printf("error");
	if (s->map.map == NULL)
		s->err.n = set_map(s);
	while (ret == 1)
	{
		ret = get_next_line(fd, &line);
		if (input_map(s, line, &j) == -1)
			ret = -1;
		free(line);
	}
	close(fd);
	return (0);
}
