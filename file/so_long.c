/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogeun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 15:50:04 by nogeun            #+#    #+#             */
/*   Updated: 2021/07/19 11:22:03 by nogeun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_variable(t_all *s)
{
	s->map.x = 0;
	s->map.y = 0;
	s->map.map = NULL;
	s->err.n = 0;
}

void	init_screen(t_all *s, char **argv)
{
	int		i;
	int		j;
	
	j = -1;
	i = -1;
	s->mlx.ptr = mlx_init();
	if (parse(s, argv[1]) == -1)
		exit(0);
	s->win.x = s->map.x * 40;
	s->win.y = s->map.y * 40;
	printf("%d %d", s->win.x, s->win.y);
	s->win.buf = malloc(sizeof(int *) * s->win.y);
	while (++i < s->win.y)
		s->win.buf[i] = malloc(sizeof(int) * s->win.x);
	i = -1;
	while (++i < s->win.y)
	{
		j = -1;
		while (++j < s->win.x)
			s->win.buf[i][j] = 0;
	}
	s->win.ptr = mlx_new_window(s->mlx.ptr, s->win.x, s->win.y, "so_long");
	s->img.ptr = mlx_new_image(s->mlx.ptr, s->win.x, s->win.y);
	/*s->img.ptr = mlx_xpm_file_to_image(s->mlx.ptr, "textures/player.xpm", &s->img.width, &s->img.height);
	s->img.data = (int *)mlx_get_data_addr(s->img.ptr, &s->img.bpp, &s->img.size_l, &s->img.endian);*/
	input_texture(s);
	for (int i = 0; i < 32; i++)
		mlx_put_image_to_window(s->mlx.ptr, s->win.ptr, s->img.ptr, i * s->img.width, 0);
}

void	init_loop(t_all *s)
{
	mlx_loop(s->mlx.ptr);
}

void	init_so_long(t_all *s, char **argv)
{
	init_variable(s);
	init_screen(s, argv);
	init_loop(s);
}

int		main (int argc, char **argv)
{
	t_all	s;
	int i;

	i = argc;

	init_so_long(&s, argv);
	/*	
	for (int i = 0; i < s.map.y; i++)
	{
		for (int j = 0; j < s.map.x; j++)
		{
			printf("%c", s.map.map[i][j]);
		}
		printf("\n");
	}
	*/
}
