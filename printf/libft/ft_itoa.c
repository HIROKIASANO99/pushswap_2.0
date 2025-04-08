/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiasano <hiasano@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 20:53:06 by hiasano           #+#    #+#             */
/*   Updated: 2024/05/23 21:13:22 by hiasano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static void	ft_input_result(int cnt_dgt, long num, char *result)
{
	while (cnt_dgt > 0)
	{
		result[cnt_dgt - 1] = num % 10 + '0';
		num = num / 10;
		cnt_dgt--;
	}
}

static int	ft_count_num(long num)
{
	int	cnt_dgt;

	cnt_dgt = 1;
	while (num >= 10)
	{
		num = num / 10;
		cnt_dgt++;
	}
	return (cnt_dgt);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		cnt_dgt;
	long	num;
	int		sign;

	num = n;
	sign = 1;
	cnt_dgt = 0;
	if (num < 0)
	{
		sign = sign * -1;
		num = num * -1;
		cnt_dgt++;
	}
	cnt_dgt += ft_count_num(num);
	result = malloc(sizeof(char) * (cnt_dgt + 1));
	if (!result)
		return (NULL);
	result[cnt_dgt] = '\0';
	ft_input_result(cnt_dgt, num, result);
	if (sign == -1)
		result[0] = '-';
	return (result);
}
