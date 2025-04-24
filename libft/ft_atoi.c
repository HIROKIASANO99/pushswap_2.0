/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiasano <hiasano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:30:10 by hiasano           #+#    #+#             */
/*   Updated: 2025/04/24 20:48:20 by hiasano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi_safe(const char *str, int *out)
{
	long long	num;
	int			sign;
	int			i;

	if (!str || !out)
		return (-1);
	num = 0;
	sign = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i++] - '0');
		if (num * sign > INT_MAX || num * sign < INT_MIN)
			return (-1);
	}
	if (str[i] != '\0')
		return (-1);
	*out = (int)(num * sign);
	return (0);
}

