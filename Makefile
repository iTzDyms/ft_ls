#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cheron <cheron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 17:06:50 by cheron            #+#    #+#              #
#    Updated: 2013/12/09 18:51:04 by cheron           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

export CC = gcc
export CFLAGS = -Wall -Werror -Wextra
export OFLAGS = -O3
export RM = rm -rf

LIB_DIR = ./libft
INCLUDES_DIR = ./libft/includes

LIBFT = $(LIB_DIR)/libft.a

NAME = ft_ls


SRC = main.c ft_readdir.c parser.c ft_parse_file.c

OBJ = $(SRC:.c=.o)


all: $(LIBFT) $(NAME)

$(LIBFT):
	@($(MAKE) -C $(LIB_DIR))

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OFLAGS) -o $(NAME) $(OBJ)  -L $(LIB_DIR) -lft

clean:
	@($(MAKE) $@ -C $(LIB_DIR))
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

%.o: %.c ft_ls.h
	$(CC) $(CFLAGS) $(OFLAGS) -c $< -o $@ -I $(INCLUDES_DIR)

.PHONY: all clean re fclean
