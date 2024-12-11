/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victda-s <victda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 21:20:03 by victda-s          #+#    #+#             */
/*   Updated: 2024/12/11 04:08:49 by victda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

int	flood_fill(t_core *core, int x, int y)
{
	char	**map;
	int		rows;
	int		cols;

	rows = core->map.rows;
	cols = core->map.cols;
	map = core->map.map_verify;
	if (x < 0 || x >= rows || y < 0 || y >= cols)
		return (0);
	if (map[x][y] == '1' || map[x][y] == 'X')
		return (0);
	if (map[x][y] == 'C')
		core->map.coins++;
	if(map[x][y] == 'E')
		core->map.exit++;
	map[x][y] = 'X';
	flood_fill(core, x + 1, y);
	flood_fill(core, x - 1, y);
	flood_fill(core, x, y + 1);
	flood_fill(core, x, y - 1);
	return (core->map.coins);
}
