/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiasano <hiasano@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 19:27:45 by hiasano           #+#    #+#             */
/*   Updated: 2024/06/12 17:11:10 by hiasano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ft_printf.h"

int	ft_print_address(unsigned long long address, int *len)
{
	char	*tolower;

	tolower = "0123456789abcdef";
	if (address < 16)
	{
		if (ft_putchar_fd(tolower[address % 16], 1) == -1)
			return (-1);
		(*len)++;
		return (*len);
	}
	ft_print_address(address / 16, len);
	ft_putchar_fd(tolower[address % 16], 1);
	(*len)++;
	return (*len);
}
