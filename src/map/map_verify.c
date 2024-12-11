/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verify.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victda-s <victda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 23:56:54 by victda-s          #+#    #+#             */
/*   Updated: 2024/12/11 03:53:44 by victda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

int	map_verify(t_core *core)
{
	map_read(core->map.map_verify, core);
	if(core->map.player != 1)
	{
		write(1, "Error!\nNumero de players invaldo!", 33);
		return (1);
	}
	if(core->map.exit != 1)
	{
		write(1, "Error!\nNumero de saidas invaldo!", 32);
		return (1);
	}
	core->map.exit = 0;
	if (flood_fill(core, core->duck.pos_y / 32, core->duck.pos_x
			/ 32) != core->coin.total || core->map.exit != 1)
	{
		write(1, "Error!\nMapa invalido!", 21);
		return (1);
	}
	if (core->map.char_inv != 0)
	{
		write(1, "Error!\nCharactere invalido!", 26);
		return (1);
	}
	free_matrix(core->map.map_verify);
	return (0);
}


	// printf("players:%d\n", core->map.player);
	// printf("exits:%d\n", core->map.exit);
	// printf("coins:%d\n", core->map.coins);
