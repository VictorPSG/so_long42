/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victda-s <victda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:33:30 by victda-s          #+#    #+#             */
/*   Updated: 2024/12/08 21:38:15 by victda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"
#include <stdio.h>

void	render_map(char **map, t_core *core)
{
	int	col;
	int	line;

	col = 0;
	line = 0;
	while (map[line])
	{
		if (map[line][col] == 48)
			grass_render(core, 5, col * 32, line * 32);
		else if (map[line][col] == 49)
			grass_render(core, 10, col * 32, line * 32);
		else if (map[line][col] == 'P')
		{
			core->duck.pos_x = col * 32;
			core->duck.pos_y = line * 32;
		}
		else if (map[line][col] == 'C')
		{
			coin_render(core, 0, col * 32, line * 32);
			core->coin.total++;
		}
		col++;
		if (col == core->win.width / 32)
		{
			col = 0;
			line++;
		}
	}
}
