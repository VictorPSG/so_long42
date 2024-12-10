/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victda-s <victda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:55:37 by victda-s          #+#    #+#             */
/*   Updated: 2024/12/09 21:59:18 by victda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"
#include <stdio.h>	

int	main(void)
{
	t_core	core;

	core.coin.total = 0;
	core.coin.collected = 0;
	core.map = map_matrix("src/map/map.ber", &core);
	core.win.mlx = mlx_init();
	if (!core.win.mlx)
	{
		return (1);
	}
	core.win.ptr = mlx_new_window(core.win.mlx,
			core.win.width, core.win.height, "GAME");
	if (!core.win.ptr)
	{
		mlx_destroy_display(core.win.mlx);
		return (1);
	}
	if (!load_grass(&core) || !load_duck(&core) || !load_coin(&core))
	{
		free_window(&core);
		return (1);
	}
	mlx_loop_hook(core.win.mlx, game_loop, &core);
	render_map(core.map, &core);
	mlx_hook(core.win.ptr, KeyPress, KeyPressMask, &handle_keyboard, &core);
	mlx_loop(core.win.mlx);
	free_window(&core);
	return (0);
}
