/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiasano <hiasano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:28:48 by hiasano           #+#    #+#             */
/*   Updated: 2024/05/07 22:52:04 by hiasano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	src[] = "1234567890";
	int		dstsize;
	char	dest[dstsize];
	char	dest2[dstsize];
	int		length;
	int		length2;

	dstsize = 40;
	length = strlcpy(dest, src, dstsize);
	printf("dst =%s,len =%d\n",dest, length);
	length2 = ft_strlcpy(dest2, src, dstsize);
	printf("dst2=%s,len2=%d\n",dest, length2);
}
*/
