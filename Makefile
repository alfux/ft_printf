# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/04 12:50:53 by afuchs            #+#    #+#              #
#    Updated: 2022/03/08 18:50:15 by afuchs           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT		=	ft_atoi.c				\
				ft_lstmap_bonus.c		\
				ft_striteri.c			\
				ft_bzero.c				\
				ft_lstnew_bonus.c		\
				ft_strjoin.c			\
				ft_calloc.c				\
				ft_lstsize_bonus.c		\
				ft_strlcat.c			\
				ft_isalnum.c			\
				ft_memchr.c				\
				ft_strlcpy.c			\
				ft_isalpha.c			\
				ft_memcmp.c				\
				ft_strlen.c				\
				ft_isascii.c			\
				ft_memcpy.c				\
				ft_strmapi.c			\
				ft_isdigit.c			\
				ft_memmove.c			\
				ft_strncmp.c			\
				ft_isprint.c			\
				ft_memset.c				\
				ft_strnstr.c			\
				ft_itoa.c				\
				ft_putchar_fd.c			\
				ft_strrchr.c			\
				ft_lstadd_back_bonus.c	\
				ft_putendl_fd.c			\
				ft_strtrim.c			\
				ft_lstadd_front_bonus.c	\
				ft_putnbr_fd.c			\
				ft_substr.c				\
				ft_lstclear_bonus.c		\
				ft_putstr_fd.c			\
				ft_tolower.c			\
				ft_lstdelone_bonus.c	\
				ft_split.c				\
				ft_toupper.c			\
				ft_lstiter_bonus.c		\
				ft_strchr.c				\
				ft_lstlast_bonus.c		\
				ft_strdup.c				\
				ft_putchar_l.c			\
				ft_putstr_l.c			\
				ft_putnbr_l.c			\
				ft_putnbru_l.c			\
				ft_putnbrh_l.c			\
				ft_printf.c				\

PATH_LIB	=	libft/

LIBFTO		=	$(LIBFT:%.c=$(PATH_LIB)%.o)

FLAGS		=	-Wall -Wextra -Werror

OPTIONS		=	-o

NAME		=	libftprintf.a

NAME_LIB	=	libft.a

$(NAME)					:	$(LIBFTO)
							@ar -r $(NAME) $^
							@echo Compilation complete.

$(PATH_LIB)%.o			:	$(PATH_LIB)%.c
							@(cd $(PATH_LIB) && $(MAKE) bonus)

all						:	$(NAME)

clean					:	
							@(cd $(PATH_LIB) && $(MAKE) $@)

fclean					:	clean
							@rm -rf $(NAME)
							@(cd $(PATH_LIB) && $(MAKE) $@)
							@echo $(NAME) removed.

re						:	fclean all

.PHONY					:	all clean fclean re
