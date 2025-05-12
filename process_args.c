/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiasano <hiasano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 20:25:12 by hiasano           #+#    #+#             */
/*   Updated: 2025/05/08 20:25:14 by hiasano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	handle_single_arg(char *arg, t_list **stack_a)
{
	char	**strs;
	int		cnt;
	int		i;
	int		ret;

	strs = ft_split(arg, ' ', &cnt);
	if (!strs)
		return (-1);
	i = -1;
	while (++i < cnt)
	{
		if (ft_check_digit(strs[i]))
		{
			free_strs(strs);
			return (-1);
		}
	}
	ret = add_to_stack_a(cnt, strs, stack_a);
	free_strs(strs);
	return (ret);
}

static int	handle_multi_args(int argc, char **argv, t_list **stack_a)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_check_digit(argv[i]))
			return (-1);
		i++;
	}
	return (add_to_stack_a(argc - 1, argv + 1, stack_a));
}

int	process_args(int argc, char **argv, t_list **stack_a)
{
	if (argc == 2)
		return (handle_single_arg(argv[1], stack_a));
	return (handle_multi_args(argc, argv, stack_a));
}
