/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogeun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 23:47:03 by nogeun            #+#    #+#             */
/*   Updated: 2022/01/12 21:18:30 by noguen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_variables(t_all *s)
{
	s->map.x = 0;
	s->map.y = 0;
	s->map.map = NULL;
	s->map.sup = NULL;
	s->win.y = 720;
	s->win.x = 1280;
	s->win.intro_flag = 1;
	s->win.tile_flag = 1;
	s->win.frame = 0;
	s->player.pos_y = 0;
	s->player.pos_x = 0;
	s->player.move_speed = 2;
	s->player.frame = 1;
	s->player.img = NULL;
    s->player.move = 0;
	s->key.w = 0;
	s->key.s = 0;
	s->key.a = 0;
	s->key.d = 0;
	s->key.n = 0;
    s->key.q = 0;
	s->key.space = 0;
	s->player.direction = 0;
    s->object_count = 0;
    s->map.exit_flag = 0;
    s->map.exit_frame = 0;
}

void	init_screen(t_all *s, char **argv)
{
	s->mlx.ptr = mlx_init();
	if (parse(s, argv[1]) == -1)
		exit(0);

	supplement_input_map(s);

	pos_player(s);
	tex_input(s);
    object_count(s);
    find_exit(s);
	s->player.img = s->tex.player_left[0];
    printf("%d %d", s->win.x, s->win.y);
	s->win.ptr = mlx_new_window(s->mlx.ptr, s->win.x, s->win.y, "so_long");
	s->img.ptr = mlx_new_image(s->mlx.ptr, s->win.x, s->win.y);
}

int		main_loop(t_all *s)
{
	if (s->win.intro_flag)
		intro(s);
	else {
        draw_point(s);
		if (s->win.tile_flag)
			draw_tiles(s);
        if (s->map.exit_flag)
            draw_exit(s);
        if (s->player.win_flag == 0)
		    draw_player(s);
	}
    if (s->player.win_flag == 0)
    {
    	key_update(s);
        object_get(s);
        win_exit(s);
    }
    else if (s->player.win_flag == 1)
    {
        if (s->win.frame != 400)
            draw_end(s);
    }
    else
    {

    }
	return 0;
}

void	init_loop(t_all *s)
{
	mlx_hook(s->win.ptr, 2, 0, &key_pressed, s);
	mlx_hook(s->win.ptr, 3, 0, &key_released, s);
	mlx_loop_hook(s->mlx.ptr, &main_loop, s);
	mlx_loop(s->mlx.ptr);
}

void	init_so_long(t_all *s, char **argv)
{
	init_variables(s);
	init_screen(s, argv);
	init_loop(s);
}
