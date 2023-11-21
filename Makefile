# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 14:36:07 by vopekdas          #+#    #+#              #
#    Updated: 2023/11/21 16:28:27 by vopekdas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SOURCES =  ft_printf.c \
			handle_flags.c \
			handle_mandatory.c \
			handle_mandatory2.c \
			printf_utils.c \
			putnbr_base_utils.c

OBJECTS = $(SOURCES:.c=.o)

CC=cc

CFLAGS=-Wall -Wextra -Werror

RM = rm -f

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJECTS)
	ar r $(NAME) $(OBJECTS)

bonus: $(OBJECTS) $(BONUS_OBJECTS)
	ar r $(NAME) $(OBJECTS) $(BONUS_OBJECTS)

clean:
	$(RM) $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all