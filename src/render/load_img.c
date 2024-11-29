/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victda-s <victda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 00:35:49 by victda-s          #+#    #+#             */
/*   Updated: 2024/11/29 04:02:48 by victda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

int	load_img(char *path[], void *frame[], t_core *core)
{
	int	i;

	i = 0;
	while (path[i] != NULL)
	{
		frame[i] = mlx_xpm_file_to_image(core->win.mlx, path[i],
				&core->grass.width, &core->grass.height);
		if (!frame[i])
		{
			write(1, "Erro ao carregar a imagem!", 26);
			return (0);
		}
		i++;
	}
	return (1);
}
