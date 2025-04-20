/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiasano <hiasano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 20:08:03 by hiasano           #+#    #+#             */
/*   Updated: 2025/04/20 20:09:54 by hiasano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *list;

	if (!new || !lst)
		return;
	if (*lst == NULL)
	{
		*lst = new;
		return;
	}
	list = *lst;
	while(list->next != NULL)
		list = list->next;
	list->next = new; 
	return;
}
