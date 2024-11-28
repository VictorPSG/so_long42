/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victda-s <victda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:55:37 by victda-s          #+#    #+#             */
/*   Updated: 2024/11/27 22:57:15 by victda-s         ###   ########.fr       */
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
	mlx_loop_hook(core.win.mlx, game_loop, &core);
	free_window(&core);
}
