/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victda-s <victda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:33:30 by victda-s          #+#    #+#             */
/*   Updated: 2024/12/11 20:42:06 by victda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

static void	wall_or_grass(char **map, t_core *core, int row, int col)
{
	if (map[row][col] == 48)
		grass_render(core, 5, col * 32, row * 32);
	else if (map[row][col] == 49)
		grass_render(core, 9, col * 32, row * 32);
}

void	render_map(char **map, t_core *core)
{
	int	col;
	int	row;

	col = 0;
	row = 0;
	while (map[row])
	{
		wall_or_grass(map, core, row, col);
		if (map[row][col] == 'P')
		{
			core->duck.pos_x = col * 32;
			core->duck.pos_y = row * 32;
		}
		else if (map[row][col] == 'C')
			coin_render(core, 0, col * 32, row * 32);
		col++;
		if (col == core->win.width / 32)
		{
			col = 0;
			row++;
		}
	}
}
