/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victda-s <victda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:55:37 by victda-s          #+#    #+#             */
/*   Updated: 2024/12/11 03:23:46 by victda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"
#include <stdio.h>

static void	init_structs(t_core *core)
{
	core->coin.total = 0;
	core->coin.collected = 0;
	core->map.exit = 0;
	core->map.coins = 0;
	core->map.player = 0;
	core->map.char_inv = 0;
	core->map.matrix = map_matrix("src/map/map.ber", core);
	core->map.map_verify = map_matrix("src/map/map.ber", core);
}
int	main(void)
{
	t_core	core;

	init_structs(&core);
	if(map_verify(&core))
	{
		free_matrix(core.map.matrix);
		free_matrix(core.map.map_verify);
		return (0);
	}
	core.win.mlx = mlx_init();
	if (!core.win.mlx)
	{
		return (1);
	}
	core.win.ptr = mlx_new_window(core.win.mlx, core.win.width, core.win.height,
			"GAME");
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
	render_map(core.map.matrix, &core);
	mlx_hook(core.win.ptr, KeyPress, KeyPressMask, &handle_keyboard, &core);
	mlx_loop(core.win.mlx);
	free_window(&core);
	return (0);
}
