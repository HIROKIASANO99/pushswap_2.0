/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiasano <hiasano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:10:41 by hiasano           #+#    #+#             */
/*   Updated: 2024/05/17 15:58:38 by hiasano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[i] && len > i)
	{
		while (haystack[i + j] == needle[j] && (i + j) < len)
		{
			if (needle[j + 1] == '\0')
				return ((char *)haystack + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

/*
#include <string.h>

int	main(void)
{
	const char	*longString = "asanohiroki";
	const char	*shortString = "hiro";
	size_t		i;
	char		*result;
	char		*result2;

	i = 6;
	result = strnstr(longString, shortString, i);
	result2 = ft_strnstr(longString, shortString, i);
	if (result)
	{
		printf("Found: %s\n", result);
	}
	else
	{
		printf("Not found within the first %ld characters.\n",i);
	}
	if (result2)
	{
		printf("Found2: %s\n", result2);
	}
	else
	{
		printf("Not found2 within the first %ld characters.\n",i );
	}
	return (0);
}
*/
