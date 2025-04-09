/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiasano <hiasano@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 23:03:32 by hiasano           #+#    #+#             */
/*   Updated: 2024/06/12 19:23:43 by hiasano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_atoi(const char *str);
char	*ft_itoa(int n);
int		ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_putnbr_fd(int n, int fd, int *len);

#endif
