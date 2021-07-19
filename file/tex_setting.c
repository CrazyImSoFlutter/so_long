/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex_setting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogeun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 10:53:31 by nogeun            #+#    #+#             */
/*   Updated: 2021/07/19 11:25:48 by nogeun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	input_xpm(t_all *s, int **adr, char *file, int *flag)
{
	int			y;
	int			x;

	*adr = malloc(sizeof(int) * (64 * 64));
	s->img.ptr = 
		mlx_xpm_file_to_image(s->mlx.ptr, file, &s->img.width, &s->img.height);
	if (s->img.ptr == NULL || s->img.width != 64 || s->img.height != 64)
	{
		*flag = 0;
		return ;
	}
	s->img.data = (int *)mlx_get_data_addr(s->img.ptr,
			&s->img.bpp, &s->img.size_l, &s->img.endian);
	y = -1;
	while (++y < 64)
	{
		x = -1;
		while (++x < 64)
			(*adr)[64 * y + x] = s->img.data[64 * y + x];
	}
	mlx_destroy_image(s->mlx.ptr, s->img.ptr);
}

int		input_texture(t_all *s)
{
	int		flag;

	flag = 1;
	input_xpm(s, &s->tex.player[0], "textures/player.xpm", &flag);
	input_xpm(s, &s->tex.player[1], "textures/player.xpm", &flag);
	input_xpm(s, &s->tex.player[2], "textures/player.xpm", &flag);
	input_xpm(s, &s->tex.player[3], "textures/player.xpm", &flag);
	input_xpm(s, &s->tex.tile, "textures/player.xpm", &flag);
	input_xpm(s, &s->tex.wall, "textures/player.xpm", &flag);
	input_xpm(s, &s->tex.enemy, "textures/player.xpm", &flag);
	printf("%d", flag);
	return (0);
}
