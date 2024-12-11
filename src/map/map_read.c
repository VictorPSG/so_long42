/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victda-s <victda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 23:30:06 by victda-s          #+#    #+#             */
/*   Updated: 2024/12/11 03:33:05 by victda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

void	map_read(char **map, t_core *core)
{
	int	col;
	int	line;

	col = 0;
	line = 0;
	while (map[line])
	{
		if (map[line][col] == 'P')
		{
			core->duck.pos_x = col * 32;
			core->duck.pos_y = line * 32;
			core->map.player++;
		}
		else if (map[line][col] == 'C')
			core->coin.total++;
		else if(map[line][col] == 'E')
		{
			core->map.exit++;
		}
		else if(map[line][col] != '1' && map[line][col] != '0')
			core->map.char_inv++;
		col++;
		if (col == core->win.width / 32)
		{
			col = 0;
			line++;
		}
	}
}
