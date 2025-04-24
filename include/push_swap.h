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

#endif
