# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmoutawa <mmoutawa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/14 04:00:43 by mmoutawa          #+#    #+#              #
#    Updated: 2022/06/14 05:10:33 by mmoutawa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PS_NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -lpthread -pthread
SRCS = philo.c utils.c

OBJS = $(SRCS:.c=.o)

$(PS_NAME) : $(SRCS)
		$(CC) $(CFLAGS) $(SRCS) -o ${PS_NAME}
	
all : $(PS_NAME)

clean :
	rm -f ${OBJS}
fclean : clean
	rm -f philo

re : fclean all
