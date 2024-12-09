/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keyboard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victda-s <victda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 23:06:17 by victda-s          #+#    #+#             */
/*   Updated: 2024/12/08 21:38:53 by victda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"
#include <stdio.h>

static void	key_escape(int keysym, t_core *core)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(core->win.mlx, core->win.ptr);
		exit(0);
	}
}

static void	move_if_valid(t_core *core, int dx, int dy)
{
	int		duck_x;
	int		duck_y;
	char	**map;

	map = core->map;
	duck_x = (core->duck.pos_x) / 32;
	duck_y = (core->duck.pos_y) / 32;
	if (map[duck_y + dy][duck_x + dx] != '1' &&
	map[duck_y + dy][duck_x + dx] != 'E')
	{
		if (map[duck_y + dy][duck_x + dx] == 'C')
		{
			core->map[duck_y + dy][duck_x + dx] = '0';
			core->coin.collected++;
		}
		grass_render(core, 5, core->duck.pos_x, core->duck.pos_y);
		core->duck.pos_x += dx * 32;
		core->duck.pos_y += dy * 32;
	}
	if (map[duck_y + dy][duck_x + dx] == 'E')
	{
		if (core->coin.total == core->coin.collected)
		{
			mlx_destroy_window(core->win.mlx, core->win.ptr);
			exit(0);
		}
	}
}

int	handle_keyboard(int keysym, t_core *core)
{
	key_escape(keysym, core);
	if (keysym == XK_a)
		move_if_valid(core, -1, 0);
	if (keysym == XK_d)
		move_if_valid(core, 1, 0);
	if (keysym == XK_w)
		move_if_valid(core, 0, -1);
	if (keysym == XK_s)
		move_if_valid(core, 0, 1);
	return (0);
}
// int	handle_keyboard(int keysym, t_core *core)
// {
// 	int		duck_x;
// 	int		duck_y;
// 	char	**map;
//
// 	map = core->map;
// 	duck_x = (core->duck.pos_x - 64) / 32;
// 	duck_y = (core->duck.pos_y - 64) / 32;
// 	key_escape(keysym, core);
// 	if (keysym == XK_a && map[duck_y][duck_x - 1] != '1')
// 	{
// 		grass_render(core, 5, core->duck.pos_x, core->duck.pos_y);
// 		core->duck.pos_x -= 32;
// 	}
// 	if (keysym == XK_d && map[duck_y][duck_x + 1] != '1')
// 	{
// 		grass_render(core, 5, core->duck.pos_x, core->duck.pos_y);
// 		core->duck.pos_x += 32;
// 	}
// 	if (keysym == XK_w && map[duck_y - 1][duck_x] != '1')
// 	{
// 		grass_render(core, 5, core->duck.pos_x, core->duck.pos_y);
// 		core->duck.pos_y -= 32;
// 	}
// 	if (keysym == XK_s && map[duck_y + 1][duck_x] != '1')
// 	{
// 		grass_render(core, 5, core->duck.pos_x, core->duck.pos_y);
// 		core->duck.pos_y += 32;
// 	}
// 	return (0);
// }
