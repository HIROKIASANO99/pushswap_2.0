#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../ft_printf/include/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>

// main.c
int     main(int argc, char **argv);
void	free_strs(char **strs);
void    ft_initialize_node(t_list *node);
int add_to_stack_a(int count_int, char **strs, t_list **stack_a);

// check.c
int	    ft_check_digit(char *str);

#endif
