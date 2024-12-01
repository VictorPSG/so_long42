/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corner_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victda-s <victda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 20:13:36 by victda-s          #+#    #+#             */
/*   Updated: 2024/11/30 22:18:41 by victda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

void	corner_render(t_core *core)
{
	int	i;

	i = 32;
	grass_render(core, 0, 0, 0);
	grass_render(core, 1, 1760, 0);
	grass_render(core, 4, 0, 864);
	grass_render(core, 7, 1760, 864);
	while (i < 1760)
	{
		grass_render(core, 2, i, 0);
		grass_render(core, 8, i, 864);
		grass_render(core, 5, i, 832);
		grass_render(core, 5, i, 32);
		i += 32;
	}
	i = 32;
	while (i < 850)
	{
		grass_render(core, 3, 1760, i);
		grass_render(core, 9, 0, i);
		grass_render(core, 5, 1728, i);
		grass_render(core, 5, 32, i);
		i += 32;
	}
}
