/* ************************************************************************** */
/*                   command_reverse_rotate.c                                  */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	command_rra(t_list **a)
{
	if (!a || !*a || !(*a)->next)
		return;
	ft_command_reverse_rotate(a);
	ft_printf("rra\n");
}

void	command_rrb(t_list **b)
{
	if (!b || !*b || !(*b)->next)
		return;
	ft_command_reverse_rotate(b);
	ft_printf("rrb\n");
}

void	command_rrr(t_list **a, t_list **b)
{
	if ((!a || !*a || !(*a)->next) \
	&&  (!b || !*b || !(*b)->next))
		return;
	ft_command_reverse_rotate(a);
	ft_command_reverse_rotate(b);
	ft_printf("rrr\n");
}
