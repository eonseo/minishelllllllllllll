CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = -rcs
RM = rm -f

NAME = libftprintf.a
SRCS = ft_printf.c \
       put_str.c \
       put_nbr.c \
       put_hex.c
OBJS = $(SRCS:.c=.o)
INCS = -I./

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^
%.o : %.c
	$(CC) $(CFLAGS) -c $< -I ./

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all
