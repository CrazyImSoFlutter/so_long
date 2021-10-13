/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogeun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 23:34:18 by nogeun            #+#    #+#             */
/*   Updated: 2021/10/14 01:00:52 by nogeun           ###   ########.fr       */
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
	s->tex.intro[0] = tex_input_xpm(s, "textures/intro0.xpm");
	s->tex.intro[1] = tex_input_xpm(s, "textures/intro1.xpm");
	s->tex.intro[2] = tex_input_xpm(s, "textures/intro2.xpm");
	s->tex.intro[3] = tex_input_xpm(s, "textures/intro3.xpm");
	s->tex.intro[4] = tex_input_xpm(s, "textures/intro4.xpm");
	s->tex.intro[5] = tex_input_xpm(s, "textures/intro5.xpm");
	s->tex.intro[6] = tex_input_xpm(s, "textures/intro6.xpm");
	s->tex.wall = tex_input_xpm(s, "textures/wall.xpm");
	s->tex.sand = tex_input_xpm(s, "textures/sand.xpm");
	s->tex.player_left[0] = tex_input_xpm(s, "textures/player_left0.xpm");
	s->tex.player_left[1] = tex_input_xpm(s, "textures/player_left1.xpm");
	s->tex.player_left[2] = tex_input_xpm(s, "textures/player_left2.xpm");
	s->tex.player_left[3] = tex_input_xpm(s, "textures/player_left3.xpm");
	s->tex.player_left[4] = tex_input_xpm(s, "textures/player_left4.xpm");
	s->tex.player_left[5] = tex_input_xpm(s, "textures/player_left5.xpm");
	s->tex.player_left[6] = tex_input_xpm(s, "textures/player_left6.xpm");
	s->tex.player_left[7] = tex_input_xpm(s, "textures/player_left7.xpm");
	//s->tex.player_right[0] = tex_input_xpm(s, "textures/player_right1.xpm");
}
