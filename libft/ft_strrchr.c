/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiasano <hiasano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:29:54 by hiasano           #+#    #+#             */
/*   Updated: 2024/05/11 03:25:02 by hiasano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	const char	*mark;

	c = (unsigned char)c;
	i = 0;
	mark = NULL;
	while (s[i])
	{
		if ((unsigned char)s[i] == c)
			mark = s + i;
		i++;
	}
	if (c == '\0')
		mark = s + i;
	return ((char *)mark);
}

/*
// strrchr(s, 'l' + 256)
#include <string.h>

int	main(void) {
	const char *str = "hello world";
	char *result;
	char *result2;

	result = strrchr(str, 'l'  + 256);

	if (result != NULL)
	{
		printf(" 'l' %s\n", result);
	}
	else
	{
		printf("'l' \n");
	}


	result2 = strrchr(str, 'l' + 256);
	if (result2 != NULL)
	{
		printf(" %s\n", result2);
	}
	else
	{
		printf("2'l' \n");
	}
	return (0);
}
*/
