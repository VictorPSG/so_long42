/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verify.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victda-s <victda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 23:56:54 by victda-s          #+#    #+#             */
/*   Updated: 2024/12/12 19:56:18 by victda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

static int	corner_check(t_core *core)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (core->map.cols > col)
	{
		if (core->map.map_verify[0][col] != '1')
			return (1);
		if (core->map.map_verify[core->map.rows - 1][col] != '1')
			return (1);
		col++;
	}
	while (core->map.rows > row)
	{
		if (core->map.map_verify[row][0] != '1')
			return (1);
		if (core->map.map_verify[row][core->map.cols - 1] != '1')
			return (1);
		row++;
	}
	return (0);
}

static int	row_verify(t_core *core)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (core->map.map_verify[i + 1])
	{
		if (core->map.cols != (int)ft_strlen(core->map.map_verify[i]) - 1)
			count++;
		if (ft_strlen(core->map.map_verify[i]) != ft_strlen
			(core->map.map_verify[i + 1]))
			count++;
		i++;
	}
	if (count > 1)
		return (1);
	if (corner_check(core))
		return (1);
	return (0);
}

static int	is_map_valid(t_core *core)
{
	core->map.exit = 0;
	if (flood_fill(core, core->duck.pos_y / 32, core->duck.pos_x
			/ 32) != core->coin.total || core->map.exit != 1)
		return (1);
	if (core->coin.total == 0)
		return (1);
	if (row_verify(core))
		return (1);
	return (0);
}

int	map_verify(t_core *core)
{
	map_read(core->map.map_verify, core);
	if (core->map.player != 1)
	{
		write(1, "Error!\nNumero de players invaldo!\n", 34);
		return (1);
	}
	if (core->map.exit != 1)
	{
		write(1, "Error!\nNumero de saidas invaldo!\n", 33);
		return (1);
	}
	if (core->map.char_inv != 0)
	{
		write(1, "Error!\nCharactere invalido!\n", 28);
		return (1);
	}
	if (is_map_valid(core))
	{
		write(1, "Error!\nMapa invalido!\n", 22);
		return (1);
	}
	free_matrix(core->map.map_verify);
	return (0);
}
