/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiasano <hiasano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 15:57:35 by hiasano           #+#    #+#             */
/*   Updated: 2024/05/17 15:57:29 by hiasano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_cdest_while(size_t n, char *cdest, const char *csrc)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		cdest[i] = csrc[i];
		i++;
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*cdest;
	const char	*csrc;

	if (dest == src)
		return (dest);
	cdest = (char *)dest;
	csrc = (const char *)src;
	if (cdest > csrc && cdest < csrc + n)
	{
		while (n > 0)
		{
			cdest[n - 1] = csrc[n - 1];
			n--;
		}
		return (dest);
	}
	else
		ft_cdest_while(n, cdest, csrc);
	return (dest);
}

/*
#include <string.h>

int	main(void)
{
	char	text[] = "Hello, world!";
	char	text2[] = "Hello, world!";

	memmove(text + 7 , text + 7 - 2, 6);
	ft_memmove(text2 + 7 , text2 + 7 - 2, 6);
	printf("Result: %s\n", text); // Result: Hello, , worl
	printf("Result2: %s\n", text2); // Result: Hello, , worl
	return (0);
}
*/
