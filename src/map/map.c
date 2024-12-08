/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victda-s <victda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:49:17 by victda-s          #+#    #+#             */
/*   Updated: 2024/12/08 00:32:22 by victda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

char	**map_matrix(char *file, t_core *core)
{
	char 	**matrix;
	int 	i;
	int 	fd;

	i = 0;
	fd = open_file(file);
	matrix = (char **)malloc(100 * sizeof(char *));
	while(i < 24)
	{
		matrix[i] = get_next_line(fd);
		i++;
		if(matrix == NULL)
			break;
	}
	matrix[i] = NULL;
	core->win.height = i * 32;
	return (matrix);
}