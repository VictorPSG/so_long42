/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victda-s <victda-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:49:17 by victda-s          #+#    #+#             */
/*   Updated: 2024/12/11 16:21:35 by victda-s         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../include/main.h"

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix[i]);
	free(matrix);
	matrix = NULL;
}

static void set_win_size(t_core *core, int len, int i)
{
	core->win.height = i * 32;
	core->win.width = len * 32;
	core->map.cols = len;
	core->map.rows = i;
}

char	**map_matrix(char *file, t_core *core)
{
	char	**matrix;
	int		i;
	int		fd;
	int		len;

	i = 0;
	len = 0;
	fd = open_file(file);
	matrix = (char **)malloc(65 * sizeof(char *));
	if (!matrix)
		return (0);
	while (i < 65)
	{
		matrix[i] = get_next_line(fd);
		if (matrix[i] == NULL)
			break ;
		len = ft_strlen(matrix[i]);
		i++;
	}
	matrix[i] = NULL;
	set_win_size(core, len, i);
	close(fd);
	return (matrix);
}
