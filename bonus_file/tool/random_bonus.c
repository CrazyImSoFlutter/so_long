/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noguen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 00:38:28 by noguen            #+#    #+#             */
/*   Updated: 2022/01/18 00:49:00 by noguen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_include/so_long_bonus.h"

void	tool_srand(t_all *s, int seed)
{
	s->holdrand = (long)seed;
}

int	tool_rand(t_all *s)
{
	s->holdrand = s->holdrand * 214013L + 2531011L;
	return ((s->holdrand >> 16) & 0x7fff);
}
