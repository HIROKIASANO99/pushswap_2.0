/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiasano <hiasano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 20:26:13 by hiasano           #+#    #+#             */
/*   Updated: 2025/05/08 20:26:15 by hiasano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	command_ra(t_list **a)
{
	if (!a || !*a || !(*a)->next)
		return ;
	ft_command_rotate(a);
	ft_printf("ra\n");
}

void	command_rb(t_list **b)
{
	if (!b || !*b || !(*b)->next)
		return ;
	ft_command_rotate(b);
	ft_printf("rb\n");
}

void	command_rr(t_list **a, t_list **b)
{
	if ((!a || !*a || !(*a)->next) && (!b || !*b || !(*b)->next))
		return ;
	ft_command_rotate(a);
	ft_command_rotate(b);
	ft_printf("rr\n");
}
