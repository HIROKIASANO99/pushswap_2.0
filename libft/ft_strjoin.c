/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiasano <hiasano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 19:42:46 by hiasano           #+#    #+#             */
/*   Updated: 2024/05/11 03:04:06 by hiasano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_write_to_memory(char *total_len, char *str, size_t p)
{
	int	i;

	i = 0;
	while (str[i])
	{
		total_len[i + p] = str[i];
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*total_len;
	size_t	i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	total_len = malloc(s1_len + s2_len + 1);
	if (!total_len)
		return (NULL);
	i = ft_write_to_memory(total_len, (char *)s1, 0);
	i += ft_write_to_memory(total_len, (char *)s2, i);
	total_len[i] = '\0';
	return (total_len);
}
