/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiasano <hiasano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 20:26:52 by hiasano           #+#    #+#             */
/*   Updated: 2025/05/08 20:26:53 by hiasano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	order_pattern(t_list *stk, int cnt)
{
	int		pat;
	int		dig;
	int		j;

	pat = 0;
	while (stk)
	{
		dig = 1;
		j = 1;
		while (j < cnt)
		{
			dig *= 10;
			j++;
		}
		pat += stk->order * dig;
		cnt--;
		stk = stk->next;
	}
	return (pat);
}

static void	sort_three(t_list **a)
{
	int	pat;

	pat = order_pattern(*a, 3);
	if (pat == 132 || pat == 354)
	{
		command_ra(a);
		command_sa(a);
		command_rra(a);
	}
	else if (pat == 213 || pat == 435)
		command_sa(a);
	else if (pat == 231 || pat == 453)
		command_rra(a);
	else if (pat == 312 || pat == 534)
		command_ra(a);
	else if (pat == 321 || pat == 543)
	{
		command_sa(a);
		command_rra(a);
	}
}

static void	sort_five(t_list **a, t_list **b)
{
	int	pushed;

	pushed = 0;
	while (pushed < 2)
	{
		if ((*a)->order <= 2)
		{
			command_pb(a, b);
			pushed++;
		}
		else
			command_ra(a);
	}
	sort_three(a);
	if (*b && (*b)->next && (*b)->order < (*b)->next->order)
		command_sb(b);
	command_pa(a, b);
	command_pa(a, b);
}

void	ft_min_sort(t_list **stack_a, t_list **stack_b, int count)
{
	if (count == 3)
		sort_three(stack_a);
	else if (count == 5)
		sort_five(stack_a, stack_b);
}
