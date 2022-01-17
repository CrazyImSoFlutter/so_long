/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_quit_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noguen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 00:34:38 by noguen            #+#    #+#             */
/*   Updated: 2022/01/18 00:48:19 by noguen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_include/so_long_bonus.h"

void	key_act_quit(t_all *s)
{
	if (s->key.q == 1)
	{
		exit(0);
	}
}

int	key_red_button(t_all *s)
{
	s->err.n = 1;
	exit(0);
	return (0);
}
