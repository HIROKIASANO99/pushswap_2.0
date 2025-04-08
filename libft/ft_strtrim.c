/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiasano <hiasano@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 22:09:27 by hiasano           #+#    #+#             */
/*   Updated: 2024/05/17 16:18:41 by hiasano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*end;
	char	*start;
	size_t	set_size;
	char	*result_len;

	if (!s1)
		return (NULL);
	start = (char *)s1;
	end = start + ft_strlen(s1);
	while (*start && ft_strchr(set, *start))
		start++;
	while (end > start && ft_strchr(set, *(end - 1)))
		end--;
	set_size = end - start;
	result_len = malloc(set_size + 1);
	if (!result_len)
		return (NULL);
	ft_strlcpy(result_len, start, set_size + 1);
	return (result_len);
}
