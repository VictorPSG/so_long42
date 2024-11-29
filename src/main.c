/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victda-s <victda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:55:37 by victda-s          #+#    #+#             */
/*   Updated: 2024/11/29 04:12:41 by victda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

int	main(void)
{
	t_core	core;

	core.win.mlx = mlx_init();
	if (!core.win.mlx)
		return (1);
	core.win.ptr = mlx_new_window(core.win.mlx, WIN_WIDTH, WIN_HEIGHT, "GAME");
	if (!core.win.ptr)
	{
		free(core.win.mlx);
		return (1);
	}
	if (!load_grass(&core))
		return (0);
	if (!core.grass.frames[0])
	{
		write(1, "erro", 4);
		return (0);
	}
	mlx_loop_hook(core.win.mlx, game_loop, &core);
	mlx_loop(core.win.mlx);
	free_window(&core);
}
