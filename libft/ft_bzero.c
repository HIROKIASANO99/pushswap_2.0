/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiasano <hiasano@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 21:27:50 by hiasano           #+#    #+#             */
/*   Updated: 2024/05/17 15:53:27 by hiasano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = (char *)s;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
}
/*
#include <strings.h>

int	main(void)
{
	char	array[10] = "akoijo";
	char	array2[10] = "akoijo";

	printf("s=%s\n",array);
	printf("s=%s\n",array2);
	bzero(array, sizeof(array));
	ft_bzero(array2, sizeof(array2));
	printf("s2=%s\n",array);
	printf("s2=%s\n",array2);
}
*/
