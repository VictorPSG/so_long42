/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victda-s <victda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 21:31:23 by victda-s          #+#    #+#             */
/*   Updated: 2024/12/12 00:37:58 by victda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

void	free_window(t_core *core)
{
	free_matrix(core->map.matrix);
	free_image(core->coin.frame, core);
	free_image(core->duck.frames, core);
	free_image(core->grass.frames, core);
	free_image(core->exit.frame, core);
	if (core->win.ptr)
		mlx_destroy_window(core->win.mlx, core->win.ptr);
	if (core->win.mlx)
	{
		mlx_destroy_display(core->win.mlx);
		free(core->win.mlx);
	}
}

void	free_image(void *frame[], t_core *core)
{
	int	i;

	if (frame != NULL)
	{
		i = 0;
		while (frame[i] != NULL)
		{
			mlx_destroy_image(core->win.mlx, frame[i]);
			frame[i] = NULL;
			i++;
		}
	}
}
