/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noguen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 00:39:02 by noguen            #+#    #+#             */
/*   Updated: 2022/01/18 01:54:12 by noguen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	tool_strlen(char *line)
{
	int	n;

	n = 0;
	while (*line)
	{
		n++;
		line++;
	}
	return (n);
}

int	tool_get_digit_count(long int n)
{
	int		i;

	if (n < 0)
		n *= -1;
	i = 1;
	while (n > 9)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*tool_itoa(int n)
{
	char			*str;
	int				digit_count;
	long int		long_n;

	long_n = n;
	digit_count = tool_get_digit_count(long_n);
	if (long_n < 0)
		digit_count++;
	str = malloc((digit_count + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[0] = '0';
	if (long_n < 0)
		support_itoa(str, &long_n);
	str[digit_count] = '\0';
	while (((digit_count >= 0 && str[0] != '-')
			|| (digit_count > 0 && str[0] == '-')) && long_n != 0)
	{
		str[digit_count - 1] = (long_n % 10) + '0';
		long_n /= 10;
		digit_count--;
	}
	return (str);
}

void	support_itoa(char *str, long int *long_n)
{
	str[0] = '-';
	(*long_n) *= -1;
}

void	free_map(t_all *s)
{
	int	i;

	i = -1;
	while (++i < s->map.y)
		free(s->map.map[i]);
	free(s->map.map);
}
