/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grass_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victda-s <victda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 02:44:37 by victda-s          #+#    #+#             */
/*   Updated: 2024/12/11 23:36:07 by victda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

void	grass_render(t_core *core, int i, int x, int y)
{
	mlx_put_image_to_window(core->win.mlx, core->win.ptr,
		core->grass.frames[i], x, y);
}

int	load_grass(t_core *core)
{
	char	*path[11];

	path[0] = "assets/texture/grass/grass_left_up.xpm";
	path[1] = "assets/texture/grass/grass_right_up.xpm";
	path[2] = "assets/texture/grass/grass_middle_up.xpm";
	path[3] = "assets/texture/grass/grass_middle_right.xpm";
	path[4] = "assets/texture/grass/grass_left_down.xpm";
	path[5] = "assets/texture/grass/grass_middle.xpm";
	path[6] = "assets/texture/grass/grass_middle_down.xpm";
	path[7] = "assets/texture/grass/grass_right_down.xpm";
	path[8] = "assets/texture/grass/grass_middle_left.xpm";
	path[9] = "assets/texture/wall/wall.xpm";
	path[10] = NULL;
	return (load_img(path, core->grass.frames, core));
}
