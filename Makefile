# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/07 02:53:54 by bhildebr          #+#    #+#              #
#    Updated: 2023/10/07 02:53:54 by bhildebr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT_NAME = client
SERVER_NAME = server

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g

CLIENT_HEADERS = \
	client.h \
	ft_universe.h
CLIENT_SOURCES = \
	client.c \
	print_cstring.c \
	ft_atoi.c
CLIENT_OBJECTS = \
	client.o \
	print_cstring.o \
	ft_atoi.o

SERVER_HEADERS = \
	server.h \
	ft_universe.h
SERVER_SOURCES = \
	print_cstring.c \
	print_int.c \
	server.c
SERVER_OBJECTS = \
	print_cstring.o \
	print_int.o \
	server.o

all: norm client server

norm:
	norminette $(CLIENT_HEADERS) $(CLIENT_SOURCES) $(SERVER_HEADERS) $(SERVER_SOURCES)

client: $(CLIENT_OBJECTS)
	$(CC) $(CLIENT_OBJECTS) -o $(CLIENT_NAME)

server: $(SERVER_OBJECTS)
	$(CC) $(SERVER_OBJECTS) -o $(SERVER_NAME)

clean:
	$(RM) $(CLIENT_OBJECTS)
	$(RM) $(SERVER_OBJECTS)

fclean: clean
	$(RM) $(CLIENT_NAME)
	$(RM) $(SERVER_NAME)

re: fclean all

.PHONY: all clean fclean re