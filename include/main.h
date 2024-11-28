/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victda-s <victda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 20:01:28 by victda-s          #+#    #+#             */
/*   Updated: 2024/11/28 01:06:23 by victda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include <unistd.h>
# define WIN_WIDTH 1800
# define WIN_HEIGHT 900

typedef struct s_window
{
	void	*mlx;
	void	*ptr;
	int		bpp;
}			t_window;

typedef struct s_grass
{
	void	*frames[6];
	int		width;
	int		height;
}			t_grass;

typedef struct s_core
{
	t_window	win;
	t_grass		grass;
}			t_core;
int		game_loop(t_core *core);
void	free_window(t_core *core);
int		load_img(t_window win, t_grass grass);
#endif
