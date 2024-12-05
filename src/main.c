/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victda-s <victda-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:55:37 by victda-s          #+#    #+#             */
/*   Updated: 2024/12/05 14:47:00 by victda-s         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/main.h"

int	main(void)
{
	t_core	core;

	// core.map = map_matrix();
	core.win.mlx = mlx_init();
	if (!core.win.mlx)
		return (1);
	core.win.ptr = mlx_new_window(core.win.mlx, WIN_WIDTH, WIN_HEIGHT, "GAME");
	if (!core.win.ptr)
	{
		mlx_destroy_display(core.win.mlx);
		return (1);
	}
	if (!load_grass(&core) || !load_duck(&core) || !load_coin(&core))
		return (0);
	mlx_loop_hook(core.win.mlx, game_loop, &core);
	core.map = map_matrix();
	corner_render(&core);
	render_map(core.map, &core);
	mlx_hook(core.win.ptr, KeyPress, KeyPressMask, &handle_keyboard, &core);
	mlx_loop(core.win.mlx);
	free_window(&core);
}
