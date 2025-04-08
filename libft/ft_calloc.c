/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiasano <hiasano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 04:37:34 by hiasano           #+#    #+#             */
/*   Updated: 2024/05/18 17:24:42 by hiasano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_size;
	void	*memory;
	size_t	i;
	char	*c_memory;

	i = 0;
	total_size = count * size;
	if (count != 0 && total_size / count != size)
		return (NULL);
	memory = malloc(total_size);
	if (memory == NULL)
		return (NULL);
	c_memory = (char *)memory;
	while (total_size > i)
	{
		c_memory[i] = 0;
		i++;
	}
	return (memory);
}

// int	main(void)
// {
// 	size_t	num_elements;
// 	int		*array_calloc;
// 	int		*array_ft_calloc;

// 	num_elements = 10;
// 	array_calloc = calloc(num_elements, sizeof(int));
// 	array_ft_calloc = ft_calloc(num_elements, sizeof(int));
// 	if (array_calloc == NULL || array_ft_calloc == NULL)
// 	{
// 		fprintf(stderr, "Memory allocation failed\n");
// 		free(array_calloc);
// 		free(array_ft_calloc);
// 		return (1);
// 	}
// 	for (size_t i = 0; i < num_elements; i++) {
// 		if (array_calloc[i] != 0 || array_ft_calloc[i] != 0) {
// 			fprintf(stderr, "Memory not properly initialized to zero\n");
// 			free(array_calloc);
// 			free(array_ft_calloc);
// 			return (1);
// 		}
// 	}
// 	printf("Both calloc and ft_calloc successfully 
// allocated and initialized memory to zero.\n");
// 	free(array_calloc);
// 	free(array_ft_calloc);
// 	return (0);
// }
