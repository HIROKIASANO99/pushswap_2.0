/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiasano <hiasano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:04:29 by hiasano           #+#    #+#             */
/*   Updated: 2024/04/24 18:33:11 by hiasano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (97 <= c && c <= 122)
		c = c - 32;
	return (c);
}

/*
#include <ctype.h>

int main ()
{
	char	c;
	char	upper;
	char	ft_upper;

	c = 's';
	upper = toupper(c);
	ft_upper = ft_toupper(c);
	printf("honke=%c\n",upper);
	printf("ft=%c\n",ft_upper);
	return(0);
}
*/
