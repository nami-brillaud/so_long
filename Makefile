# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/26 14:41:03 by nfujisak          #+#    #+#              #
#    Updated: 2024/06/26 14:48:59 by nfujisak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= samplefile.c

OBJS	= $(SRCS:.c=.o)

HEAD	= sampleheader.h

NAME	= so_long

LIBFT	= libft/libft.a

PRINTF	= printf/printf.a

AR		= ar rc

RM		= rm -f

LIB 	= ranlib

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

all		= ${NAME}

.c.o:
	${CC} ${CFLAGS} -c -I ${HEAD} $< -o ${<:.c=.o}

${NAME}:	${OBJS}
	${MAKE} -C ./libft && cp ${LIBFT} ${NAME}
	${MAKE} -C ./printf && cp ${PRINTF} ${NAME}
	${AR} ${NAME} ${OBJS}
	${LIB} ${NAME}

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
