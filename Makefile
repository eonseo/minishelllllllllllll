# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/15 09:48:53 by seojang           #+#    #+#              #
#    Updated: 2024/10/14 00:11:46 by eonoh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


.DEFAULT_GOAL := all

CC = cc
RM = rm -rf

SRC = main.c \
	ft_tokenizer.c \
	ft_export.c \
	ft_qoute.c \
	ft_split.c \
	ft_split_utils.c \
	ft_libft.c \
	ft_lst_util.c \
	ft_paser.c \
	ft_utils.c \
	./srcs/builtin.c \
	./srcs/builtin2.c \
	./srcs/export_parsing.c \
	./srcs/insert_node.c \
	./srcs/list_utils.c \
	./srcs/longlong.c \
	./srcs/remove_node.c \
	./srcs/utils.c \
	./srcs/error.c

HEADER = ms_test.h

OBJ_S = $(SRC_S:.c=.o) 

CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address

NAME = minishell

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	@make -C ./libft
	@make -C ./ft_printf
	$(CC) $(OBJ) -lreadline -o $@ ./libft/libft.a ./ft_printf/libftprintf.a

%.o : %.c
	$(CC) -c $< -o $@ -I ./
	
clean :
	@make -C ./libft clean
	@make -C ./ft_printf clean
	$(RM) $(OBJ)

fclean : clean
	@make -C ./libft fclean
	@make -C ./ft_printf fclean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
