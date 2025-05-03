/* ************************************************************************** */
/*  debug.c                                                               */
/* ************************************************************************** */

#include "push_swap.h"

/* 単一ノードを表示するヘルパー（再帰・ネストなし） */
static void	print_node(t_list *node, int idx, char c)
{
	if (!node)
		return ;
	printf("stack_%c	[%d		] num:%d		ord:%d		grp:%d		|node:%p	next:%p\n",
		c, idx, node->number, node->order, node->group, (void *)node,(void *)node->next);
}

/* スタック全体を走査して各ノードを出力 */
void	print_stack(t_list *stack, char c)
{
    printf("---- start of stack_%c----\n",c);
	int	i;

	i = 1;
	while (stack)
	{
		print_node(stack, i , c) ;
		stack = stack->next;
		i++;
	}
	printf("---- end of stack_%c----\n",c);
}
