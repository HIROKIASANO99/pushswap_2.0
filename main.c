/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiasano <hiasano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 20:40:49 by hiasano           #+#    #+#             */
/*   Updated: 2025/04/28 22:08:25 by hiasano          ###   ########.fr       */
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
			free(new_node);      /* ← ここで必ず解放 */
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
	int		count_str;

	stack_a = NULL;
	if (!check_args(argc, argv))
		return (0);
	count_str = process_args(argc, argv, &stack_a);
	if (count_str == -1)
		PRINT_ERROR();
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