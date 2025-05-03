/* ************************************************************************** */
/*                          push_swap_commands.c                              */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_command_swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first  = *stack;
	second = first->next;
	first->next   = second->next;
	second->next  = first;
	*stack        = second;
}

void	ft_command_push(t_list **dst, t_list **src)
{
	t_list	*tmp;

	if (!src || !*src)
		return ;
	tmp    = *src;
	*src   = tmp->next;
	tmp->next = NULL;
	ft_lstadd_front(dst, tmp);
}

void	ft_command_rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
}

void	ft_command_reverse_rotate(t_list **stack)
{
	t_list	*prev;
	t_list	*tail;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	prev = *stack;
	while (prev->next->next)
		prev = prev->next;
	tail = prev->next;
	prev->next = NULL;
	tail->next = *stack;
	*stack = tail;
}
