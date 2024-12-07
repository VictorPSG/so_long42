/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victda-s <victda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:33:30 by victda-s          #+#    #+#             */
/*   Updated: 2024/12/07 01:06:19 by victda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"
#include <stdio.h>

void	render_map(char **map, t_core *core)
{
	int	col;
	int	line;

	col = 2;
	line = 2;
	while (map[line - 2][col - 2])
	{
		if (map[line - 2][col - 2] == 48)
			grass_render(core, 5, col * 32, line * 32);
		else if (map[line - 2][col - 2] == 49)
			grass_render(core, 10, col * 32, line * 32);
		else if (map[line - 2][col - 2] == 'P')
		{
			core->duck.pos_x = col * 32;
			core->duck.pos_y = line * 32;
		}
		else if (map[line - 2][col - 2] == 'C')
		{
			coin_render(core, 0, col * 32, line * 32);
			core->coin.total++;
		}
		col++;
		if (col == 55)
		{
			col = 2;
			line++;
		}
	}
}
