/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse_rotate.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiasano <hiasano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 20:26:37 by hiasano           #+#    #+#             */
/*   Updated: 2025/05/08 20:26:39 by hiasano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	command_rra(t_list **a)
{
	if (!a || !*a || !(*a)->next)
		return ;
	ft_command_reverse_rotate(a);
	ft_printf("rra\n");
}

void	command_rrb(t_list **b)
{
	if (!b || !*b || !(*b)->next)
		return ;
	ft_command_reverse_rotate(b);
	ft_printf("rrb\n");
}

void	command_rrr(t_list **a, t_list **b)
{
	if ((!a || !*a || !(*a)->next) && (!b || !*b || !(*b)->next))
		return ;
	ft_command_reverse_rotate(a);
	ft_command_reverse_rotate(b);
	ft_printf("rrr\n");
}
