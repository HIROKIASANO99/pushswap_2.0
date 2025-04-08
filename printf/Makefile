# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hiasano <hiasano@student.42tokyo.j>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/22 22:17:37 by hiasano           #+#    #+#              #
#    Updated: 2024/05/26 02:45:40 by hiasano          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDE =	./include
NAME	=	libftprintf.a
SRCS	=	\
	ft_printf.c	ft_print_str.c	ft_print_hex.c ft_print_pointer.c	ft_putnbr_unsign_fd.c


OBJS = $(SRCS:.c=.o)
CC = cc
CFLAG = -Wall -Wextra -Werror 

LIBFT_PATH = ./libft
LIBFT_NAME = libft.a

$(NAME) : $(OBJS)
	make -C	$(LIBFT_PATH)	all
		cp	$(LIBFT_PATH)/$(LIBFT_NAME)	$(NAME)
	ar rc	$(NAME)	$(OBJS)
	@make -C $(LIBFT_PATH) clean



all:$(NAME)

.c.o:
	$(CC) $(CFLAG) -I $(INCLUDE) -c $< -o $@
clean:
	rm -f $(OBJS)
	@make -C $(LIBFT_PATH) clean
fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT_PATH)/$(LIBFT_NAME)
re:fclean all

.PHONY:	all	clean	fclean	re
