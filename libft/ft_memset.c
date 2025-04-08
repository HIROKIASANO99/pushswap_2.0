/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiasano <hiasano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:28:58 by hiasano           #+#    #+#             */
/*   Updated: 2024/05/27 19:12:09 by hiasano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buf, int ch, size_t n)
{
	size_t	i;
	unsigned char	*buffer;

	i = 0;
	buffer = (unsigned char *)buf;
	while (i < n)
	{
		buffer[i] = (unsigned char)ch;
		i++;
	}
	return (buf);
}
