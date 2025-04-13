/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiasano <hiasano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 20:40:49 by hiasano           #+#    #+#             */
/*   Updated: 2025/04/13 22:09:10 by hiasano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/push_swap.h"

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



int main(int argc, char **argv) 
{    
    t_list *stack_a;

    if(argc < 2)
        return (0);
    stack_a = NULL;
    if(argc == 2)
    {
        // スプリット
    }
    // エラーチェック文字列に整数以外が入っているか⇢スタックaに入れる    

    PRINT_ERROR();
    return (0);
}

/*
int	ft_check_digit(char *str)の返り値
1ならエラー
0ならエラーなし　
*/

