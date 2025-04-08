/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiasano <hiasano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 22:53:22 by hiasano           #+#    #+#             */
/*   Updated: 2024/05/11 03:24:12 by hiasano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	j;

	dst_len = 0;
	src_len = 0;
	j = 0;
	while (src[src_len])
		src_len++;
	if (dstsize == 0)
		return (src_len);
	while (dst[dst_len] && dstsize > dst_len)
		dst_len++;
	if (dstsize > dst_len)
	{
		while (src[j] && (dst_len + j < dstsize - 1))
		{
			dst[dst_len + j] = src[j];
			j++;
		}
		dst[dst_len + j] = '\0';
	}
	return (dst_len + src_len);
}
/*
#include <string.h>

int	main(void) {
	char dest[20] = "Hello, ";
	char dest2[20] = "Hello, ";
	const char *src = "world!";
	size_t buf_size = sizeof(dest); 
	strlcat(dest, src, buf_size);
	ft_strlcat(dest2, src, buf_size);
	printf("%s\n", dest); // "Hello, world!"
	printf("%s\n", dest2); // "Hello, world!"
	return (0);
}
*/
