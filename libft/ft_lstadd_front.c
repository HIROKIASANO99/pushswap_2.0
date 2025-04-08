/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiasano <hiasano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 20:08:45 by hiasano           #+#    #+#             */
/*   Updated: 2024/08/21 20:08:48 by hiasano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if(!new || !lst)
		return;
	new->next = *lst;
	*lst = new;
}
