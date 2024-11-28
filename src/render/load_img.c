/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victda-s <victda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 00:35:49 by victda-s          #+#    #+#             */
/*   Updated: 2024/11/28 01:05:52 by victda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

int	load_img(t_window win, t_grass grass)
{
	char	*path[] = {
		"../../assets/texture/grass_middle.xpm",
		NULL
	};
	grass.frames[0] = mlx_xpm_file_to_image(win.mlx, &path[1], &grass.width, &grass.height);
}
