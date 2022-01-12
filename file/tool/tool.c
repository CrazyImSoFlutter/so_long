/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogeun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 00:15:17 by nogeun            #+#    #+#             */
/*   Updated: 2022/01/12 18:46:21 by noguen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		tool_strlen(char* line)
{
	int		n;
	
	n = 0;
	while (*line)
	{
		n++;
		line++;
	}
	return (n);
}

int		tool_get_digit_count(long int n)
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
	if (!(str = malloc((digit_count + 1) * sizeof(char))))
		return (NULL);
	str[0] = '0';
	if (long_n < 0)
	{
		str[0] = '-';
		long_n *= -1;
	}
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
