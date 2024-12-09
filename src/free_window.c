/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victda-s <victda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 21:31:23 by victda-s          #+#    #+#             */
/*   Updated: 2024/12/09 20:25:21 by victda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

void	free_window(t_core *core)
{
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
	while (frame)
	{
		mlx_destroy_image(core->win.mlx, frame);
		frame = NULL;
	}
}
