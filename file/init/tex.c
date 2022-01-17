/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noguen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 00:13:50 by noguen            #+#    #+#             */
/*   Updated: 2022/01/18 00:41:33 by noguen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	*tex_input_xpm(t_all *s, char *file)
{
	void	*img;

	img = mlx_xpm_file_to_image
		(s->mlx.ptr, file, &(s->img.width), &(s->img.height));
	if (img == NULL)
		s->err.n = tool_error(-12);
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
	s->tex.object = tex_input_xpm(s, "textures/object.xpm");
	s->tex.black = tex_input_xpm(s, "textures/black.xpm");
	s->tex.win = tex_input_xpm(s, "textures/win.xpm");
	s->tex.lose = tex_input_xpm(s, "textures/lose.xpm");
	s->tex.player_left = tex_input_xpm(s, "textures/player_left0.xpm");
	s->tex.player_right = tex_input_xpm(s, "textures/player_right0.xpm");
	s->tex.exit = tex_input_xpm(s, "textures/exit0.xpm");
}
