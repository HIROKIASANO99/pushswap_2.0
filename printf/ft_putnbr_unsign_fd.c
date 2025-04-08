/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsign_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiasano <hiasano@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 23:52:16 by hiasano           #+#    #+#             */
/*   Updated: 2024/05/25 23:57:07 by hiasano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ft_printf.h"

int	ft_putnbr_unsign_fd(unsigned int n, int fd, int *len)
{
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd, len);
	ft_putchar_fd((n % 10 + '0'), fd);
	(*len)++;
	return (*len);
}
