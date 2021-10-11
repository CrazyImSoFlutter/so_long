/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogeun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 23:34:18 by nogeun            #+#    #+#             */
/*   Updated: 2021/10/11 18:18:33 by nogeun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*tex_input_xpm(t_all *s, char *file)
{
	void	*img;

	img = mlx_xpm_file_to_image(s->mlx.ptr, file, &(s->img.width), &(s->img.height));
	if (img == NULL)
		printf("error");
	return (img);
}

void	tex_input(t_all *s)
{
	s->tex.wall = tex_input_xpm(s, "textures/wall.xpm");
	s->tex.sand = tex_input_xpm(s, "textures/sand.xpm");
	s->tex.player_left[0] = tex_input_xpm(s, "textures/player_left1.xpm");
	s->tex.player_right[0] = tex_input_xpm(s, "textures/player_right1.xpm");
}
