/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victda-s <victda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 21:31:16 by victda-s          #+#    #+#             */
/*   Updated: 2024/11/29 03:37:13 by victda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

int	game_loop(t_core *core)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (!core->grass.frames[i])
			write(1, "a", 1);
		mlx_put_image_to_window(core->win.mlx, core->win.ptr,
			core->grass.frames[i], 32 * i, 0);
		i++;
	}
	return (0);
}
