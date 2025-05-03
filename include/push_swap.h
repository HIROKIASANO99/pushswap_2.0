#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../ft_printf/include/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>

//debug.c---------------------------------------------------
#include <stdio.h>  /* 42 版 printf を使うなら不要 */
void	print_stack(t_list *stack, char c);
//----------------------------------------------------------

// main.c
int     main(int argc, char **argv);
void	free_strs(char **strs);
int add_to_stack_a(int count_int, char **strs, t_list **stack_a);

// check.c
int	    ft_check_digit(char *str);

//process_args.c
int	process_args(int argc, char **argv, t_list **stack_a);


int	get_group(int count_str, t_list *stack_a);

/* commands.c */
void	ft_command_swap(t_list **stack);
void	ft_command_push(t_list **dst, t_list **src);
void	ft_command_rotate(t_list **stack);
void	ft_command_reverse_rotate(t_list **stack);

/* operations_swap_push.c */
void	command_sa(t_list **a);
void	command_sb(t_list **b);
void	command_ss(t_list **a, t_list **b);
void	command_pa(t_list **a, t_list **b);
void	command_pb(t_list **a, t_list **b);

/* operations_rotate.c */
void	command_ra(t_list **a);
void	command_rb(t_list **b);
void	command_rr(t_list **a, t_list **b);

/* operations_reverse_rotate.c */
void	command_rra(t_list **a);
void	command_rrb(t_list **b);
void	command_rrr(t_list **a, t_list **b);

// sort.c
void	ft_first_sort(t_list **stack_a, t_list **stack_b, int top, int bottom);
void	ft_sortstack(t_list **stack_a, t_list **stack_b, int size);

#endif
