/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiasano <hiasano@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:21:22 by hiasano           #+#    #+#             */
/*   Updated: 2024/05/24 18:20:50 by hiasano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ft_printf.h"

int	ft_convert_base(unsigned int num, char type, int *len)
{
	char	*toupper;
	char	*tolower;

	toupper = "0123456789ABCDEF";
	tolower = "0123456789abcdef";
	if (num < 16)
	{
		if (type == 'X')
			ft_putchar_fd(toupper[num % 16], 1);
		if (type == 'x')
			ft_putchar_fd(tolower[num % 16], 1);
		(*len)++;
		return (1);
	}
	ft_convert_base(num / 16, type, len);
	if (type == 'X')
		ft_putchar_fd(toupper[num % 16], 1);
	if (type == 'x')
		ft_putchar_fd(tolower[num % 16], 1);
	(*len)++;
	return (*len);
}
