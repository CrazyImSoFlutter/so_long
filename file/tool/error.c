/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noguen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 22:41:11 by noguen            #+#    #+#             */
/*   Updated: 2022/01/17 01:13:54 by noguen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	tool_error1(int err)
{
	if (err == -1)
		printf("Error Code 1 : Invalid argument.\n");
	else if (err == -2)
		printf("Error Code 2 : Can't open the file(fd).\n");
	else if (err == -3)
		printf("Error Code 3 : Can't parse the file(gnl).\n");
	else if (err == -4)
		printf("Error Code 4 : Malloc Error.\n");
	else if (err == -5)
		printf("Error Code 5 : Map size is not appropriate.\n");
	else if (err == -6)
		printf("Error Code 6 : Map is not rectangular.\n");
	else if (err == -7)
		printf("Error Code 7 : Map has no exit.\n");
	else if (err == -8)
		printf("Error Code 8 : Map has no collectable thing.\n");
	else if (err == -9)
		printf("Error Code 9 : Map has no player\n");
	exit(0);
	return (-1);
}

int	tool_error2(int err)
{
	if (err == -10)
		printf("Error Code 10 : Map has no movable space.\n");
	else if (err == -11)
		printf("Error Code 11 : Player can't win");
	else if (err == -12)
		printf("Error Code 12 : Invalid texture.\n");
	exit(0);
	return (-1);
}

int	tool_error3(int err)
{
	if (err == -15)
	{
		printf("Error Code 7 : Map has no exit.\n");
		printf("Error Code 8 : Map has no collectable thing.\n");
	}
	else if (err == -16)
	{
		printf("Error Code 7 : Map has no exit.\n");
		printf("Error Code 9 : Map has no player\n");
	}
	else if (err == -17)
	{
		printf("Error Code 8 : Map has no collectable thing.\n");
		printf("Error Code 9 : Map has no player\n");
	}
	else if (err == -24)
	{
		printf("Error Code 7 : Map has no exit.\n");
		printf("Error Code 8 : Map has no collectable thing.\n");
		printf("Error Code 9 : Map has no player\n");
	}
	exit(0);
	return (-1);
}

int tool_error4(int err)
{
	if (err == -30)
		printf("Error Code 30 : Can't init enemy.\n");
	exit(0);
	return (-1);
}

int	tool_error(int err)
{
	if (err > -10)
		return tool_error1(err);
	else if (err > -15)
		return tool_error2(err);
	else if (err > -30)
		return tool_error3(err);
	else
		return tool_error4(err);
}
