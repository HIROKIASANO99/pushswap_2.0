/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiasano <hiasano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:00:02 by hiasano           #+#    #+#             */
/*   Updated: 2024/04/24 18:33:05 by hiasano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		c = c + 32;
	return (c);
}

/*
#include <ctype.h>

int main ()
{
	char	c;
	char	lower;
	char	ft_lower;

	c = 'S';
	lower = tolower(c);
	ft_lower = ft_tolower(c);
	printf("honke=%c\n",lower);
	printf("ft=%c\n",ft_lower);
	return(0);
}
*/
