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
INCLUDE     = ../include
NAME        = libft.a

SRCS        = ft_atoi.c ft_itoa.c ft_putnbr_fd.c ft_putchar_fd.c ft_putstr_fd.c
OBJDIR      = obj
OBJS        = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# obj ディレクトリへ .o ファイルを出力するパターンルール
$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re


