# /* ************************************************************************** */
# /*                                                                            */
# /*                                                        :::      ::::::::   */
# /*   Makefile                                           :+:      :+:    :+:   */
# /*                                                    +:+ +:+         +:+     */
# /*   By: sguruge <sguruge@student.42tokyo.jp>       #+#  +:+       +#+        */
# /*                                                +#+#+#+#+#+   +#+           */
# /*   Created: 2025-05-14 13:08:30 by sguruge           #+#    #+#             */
# /*   Updated: 2025-05-14 13:08:30 by sguruge          ###   ########.fr       */
# /*                                                                            */
# /* ************************************************************************** */

NAME = libft.a
CC = cc
AR = ar rcs
RM = rm -f
CFLAGS = -Wall -Werror -Wextra 
INCLUDES = -Iincludes

SRC_DIR = utils
UTILS = \
	utils/ft_isalpha.c utils/ft_isdigit.c utils/ft_isalnum.c utils/ft_isascii.c utils/ft_isprint.c \
	utils/ft_tolower.c utils/ft_toupper.c \
	utils/ft_strlen.c utils/ft_strchr.c utils/ft_strdup.c utils/ft_strlcat.c utils/ft_strlcpy.c utils/ft_strncmp.c \
	utils/ft_strnstr.c utils/ft_strrchr.c utils/ft_substr.c utils/ft_strjoin.c utils/ft_strtrim.c  utils/ft_strmapi.c utils/ft_striteri.c\
	utils/ft_atoi.c utils/ft_itoa.c utils/ft_split.c \
	utils/ft_putchar_fd.c utils/ft_putstr_fd.c utils/ft_putendl_fd.c utils/ft_putnbr_fd.c \
	utils/ft_bzero.c utils/ft_calloc.c utils/ft_memchr.c utils/ft_memcmp.c utils/ft_memmove.c utils/ft_memset.c utils/ft_memcpy.c\
	utils/ft_printf.c utils/print1.c utils/print2.c utils/special_itoa1.c utils/special_itoa2.c\
	utils/get_next_line.c utils/get_next_line_utils.c\

SRCS = 



OBJS = $(UTILS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
