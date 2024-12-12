/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duck_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victda-s <victda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 23:09:51 by victda-s          #+#    #+#             */
/*   Updated: 2024/12/12 01:49:53 by victda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

void	duck_render(t_core *core, int i, int x, int y)
{
	mlx_put_image_to_window(core->win.mlx, core->win.ptr,
		core->duck.frames[i], x, y);
}

int	load_duck(t_core *core)
{
	char	*path[3];

	path[0] = "assets/characters/duck1.xpm";
	path[1] = "assets/characters/duck_left.xpm";
	path[2] = NULL;
	return (load_img(path, core->duck.frames, core));
}
