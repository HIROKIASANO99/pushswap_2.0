/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiasano <hiasano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 20:41:13 by hiasano           #+#    #+#             */
/*   Updated: 2025/05/06 17:01:46 by hiasano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/push_swap.h"

int	ft_check_digit(char *str)
{
	int i;

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

int	ft_check_a(int count_str, t_list **stack_a)
{
	t_list	*cur;

	if (!stack_a || !*stack_a || (count_str == -1))
		return(-1);
	cur = *stack_a;
	while (cur->next)
	{
		if (cur->order + 1 != cur->next->order)
			return (count_str);
		cur = cur->next;
	}
	ft_lstclear(stack_a);
	return(-1);
}