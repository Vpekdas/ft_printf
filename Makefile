# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 14:36:07 by vopekdas          #+#    #+#              #
#    Updated: 2023/11/24 15:44:25 by vopekdas         ###   ########.fr        #
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
			src/handle_flags_bonus.c \
			src/handle_mandatory_bonus.c \
			src/handle_mandatory2_bonus.c \
			src/printf_utils_bonus.c \
			src/putnbr_base_utils_bonus.c

OBJECTS = $(SOURCES:.c=.o)

BONUS_OBJECTS = $(BONUS:.c=.o)

CC=cc

CFLAGS=-Wall -Wextra -Werror -Iinclude

RM = rm -f

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

bonus: $(BONUS_OBJECTS)
	ar rcs $(NAME) $(BONUS_OBJECTS)

clean:
	$(RM) $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all