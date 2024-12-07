/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victda-s <victda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:25:03 by victda-s          #+#    #+#             */
/*   Updated: 2024/12/06 22:21:07 by victda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	c = (unsigned char)c;
	i = -1;
	while (s[++i])
	{
		if (s[i] == c)
			return ((char *)&s[i]);
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
/*
int	main(void) {
	char str[] = "bonjor";
	char *ptr;

	// Procurando a primeira ocorrência da letra 'W'
	ptr = ft_strchr(str, '\0');

	if (ptr != NULL) {
		printf("A primeira ocorrência de 'W' está em: %s\n", ptr);
	} else {
		printf("'W' não encontrado na string.\n");
	}

	return (0);
}
*/