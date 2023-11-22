# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 14:36:07 by vopekdas          #+#    #+#              #
#    Updated: 2023/11/22 13:29:21 by vopekdas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SOURCES =  src/ft_printf.c \
			src/handle_flags.c \
			src/handle_mandatory.c \
			src/handle_mandatory2.c \
			src/printf_utils.c \
			src/putnbr_base_utils.c

BONUS = src/ft_printf_bonus.c \
			src/handle_flags.c \
			src/handle_mandatory.c \
			src/handle_mandatory2.c \
			src/printf_utils.c \
			src/putnbr_base_utils.c

OBJECTS = $(SOURCES:.c=.o)

BONUS_OBJECTS = $(BONUS:.c=.o)

CC=cc

CFLAGS=-Wall -Wextra -Werror -Iinclude

RM = rm -f

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJECTS)
	ar r $(NAME) $(OBJECTS)

bonus: $(BONUS_OBJECTS)
	ar r $(NAME) $(BONUS_OBJECTS)

clean:
	$(RM) $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all