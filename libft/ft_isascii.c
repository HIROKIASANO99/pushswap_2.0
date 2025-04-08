/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiasano <hiasano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 21:56:15 by hiasano           #+#    #+#             */
/*   Updated: 2024/04/29 23:44:12 by hiasano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return (0 <= c && c <= 127);
}

/*
int	main(void)
{
	char	c;

	c = 'j';
	if(ft_isascii(c))
		printf("ok\n");
	else
		printf("NG\n");
	return(0);
}
*/
