/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiasano <hiasano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 20:40:49 by hiasano           #+#    #+#             */
/*   Updated: 2025/05/06 16:48:33 by hiasano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/push_swap.h"

int	add_to_stack_a(int count, char **strs, t_list **stack_a)
{
	int	i;
	int	val;
	t_list *new_node;
	int		ret;

	i = 0;
	while (i < count)
	{
		if (ft_atoi_safe(strs[i], &val) < 0)
			return (-1);
		new_node = ft_lstnew(val);
		if (!new_node)
			return (-1);
		ret = ft_lstadd_back(stack_a, new_node);
		if (ret < 0)
		{
			free(new_node);      
			return (-1);
		}
		i++;
	}
	return (count);
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


int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		count_str;

	stack_a = NULL;
	stack_b = NULL;
	if (!check_args(argc, argv))
		return (1);
	count_str = process_args(argc, argv, &stack_a);
	count_str = get_group(count_str, stack_a);
	if (count_str == -1)
		PRINT_ERROR();
	count_str = ft_check_a(count_str, &stack_a);
	if(count_str != -1)
		ft_sortstack(&stack_a, &stack_b, count_str);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	if (count_str == -1)
			return(1);
	return (0);
}