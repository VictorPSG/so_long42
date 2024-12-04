/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keyboard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victda-s <victda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 23:06:17 by victda-s          #+#    #+#             */
/*   Updated: 2024/12/03 20:55:22 by victda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

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
	key_escape(keysym, core);
	if (keysym == XK_a)
	{
		grass_render(core, 5, core->duck.pos_x, core->duck.pos_y);
		core->duck.pos_x -= 32;
	}
	if (keysym == XK_d)
	{
		grass_render(core, 5, core->duck.pos_x, core->duck.pos_y);
		core->duck.pos_x += 32;
	}
	if (keysym == XK_w)
	{
		grass_render(core, 5, core->duck.pos_x, core->duck.pos_y);
		core->duck.pos_y -= 32;
	}
	if (keysym == XK_s)
	{
		grass_render(core, 5, core->duck.pos_x, core->duck.pos_y);
		core->duck.pos_y += 32;
	}
	return (0);
}
