/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victda-s <victda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 21:31:16 by victda-s          #+#    #+#             */
/*   Updated: 2024/12/08 21:29:37 by victda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"
#include <stdio.h>

int	game_loop(t_core *core)
{
	duck_render(core, 0, core->duck.pos_x, core->duck.pos_y);
	return (0);
}
