/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiasano <hiasano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 20:41:13 by hiasano           #+#    #+#             */
/*   Updated: 2025/04/14 19:09:34 by hiasano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/push_swap.h"

int	ft_check_digit(char *str)
{
	int i;
	// int err;
	i = 0;
	if (str[i] == '-')
	{
		if((str[i + 1] == '0')||(str[i + 1] == '\0'))
			return(1);
		i++;
	}
	if(str[i] == '0' && str[i + 1] >= '0' && str[i + 1]  <= '9')
		return(1);
	while (str[i] != '\0')
	{
		if(str[i] < '0' || str[i] > '9')
			return(1);
		i++;
	}
	return(0);
}