/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiasano <hiasano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 20:08:03 by hiasano           #+#    #+#             */
/*   Updated: 2025/04/28 22:07:46 by hiasano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*cur;

	if (!new)
		return (-1);
	if (*lst == NULL)
	{
		*lst = new;
		return (0);
	}
	cur = *lst;
	while (cur)
	{
		if (cur->number == new->number)
			return (-1);
		if (cur->number > new->number)
			cur->order++;
		else
			new->order++;
		if (cur->next == NULL)
			break ;
		cur = cur->next;
	}
	cur->next = new;
	return (0);
}
