/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogeun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 23:34:18 by nogeun            #+#    #+#             */
/*   Updated: 2021/10/17 14:48:40 by nogeun           ###   ########.fr       */
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
	s->tex.player_right[0] = tex_input_xpm(s, "textures/player_right0.xpm");
	s->tex.player_right[1] = tex_input_xpm(s, "textures/player_right1.xpm");
	s->tex.player_right[2] = tex_input_xpm(s, "textures/player_right2.xpm");
	s->tex.player_right[3] = tex_input_xpm(s, "textures/player_right3.xpm");
	s->tex.player_right[4] = tex_input_xpm(s, "textures/player_right4.xpm");
	s->tex.player_right[5] = tex_input_xpm(s, "textures/player_right5.xpm");
	s->tex.player_right[6] = tex_input_xpm(s, "textures/player_right6.xpm");
	s->tex.player_right[7] = tex_input_xpm(s, "textures/player_right7.xpm");
	s->tex.jump[0] = tex_input_xpm(s, "textures/jump0.xpm");
	s->tex.jump[1] = tex_input_xpm(s, "textures/jump1.xpm");
	s->tex.jump[2] = tex_input_xpm(s, "textures/jump2.xpm");
	s->tex.jump[3] = tex_input_xpm(s, "textures/jump3.xpm");
	s->tex.jump[4] = tex_input_xpm(s, "textures/jump4.xpm");
	s->tex.jump[5] = tex_input_xpm(s, "textures/jump5.xpm");
	s->tex.jump[6] = tex_input_xpm(s, "textures/jump6.xpm");
	s->tex.jump[7] = tex_input_xpm(s, "textures/jump7.xpm");
	s->tex.jump[8] = tex_input_xpm(s, "textures/jump8.xpm");
	s->tex.jump[9] = tex_input_xpm(s, "textures/jump9.xpm");
	s->tex.jump[10] = tex_input_xpm(s, "textures/jump10.xpm");
}
