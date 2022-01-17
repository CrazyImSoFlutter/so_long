/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noguen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 23:41:58 by noguen            #+#    #+#             */
/*   Updated: 2022/01/18 00:47:07 by noguen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_include/so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_all	s;

	if (argc != 2)
		tool_error(0);
	check_argument(&s, argv);
	init_so_long(&s, argv);
}
