/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiasano <hiasano@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:13:45 by hiasano           #+#    #+#             */
/*   Updated: 2024/05/26 01:21:44 by hiasano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_print_str_count_len(char *str);
int	ft_convert_base(unsigned int num, char type, int *len);
int	ft_print_address(unsigned long long address, int *len);
int	ft_putnbr_unsign_fd(unsigned int n, int fd, int *len);
// int	ft_putnbr_fd(int n, int fd, int *len);
// int	ft_putchar_fd(int n, int fd);

#endif
