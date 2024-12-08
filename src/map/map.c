/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victda-s <victda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:49:17 by victda-s          #+#    #+#             */
/*   Updated: 2024/12/08 01:44:41 by victda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

// static void free_matrix(char **matrix, int i) {
//     while (i < 65) {
//         if (matrix[i] != NULL) { // Verifica se o ponteiro não é NULL
//             free(matrix[i]);
//         }
//         i++;
//     }
// }
char	**map_matrix(char *file, t_core *core)
{
	char 	**matrix;
	int 	i;
	int 	fd;
	int		len;

	i = 0;
	len = 0;
	fd = open_file(file);
	matrix = (char **)malloc(65 * sizeof(char *));
	while(i < 65)
	{
		matrix[i] = get_next_line(fd);
		if(matrix[i] == NULL)
			break;
		len = ft_strlen(matrix[i]);
		i++;
	}
	matrix[i] = NULL;
	// free_matrix(matrix, 26);
	core->win.height = i * 32;
	core->win.width = len *32;
	return (matrix);
}
