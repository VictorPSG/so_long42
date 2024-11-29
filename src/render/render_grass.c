/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_grass.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victda-s <victda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 02:44:37 by victda-s          #+#    #+#             */
/*   Updated: 2024/11/29 04:13:03 by victda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

int	load_grass(t_core *core)
{
	char	*path[7];

	path[0] = "assets/texture/grass_left_down.xpm";
	path[1] = "assets/texture/grass_left_up.xpm";
	path[2] = "assets/texture/grass_middle_up.xpm";
	path[3] = "assets/texture/grass_middle.xpm";
	path[4] = "assets/texture/grass_right_down.xpm";
	path[5] = "assets/texture/grass_right_up.xpm";
	path[6] = NULL;
	return (load_img(path, core->grass.frames, core));
}
