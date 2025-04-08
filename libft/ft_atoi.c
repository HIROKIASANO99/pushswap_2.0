/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiasano <hiasano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:30:10 by hiasano           #+#    #+#             */
/*   Updated: 2024/08/21 20:15:45 by hiasano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

static int	skip_and_minus_cheak(int sign, const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	return (sign);
}

static int	check_overflow(long long num, long long num2)
{
	if (num <= 0 && num2 != 0)
		return (1);
	return (0);
}

static int	a(int minus)
{
	if (minus == 1)
		return (-1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	num;
	long long	num2;

	i = 0;
	sign = 1;
	num = 0;
	num2 = 0;
	sign = skip_and_minus_cheak(sign, str);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while ('0' <= str[i] && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
		if (check_overflow(num, num2))
			return (a(sign));
		num2 = num;
	}
	return (sign * (int)num);
}

// int main() {
//     const char *str1 = "1234";
//     const char *str2 = "21474836484";
//     const char *str3 = "0";

//     int num1 = atoi(str1);
//     int num2 = atoi(str2);
//     int num3 = atoi(str3);

//     printf("Number1: %d\n", num1);
//     printf("Number2: %d\n", num2);
//     printf("Number3: %d\n", num3);

//     int ft_num1 = ft_atoi(str1);
//     int ft_num2 = ft_atoi(str2);
//     int ft_num3 = ft_atoi(str3);

//     printf("ft_Number1: %d\n", ft_num1);
//     printf("ft_Number2: %d\n", ft_num2);
//     printf("ft_Number3: %d\n", ft_num3);

//     printf("max=%d,min=%d\n",INT_MAX,INT_MIN);
//     return (0);
// }
