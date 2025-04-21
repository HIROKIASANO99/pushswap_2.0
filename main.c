/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiasano <hiasano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 20:40:49 by hiasano           #+#    #+#             */
/*   Updated: 2025/04/21 22:45:48 by hiasano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/push_swap.h"

int add_to_stack_a(int count_int, char **strs, t_list **stack_a)
{
    int i;
    t_list *new_node;
    
    i = 0;
    while (i < count_int)
    {
        new_node = ft_lstnew(ft_atoi(strs[i]));
        if (!new_node)
            return (-1);
        ft_lstadd_back(stack_a, new_node);
        i++;
    }
    return (count_int);
}

void	free_strs(char **strs)
{
	int	i;

	if (!strs)
		return;
	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

void	ft_initialize_node(t_list *node)
{
	if (!node)
		return;
	node->number = 0;
	node->order = 0;
	node->group = 0;
	node->next = NULL;
	node->top = NULL;
	node->bottom = NULL;
}

static int	check_args(int argc, char **argv)
{
	int	i;

	if (argc < 2)
		return (0);
	if (argc > 2)
	{
		i = 1;
		while (i < argc)
		{
			if (ft_strchr(argv[i], ' '))
			{
				ft_putstr_fd("Error\n", 2);
				return (0);
			}
			i++;
		}
	}
	return (1);
}


// int	process_args(int argc, char **argv, t_list **stack_a)
// {
	// char	**strs;
	// int		count_str;
	// int		tmp_count;
// 
	// strs = NULL;
	// count_str = 0;
	// if (argc == 2)
	// {
		// strs = ft_split(argv[1], ' ', &tmp_count);
		// count_str = tmp_count;
		// count_str = add_to_stack_a(count_str, strs, stack_a);
	// }
	// else
	// {
		// argv++;
		// count_str = add_to_stack_a(argc - 1, argv, stack_a);
	// }
	// if (strs)
		// free_strs(strs);
	// return (count_str);
// }


int	main(int argc, char **argv)
{
	t_list	*stack_a;
	int		count_str;

	stack_a = NULL;
	if (!check_args(argc, argv))
		return (0);
	count_str = process_args(argc, argv, &stack_a);
printf("count_str = %d\n",count_str);
print_stack(stack_a,'a');
	ft_lstclear(&stack_a);
print_stack(stack_a,'a');
	return (0);
}

// PRINT_ERROR();

/*
int	ft_check_digit(char *str)の返り値
1ならエラー
0ならエラーなし　
*/