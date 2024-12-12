/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victda-s <victda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 00:03:56 by victda-s          #+#    #+#             */
/*   Updated: 2024/12/12 20:28:22 by victda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

void	exit_render(t_core *core, int i, int x, int y)
{
	mlx_put_image_to_window(core->win.mlx, core->win.ptr, core->exit.frame[i],
		x, y);
}

int	load_exit(t_core *core)
{
	char	*path[2];

	path[0] = "assets/texture/exit/exit.xpm";
	path[1] = NULL;
	return (load_img(path, core->exit.frame, core));
}
