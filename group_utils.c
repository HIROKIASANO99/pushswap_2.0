/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiasano <hiasano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 20:27:09 by hiasano           #+#    #+#             */
/*   Updated: 2025/05/12 21:24:13 by hiasano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/push_swap.h"

static void	assign_small_groups(t_list *stack)
{
	while (stack)
	{
		stack->group = 1;
		stack = stack->next;
	}
}

static t_list	*find_order_node(t_list *stack, int order)
{
	while (stack && stack->order != order)
		stack = stack->next;
	return (stack);
}

static void	assign_large_groups(t_list *stack, int count, int base)
{
	int		cur_order;
	int		group;
	int		remaining;
	t_list	*node;

	cur_order = 1;
	group = 1;
	remaining = base;
	while (cur_order <= count)
	{
		node = find_order_node(stack, cur_order);
		if (node)
		{
			node->group = group;
			if (--remaining == 0)
			{
				group++;
				remaining = base;
				if (group == 6)
					remaining += count % 6;
			}
		}
		cur_order++;
	}
}

int	get_group(int count_str, t_list *stack_a)
{
	int	base;

	if (count_str < 1)
		return (-1);
	base = count_str / 6;
	if (base == 0)
		assign_small_groups(stack_a);
	else
		assign_large_groups(stack_a, count_str, base);
	return (count_str);
}
