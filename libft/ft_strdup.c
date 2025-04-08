/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiasano <hiasano@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:41:32 by hiasano           #+#    #+#             */
/*   Updated: 2024/04/27 18:07:42 by hiasano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;
	int		i;

	i = 0;
	while (s1[i])
	{
		i++;
	}
	copy = malloc(i + 1);
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

/*
#include <string.h>

int	main(void) {
	const char *original = "Hello, world!";
	const char *original2 = "Hello, world!";
	char *copy = strdup(original);
	char *copy2 = ft_strdup(original2);

	if (copy == NULL)
	{
		fprintf(stderr, "Failed to allocate memory.\n");
		return (1);
	}

	if (copy2 == NULL)
	{
		fprintf(stderr, "2Failed to allocate memory.\n");
		return (1);
	}

	printf("Original: %s\n", original);
	printf("Copy: %s\n", copy);

	printf("Original2: %s\n", original2);
	printf("Copy2: %s\n", copy2);
	free(copy);
	free(copy2);
	return (0);
}
*/
