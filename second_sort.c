/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiasano <hiasano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 20:24:22 by hiasano           #+#    #+#             */
/*   Updated: 2025/05/08 20:24:27 by hiasano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/push_swap.h"

static int	ft_find_position(t_list *stack_b, int n)
{
	t_list	*cur;
	int		i;

	cur = stack_b;
	i = 1;
	while (cur && cur->order != n)
	{
		cur = cur->next;
		i++;
	}
	return (i);
}

static void	rotate_stack_b(t_list **stack_b, int n, int pos)
{
	if (pos <= n / 2)
	{
		while ((*stack_b)->order != n)
		{
			command_rb(stack_b);
		}
	}
	else
	{
		while ((*stack_b)->order != n)
		{
			command_rrb(stack_b);
		}
	}
}

void	ft_second_sort(t_list **stack_a, t_list **stack_b, int size)
{
	int	n;
	int	pos;

	n = size;
	while (n >= 1)
	{
		pos = ft_find_position(*stack_b, n);
		rotate_stack_b(stack_b, n, pos);
		command_pa(stack_a, stack_b);
		n--;
	}
}
