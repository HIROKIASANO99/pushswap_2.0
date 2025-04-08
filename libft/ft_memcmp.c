/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiasano <hiasano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:19:26 by hiasano           #+#    #+#             */
/*   Updated: 2024/04/25 01:55:54 by hiasano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (n > i)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

/*
#include <string.h>

int	main(void) {
	char str1[] = "abcDef";
	char str2[] = "abcdeg";

	int result = memcmp(str1, str2, sizeof(str1));
	int result2 = ft_memcmp(str1, str2, sizeof(str1));

	if (result == 0)
	{
		printf("The strings are identical.\n");
	}
	else if (result < 0)
	{
		printf("The first string is less than the second string.\n");
	}
	else
	{
		printf("The first string is greater than the second string.\n");
	}

	if (result2 == 0)
	{
		printf("2The strings are identical.\n");
	}
	else if (result2 < 0)
	{
		printf("2The first string is less than the second string.\n");
	}
	else
	{
		printf("2The first string is greater than the second string.\n");
	}
	return (0);
}
*/
