
#include "./include/push_swap.h"

void	ft_first_sort(t_list **stack_a, t_list **stack_b, int top, int bottom)
{
	int		count;
	int		remaining;
	t_list	*tmp;

	tmp = *stack_a;
	count = 0;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	remaining = count;
	while (remaining-- > 0 && *stack_a)
	{
		if ((*stack_a)->group == top)
			command_pb(stack_a, stack_b);
		else if ((*stack_a)->group == bottom)
		{
			command_pb(stack_a, stack_b);
			command_rb(stack_b);
		}
		else
			command_ra(stack_a);
	}
}

void	ft_sortstack(t_list **stack_a, t_list **stack_b, int size)
{
	if (size == 0)
		return ;
    if (size == 3 || size == 5)
    {
	    ft_min_sort(stack_a, stack_b, size);
        return;
    }
	ft_first_sort(stack_a, stack_b, 4, 3);
	ft_first_sort(stack_a, stack_b, 5, 2);
	ft_first_sort(stack_a, stack_b, 6, 1);
    ft_second_sort(stack_a, stack_b, size);
    return;
} 