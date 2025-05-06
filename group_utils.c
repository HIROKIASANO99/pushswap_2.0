

#include "./include/push_swap.h"

/* 1) 要素数〈6 のとき、全ノードを group=1 にする */
static void	assign_small_groups(t_list *stack)
{
	while (stack)
	{
		stack->group = 1;
		stack = stack->next;
	}
}

/* 2) 要素数≥6 のとき、order に応じて 6 分割で group を振る */
static void	assign_large_groups(t_list *stack, int count, int base)
{
	t_list	*node;
	int		cur_order;
	int		group;
	int		remaining;

	cur_order = 1;
	group     = 1;
	remaining = base;
	while (cur_order <= count)
	{
		node = stack;
		while (node && node->order != cur_order)
			node = node->next;
		if (node)
		{
			node->group = group;
			remaining--;
			if (remaining == 0)
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
