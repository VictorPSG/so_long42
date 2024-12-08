/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victda-s <victda-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 00:05:39 by victda-s          #+#    #+#             */
/*   Updated: 2024/12/08 16:57:58 by victda-s         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../include/main.h"

int	open_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		write(1, "Erro ao abrir o arquivo!\n", 25);
		return (1);
	}
	return (fd);
}
