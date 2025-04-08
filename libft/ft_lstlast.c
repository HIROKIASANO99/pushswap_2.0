/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiasano <hiasano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 20:11:54 by hiasano           #+#    #+#             */
/*   Updated: 2024/08/21 20:11:56 by hiasano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list *ft_lstlast(t_list *lst)
{
	if(!lst)
		return(NULL);
	while(lst->next != NULL)
		lst = lst->next;
	return(lst);
}
