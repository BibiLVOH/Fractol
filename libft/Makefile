# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 14:51:26 by bvigne            #+#    #+#              #
#    Updated: 2018/03/09 14:24:22 by bvigne           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAG = -Wall -Wextra -Werror

SRC = ft_abs.c					\
	  ft_atoi.c 				\
	  ft_atoi_base.c			\
	  ft_biggest.c				\
	  ft_bzero.c 				\
	  ft_charjoin.c 			\
	  ft_isalnum.c 				\
	  ft_isalpha.c 				\
	  ft_isascii.c 				\
	  ft_isblank.c 				\
	  ft_isdigit.c 				\
	  ft_islower.c 				\
	  ft_isprint.c 				\
	  ft_isupper.c 				\
	  ft_itoa.c 				\
	  ft_itoa_base.c 			\
	  ft_lstadd.c 				\
	  ft_lstaddend.c			\
	  ft_lstcount.c 			\
	  ft_lstdel.c 				\
	  ft_lstdelone.c 			\
	  ft_lstiter.c 				\
	  ft_lstlast.c 				\
	  ft_lstmap.c 				\
	  ft_lstnew.c 				\
	  ft_memalloc.c 			\
	  ft_memccpy.c 				\
	  ft_memchr.c 				\
	  ft_memcmp.c 				\
	  ft_memcpy.c 				\
	  ft_memdel.c 				\
	  ft_memmove.c 				\
	  ft_memset.c 				\
	  ft_nbrlen.c				\
	  ft_nbrlen_base.c			\
	  ft_nbr_split_whitespaces.c\
	  ft_power.c 				\
	  ft_putchar.c 				\
	  ft_putchar_fd.c 			\
	  ft_putendl.c 				\
	  ft_putendl_fd.c 			\
	  ft_putnchar.c				\
	  ft_putnbr.c 				\
	  ft_putnbr_fd.c 			\
	  ft_putnbr_base.c 			\
	  ft_putnstr.c				\
	  ft_putstr.c 				\
	  ft_putunbr.c				\
	  ft_put_hex.c				\
	  ft_put_uhex.c				\
	  ft_put_uhex_maj.c			\
	  ft_putstr_fd.c 			\
	  ft_smallest.c				\
	  ft_split_whitespaces.c	\
	  ft_strcapitalize.c 		\
	  ft_strcat.c 				\
	  ft_strcdup.c				\
	  ft_strchr.c 				\
	  ft_strclr.c 				\
	  ft_strcmp.c 				\
	  ft_strcpy.c 				\
	  ft_strdel.c 				\
	  ft_strdup.c 				\
	  ft_strequ.c 				\
	  ft_strndup.c				\
	  ft_strend.c				\
	  ft_str_is_alpha.c 		\
	  ft_str_is_lowercase.c 	\
	  ft_str_is_printable.c 	\
	  ft_str_is_uppercase.c 	\
	  ft_striter.c 				\
	  ft_striteri.c 			\
	  ft_strjoin.c 				\
	  ft_strlcat.c 				\
	  ft_strlen.c 				\
	  ft_strlowcase.c 			\
	  ft_strmap.c 				\
	  ft_strmapi.c 				\
	  ft_strncat.c 				\
	  ft_strncmp.c 				\
	  ft_strncpy.c 				\
	  ft_strnequ.c 				\
	  ft_strnew.c 				\
	  ft_strnstr.c 				\
	  ft_strrchr.c 				\
	  ft_strrev.c 				\
	  ft_strsplit.c 			\
	  ft_strstr.c 				\
	  ft_strsub.c 				\
	  ft_strsubdel.c 			\
	  ft_strtrim.c 				\
	  ft_strupcase.c 			\
	  ft_swap.c 				\
	  ft_tablen.c 				\
	  ft_tolower.c 				\
	  ft_toupper.c				\
	  get_next_line.c

OBJ = $(SRC:.c=.o)
	OPTION = -c -include libft.h

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAG) $(OPTION) $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
