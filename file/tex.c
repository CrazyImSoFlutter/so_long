/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogeun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 23:34:18 by nogeun            #+#    #+#             */
/*   Updated: 2021/10/10 21:02:01 by nogeun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*tex_input_xpm(t_all *s, char *file)
{
	int size;
	void	*img;
	char name[18] = {'t', 'e', 'x', 't', 'u', 'r', 'e', 's', '/', 'w', 'a', 'l', 'l', '.', 'x', 'p', 'm', '\n'};

	if (strcmp(file, name))
		size = 80;
	else
		size = 40;

	img = mlx_xpm_file_to_image(s->mlx.ptr, file, &(s->img.width), &(s->img.height));
	if (img == NULL)
		printf("error");
	return (img);
}

void	tex_input(t_all *s)
{
	s->tex.wall = tex_input_xpm(s, "textures/wall.xpm");
	s->tex.sand = tex_input_xpm(s, "textures/sand.xpm");
}
