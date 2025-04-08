/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiasano <hiasano@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 18:44:39 by hiasano           #+#    #+#             */
/*   Updated: 2024/06/12 17:28:02 by hiasano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_putnbr_fd(int n, int fd, int *len)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		(*len) += 11;
		return (*len);
	}
	if (n < 0)
	{
		n = n * -1;
		if (ft_putchar_fd('-', fd) == -1)
			return (-1);
		(*len)++;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd, len);
	if (ft_putchar_fd((n % 10 + '0'), fd) == -1)
		return (-1);
	(*len)++;
	return (*len);
}
