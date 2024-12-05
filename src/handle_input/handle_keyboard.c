/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keyboard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victda-s <victda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 23:06:17 by victda-s          #+#    #+#             */
/*   Updated: 2024/12/05 00:46:38 by victda-s         ###   ########.fr       */
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

int	handle_keyboard(int keysym, t_core *core)
{
	int		duck_x;
	int		duck_y;
	char	**map;
	
	map = core->map;
	duck_x = (core->duck.pos_x - 64) / 32;
	duck_y = (core->duck.pos_y - 64) / 32;
	key_escape(keysym, core);
	if (keysym == XK_a && map[duck_y][duck_x - 1] != '1')
	{
		grass_render(core, 5, core->duck.pos_x, core->duck.pos_y);
		core->duck.pos_x -= 32;
	}
	if (keysym == XK_d && map[duck_y][duck_x + 1] != '1')
	{
		grass_render(core, 5, core->duck.pos_x, core->duck.pos_y);
		core->duck.pos_x += 32;
	}
	if (keysym == XK_w && map[duck_y - 1][duck_x] != '1')
	{
		grass_render(core, 5, core->duck.pos_x, core->duck.pos_y);
		core->duck.pos_y -= 32;
	}
	if (keysym == XK_s && map[duck_y + 1][duck_x] != '1')
	{
		grass_render(core, 5, core->duck.pos_x, core->duck.pos_y);
		core->duck.pos_y += 32;
	}
	return (0);
}
