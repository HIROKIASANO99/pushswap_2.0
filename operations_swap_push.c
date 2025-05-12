/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap_push.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiasano <hiasano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 20:25:45 by hiasano           #+#    #+#             */
/*   Updated: 2025/05/08 20:25:47 by hiasano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	command_sa(t_list **a)
{
	if (!a || !*a || !(*a)->next)
		return ;
	ft_command_swap(a);
	ft_printf("sa\n");
}

void	command_sb(t_list **b)
{
	if (!b || !*b || !(*b)->next)
		return ;
	ft_command_swap(b);
	ft_printf("sb\n");
}

void	command_ss(t_list **a, t_list **b)
{
	if ((!a || !*a || !(*a)->next) && (!b || !*b || !(*b)->next))
		return ;
	ft_command_swap(a);
	ft_command_swap(b);
	ft_printf("ss\n");
}

void	command_pa(t_list **a, t_list **b)
{
	if (!b || !*b)
		return ;
	ft_command_push(a, b);
	ft_printf("pa\n");
}

void	command_pb(t_list **a, t_list **b)
{
	if (!a || !*a)
		return ;
	ft_command_push(b, a);
	ft_printf("pb\n");
}
