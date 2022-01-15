/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noguen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 00:12:49 by noguen            #+#    #+#             */
/*   Updated: 2022/01/16 00:32:41 by noguen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parse_longest_line(t_all *s, char *map)
{
	char	*line;
	int		fd;
	int		ret;
	int		tmp;

	ret = 1;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		printf("error code : 1\n");
	while (ret == 1)
	{
		ret = get_next_line(fd, &line);
		if (line[0] == '1')
			tmp = tool_strlen(line);
		else
		{
			break ;
		}
		s->map.y++;
		if (s->map.x <= tmp)
			s->map.x = tmp;
		free(line);
	}
	close(fd);
}

int	parse_set_map(t_all *s)
{
	int	j;

	j = -1;
	s->map.map = malloc(sizeof(char *) * (s->map.y + 2));
	if (s->map.map == NULL)
		return (-1);
	while (++j < s->map.y + 2)
	{
		s->map.map[j] = malloc(sizeof(char) * (s->map.x + 1));
		if (s->map.map[j] == NULL)
			return (-1);
	}
	j = -1;
	while (++j < s->map.y + 2)
		s->map.map[j][0] = '\0';
	return (0);
}

int	parse_input_map(t_all *s, char *line, int *j)
{
	int	k;

	if (s->map.map == NULL)
		s->err.n = parse_set_map(s);
	k = 0;
	while (k < s->map.x)
	{
		s->map.map[*j][k] = line[k];
		k++;
	}
	*j = *j + 1;
	return (0);
}

int	parse(t_all *s, char *map)
{
	char	*line;
	int		fd;
	int		ret;
	int		j;

	parse_longest_line(s, map);
	ret = 1;
	fd = open(map, O_RDONLY);
	j = 0;
	if (fd == -1)
		printf("error code : 1\n");
	while (ret == 1)
	{
		ret = get_next_line(fd, &line);
		if (parse_input_map(s, line, &j) == -1)
			ret = -1;
		free(line);
	}
	close(fd);
	if (s->err.n < 0)
		return (-1);
	else
		return (0);
}
