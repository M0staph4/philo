# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmoutawa <mmoutawa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/14 04:00:43 by mmoutawa          #+#    #+#              #
#    Updated: 2022/06/27 23:29:32 by mmoutawa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PS_NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = philo.c utils.c init.c check.c threads_tools.c

OBJS = $(SRCS:.c=.o)

$(PS_NAME) : $(SRCS)
		$(CC) $(CFLAGS) $(SRCS) -o ${PS_NAME}
	
all : $(PS_NAME)

clean :
	rm -f ${OBJS}
fclean : clean
	rm -f philo

re : fclean all
