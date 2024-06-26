# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/26 14:41:03 by nfujisak          #+#    #+#              #
#    Updated: 2024/06/26 16:53:03 by nfujisak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= samplefile.c

OBJS	= $(SRCS:.c=.o)

HEAD	= so_long.h

NAME	= so_long

LIBFT	= libft/libft.a

PRINTF	= printf/libftprintf.a

RM		= rm -f

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

all:	${NAME}

%.o: %.c
	${CC} ${CFLAGS} -Imlx -I ${HEAD} -c $< -o $@

${NAME}:	${OBJS}
	${MAKE} -C ./libft && cp ${LIBFT} ${NAME}
	${MAKE} -C ./printf && cp ${PRINTF} ${NAME}
	${CC} ${OBJS} -Lmlx -lmlx -framework OpenGL -framework AppKit -o ${NAME}

all: $(NAME)

clean:
	${MAKE} clean -C ./libft
	${MAKE} clean -C ./printf
	${RM} ${OBJS}

fclean:	clean
	${MAKE} fclean -C ./libft
	${MAKE} fclean -C ./printf
	${RM} ${NAME}

re:		fclean all

.PHONY:	all bonus clean fclean re
