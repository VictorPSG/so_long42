/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victda-s <victda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:55:37 by victda-s          #+#    #+#             */
/*   Updated: 2024/12/12 01:42:29 by victda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"
#include <stdio.h>

static int file_ber(char *file[])
{
	int		i;
	int		len;
	int		len2;
	char	*ber = ".ber";

	i = 0;
	len2 = 3;
	len = ft_strlen(file[1]) - 1;
	while (i < 4)
	{
		if(file[1][len--] != ber[len2--])
		{
			ft_putstr_fd("Error!\nFormato de arquivo invalido!\n", 1);
			return (1);
		}
		i++;
	}
	return (0);
}
static void	init_structs(t_core *core, char *argv[])
{
	core->coin.total = 0;
	core->coin.collected = 0;
	core->map.exit = 0;
	core->map.coins = 0;
	core->map.player = 0;
	core->map.char_inv = 0;
	core->duck.count_mov = 0;
	core->win.mlx = mlx_init();
	core->map.matrix = map_matrix(argv[1], core);
	core->map.map_verify = map_matrix(argv[1], core);
}

static int	init_funcs(t_core *core)
{
	if (map_verify(core))
	{
		free_matrix(core->map.matrix);
		free_matrix(core->map.map_verify);
		mlx_destroy_display(core->win.mlx);
		free(core->win.mlx);
		return (1);
	}
	core->win.ptr = mlx_new_window(core->win.mlx, core->win.width,
			core->win.height, "So_long.42");
	if (!core->win.ptr)
	{
		mlx_destroy_display(core->win.mlx);
		return (1);
	}
	if (!load_grass(core) || !load_duck(core) || !load_coin(core) ||
		!load_exit(core))
	{
		free_window(core);
		free_matrix(core->map.matrix);
		return (1);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_core	core;

	if (argc != 2)
	{
		ft_putstr_fd("Error!\nNúmeros de argumentos inválido!", 1);
		return (0);
	}
	if (open_file(argv[1]) == -1 || file_ber(argv))
		return (0);
	init_structs(&core, argv);
	if (init_funcs(&core))
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
