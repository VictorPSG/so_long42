/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victda-s <victda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 20:01:28 by victda-s          #+#    #+#             */
/*   Updated: 2024/12/03 00:16:02 by victda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include <unistd.h>
# define WIN_WIDTH 1792
# define WIN_HEIGHT 896

typedef struct s_window
{
	void	*mlx;
	void	*ptr;
	int		bpp;
}			t_window;

typedef struct s_grass
{
	void	*frames[12];
	int		width;
	int		height;
}			t_grass;

typedef struct s_duck
{
	void	*frames[10];
	int		pos_x;
	int		pos_y;
}			t_duck;
typedef struct s_map
{
	char	**matrix;
	int		line;
	int		col;
}			t_map;

typedef struct s_core
{
	t_window	win;
	t_grass		grass;
	t_duck		duck;
	t_map		map;
}			t_core;
int		game_loop(t_core *core);
void	free_window(t_core *core);
int		load_img(char *path[], void *frame[], t_core *core);
int		load_grass(t_core *core);
void	grass_render(t_core *core, int i, int x, int y);
void	corner_render(t_core *core);
char	**map_matrix();
int		handle_keyboard(int keysym, t_core *core);
void	duck_render(t_core *core, int i, int x, int y);
int		load_duck(t_core *core);
#endif
