/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiasano <hiasano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 20:07:23 by hiasano           #+#    #+#             */
/*   Updated: 2024/05/11 03:26:51 by hiasano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	const char		*mark;
	unsigned char	uc;

	uc = (unsigned char)c;
	i = 0;
	mark = NULL;
	while (s[i])
	{
		if ((unsigned char)s[i] == uc)
		{
			mark = s + i;
			return ((char *)mark);
		}
		i++;
	}
	if (uc == '\0')
		return ((char *)s + i);
	return ((char *)mark);
}

/*
#include <string.h>

int	main(void) {
	const char *str = "hello world";
	char *result;
	char *result2;

	result = strchr(str, '\0');

	if (result != NULL)
	{
		printf(", result);
	}
	else
	{
		printf("'l' \n");
	}


	result2 = strchr(str, '\0');
	if (result2 != NULL)
	{
		printf("", result2);
	}
	else
	{
		printf(l' \n");
	}
	return (0);
}
*/
