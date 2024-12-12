/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victda-s <victda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:55:37 by victda-s          #+#    #+#             */
/*   Updated: 2024/12/11 22:38:46 by victda-s         ###   ########.fr       */
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
	core->duck.countMov = 0;
	core->win.mlx = mlx_init();
	core->map.matrix = map_matrix("src/map/map2.ber", core);
	core->map.map_verify = map_matrix("src/map/map2.ber", core);
}
static int	init_funcs(t_core *core)
{
	if(map_verify(core))
	{
		free_matrix(core->map.matrix);
		free_matrix(core->map.map_verify);
		mlx_destroy_display(core->win.mlx);
		free(core->win.mlx);
		return (1);
	}
	core->win.ptr = mlx_new_window(core->win.mlx, core->win.width, core->win.height,
		"So_long.42");
	if (!core->win.ptr)
	{
		mlx_destroy_display(core->win.mlx);
		return (1);
	}
	if (!load_grass(core) || !load_duck(core) || !load_coin(core))
	{
		free_window(core);
		return (1);
	}
	return (0);
}

int	main(void)
{
	t_core	core;

	if(open_file("src/map/map2.ber") == -1)
		return (0);
	init_structs(&core);
	if(init_funcs(&core))
		return (0);
	if (!core.win.mlx)
	{
		free_matrix(core.map.matrix);
		return (1);
	}
	mlx_loop_hook(core.win.mlx, game_loop, &core);
	render_map(core.map.matrix, &core);
	mlx_hook(core.win.ptr, 17, 0, (int (*)(void *))close_window, &core);
	mlx_hook(core.win.ptr, KeyPress, KeyPressMask, &handle_keyboard, &core);
	mlx_loop(core.win.mlx);
	return (0);
}
