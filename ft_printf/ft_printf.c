/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiasano <hiasano@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:20:04 by hiasano           #+#    #+#             */
/*   Updated: 2024/06/12 19:23:00 by hiasano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ft_printf.h"
#include "stdarg.h"

static int	ft_print_char(char c)
{
	return (write(1, &c, 1));
}

static int	ft_str_cheak(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] != 'c' && str[i + 1] != 's' && str[i + 1] != 'p'
				&& str[i + 1] != 'd' && str[i + 1] != 'i' && str[i + 1] != 'u'
				&& str[i + 1] != 'x' && str[i + 1] != 'X' && str[i + 1] != '%')
				return (1);
			i++;
		}
		i++;
	}
	return (0);
}

static int	ft_process_by_type(char type, va_list ap)
{
	int	i;

	i = 0;
	if (type == 'c')
		return (ft_print_char(va_arg(ap, int)));
	if (type == 's')
		return (ft_print_str_count_len(va_arg(ap, char *)));
	if (type == 'p')
	{
		if (write(1, "0x", 2) == -1)
			return (-1);
		i = 2;
		return (ft_print_address(va_arg(ap, unsigned long long), &i));
	}
	if (type == 'd' || type == 'i')
		return (ft_putnbr_fd(va_arg(ap, int), 1, &i));
	if (type == 'u')
		return (ft_putnbr_unsign_fd(va_arg(ap, unsigned int), 1, &i));
	if (type == 'x' || type == 'X')
		return (ft_convert_base(va_arg(ap, unsigned int), type, &i));
	if (type == '%')
		return (ft_print_char('%'));
	return (-1);
}

static int	ft_else(int i, int result_len, const char *str)
{
	int	count_char;

	count_char = write(1, &str[i], 1);
	i++;
	result_len++;
	return (count_char);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		count_char;
	int		result_len;

	va_start(ap, str);
	i = 0;
	result_len = 0;
	if (ft_str_cheak(str))
		return (-1);
	while (str[i])
	{
		if (str[i] == '%')
		{
			count_char = ft_process_by_type(str[i + 1], ap);
			result_len += count_char;
			i += 2;
		}
		else
			count_char = ft_else(i++, result_len++, str);
		if (count_char == -1)
			return (-1);
	}
	va_end(ap);
	return (result_len);
}
