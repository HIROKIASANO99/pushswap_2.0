/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiasano <hiasano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 20:09:03 by hiasano           #+#    #+#             */
/*   Updated: 2024/08/21 20:09:16 by hiasano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *temp;

	if(lst == NULL || del == NULL)
		return;
	while(*lst != NULL)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst ,del);
		*lst = temp;
	}
	return;
}
