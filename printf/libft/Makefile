# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hiasano <hiasano@student.42tokyo.j>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/22 21:57:37 by hiasano           #+#    #+#              #
#    Updated: 2024/05/26 02:44:12 by hiasano          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ./Libft/Makefile
INCLUDE = ../include
NAME = libft.a
SRCS = ft_atoi.c ft_itoa.c ft_putnbr_fd.c ft_putchar_fd.c ft_putstr_fd.c
OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar	rcs	$(NAME) $(OBJS)
.c.o:
	$(CC) $(CFLAG) -I $(INCLUDE) -c $< -o $@
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re

