/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiasano <hiasano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 20:49:02 by hiasano           #+#    #+#             */
/*   Updated: 2024/05/17 15:59:33 by hiasano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		comp;
	size_t	i;

	comp = 0;
	i = 0;
	while ((s1[i] || s2[i]) && n > i)
	{
		if (s1[i] != s2[i])
		{
			comp = (unsigned char)s1[i] - (unsigned char)s2[i];
			return (comp);
		}
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void) {
	const char *str1 = '\0';
	const char *str2 = '\0';
	size_t i = 5;

	int result = strncmp(str1, str2, i);
	int result2 = ft_strncmp(str1, str2, i);
	printf(" %d\n", result);
	printf(%d\n", result2);

	return (0);
}
*/
