/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victda-s <victda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:33:30 by victda-s          #+#    #+#             */
/*   Updated: 2024/12/10 23:52:46 by victda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"
#include <stdio.h>

static void	wall_or_grass(char **map, t_core *core, int line, int col)
{
	if (map[line][col] == 48)
		grass_render(core, 5, col * 32, line * 32);
	else if (map[line][col] == 49)
		grass_render(core, 9, col * 32, line * 32);
}

void	render_map(char **map, t_core *core)
{
	int	col;
	int	line;

	col = 0;
	line = 0;
	while (map[line])
	{
		wall_or_grass(map, core, line, col);
		if (map[line][col] == 'P')
		{
			core->duck.pos_x = col * 32;
			core->duck.pos_y = line * 32;
		}
		else if (map[line][col] == 'C')
			coin_render(core, 0, col * 32, line * 32);
		col++;
		if (col == core->win.width / 32)
		{
			col = 0;
			line++;
		}
	}
}
