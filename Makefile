INCLUDE	= ./include
NAME	= push_swap
SRCS	= \

OBJS	= $(SRCS:.c=.o)
CC		= cc 
CFLG	= -Wall -Wextra -Werror -g 

LIBFT_PATH = ./libft
LIBFT_NAME = libft.a

FT_PRINTF_PATH	=	./ft_printf
FT_PRINTF_NAME	=	libftprintf.a

$(NAME): $(OBJS) 
		make -C $(LIBFT_PATH) bonus 
				cp	$(LIBFT_PATH)/$(LIBFT_NAME) .
		make -C $(FT_PRINTF_PATH)  
				cp	$(FT_PRINTF_PATH)/$(FT_PRINTF_NAME) .
		$(CC) $(CFLG) $(OBJS) $(LIBFT_NAME) $(FT_PRINTF_NAME) -o $(NAME)
		rm -f $(LIBFT_NAME) $(FT_PRINTF_NAME) 



all:$(NAME)

.c.o:
	$(CC) $(CFLG) -I$(INCLUDE) -c $< -o $@
clean:
	rm -f $(OBJS) $(LIBFT_NAME) $(FT_PRINTF_NAME) 
	@make -C $(LIBFT_PATH) clean
	@make -C $(FT_PRINTF_PATH) clean
fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT_PATH)/$(LIBFT_NAME)
	rm -f $(FT_PRINTF_PATH)/$(FT_PRINTF_NAME)
re: fclean all

.PHONY: all clean fclean re
	

