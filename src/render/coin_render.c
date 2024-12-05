/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coin_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victda-s <victda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 00:04:05 by victda-s          #+#    #+#             */
/*   Updated: 2024/12/05 01:24:04 by victda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

void	coin_render(t_core *core, int i, int x, int y)
{
	mlx_put_image_to_window(core->win.mlx, core->win.ptr,
		core->coin.frame[i], x, y);
}
int	load_coin(t_core *core)
{
	char	*path[2];

	path[0] = "assets/apple.xpm";
	path[1] = NULL;
	return (load_img(path, core->coin.frame, core));
}