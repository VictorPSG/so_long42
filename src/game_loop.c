/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victda-s <victda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 21:31:16 by victda-s          #+#    #+#             */
/*   Updated: 2024/11/30 22:32:37 by victda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"
#include "../include/test.h"

int	game_loop(t_core *core)
{
	int	i;

	i = 0;
	corner_render(core);
	test_render_background(core);
	return (0);
}
