/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiasano <hiasano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:12:57 by hiasano           #+#    #+#             */
/*   Updated: 2024/05/17 15:56:46 by hiasano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	i = 0;
	if (dst == src)
		return (dst);
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
/*

#include <string.h>

int	main(void)
{
	char	src[] = "test basic du memcpy !";
	size_t	n;
	char	dest[100];
	char	dest2[100];

	n = 5;
	memcpy(dest, src, n);
	ft_memcpy(dest2, src, n);
	dest[n] = '\0';
	dest2[n] = '\0';
	printf("Copied string: %s\n", dest);
	printf("Copied string2: %s\n", dest2);
	return (0);
}
*/
