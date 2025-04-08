/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiasano <hiasano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:20:54 by hiasano           #+#    #+#             */
/*   Updated: 2024/04/25 01:03:40 by hiasano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (n > i)
	{
		if (str[i] == (unsigned char)c)
			return ((void *)str + i);
		i++;
	}
	return (0);
}

/*
#include <string.h>

int	main(void)
{
	const char	str[] = "example.com";
	char		ch;
	char		*result;
	char		*result2;

	ch = '.';
	result = memchr(str, ch, strlen(str));
	result2 = ft_memchr(str, ch, strlen(str));
	if (result != NULL)
	{
		printf("The character %c is found at position: %ld\n", ch, (result
				- str));
	}
	else
	{
		printf("The character %c was not found within the first
			%lu characters.\n", ch, strlen(str));
	}
	if (result2 != NULL)
	{
		printf("The character %c is found at position: %ld\n", ch, (result2
				- str));
	}
	else
	{
		printf("The character %c was not found within the first
			%lu characters.\n", ch, strlen(str));
	}
	return (0);
}
*/
