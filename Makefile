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
CFLAGS = -Wall -Werror -Wextra

CLIENT_HEADERS = \
	client.h \
	ft_universe.h
CLIENT_SOURCES = \
	client.c
CLIENT_OBJECTS = \
	client.o

SERVER_HEADERS = \
	server.h \
	ft_universe.h \
	memory.h \
	string.h
SERVER_SOURCES = \
	memory_create.c \
	memory_destroy.c \
	print_cstring.c \
	print_int.c \
	server.c \
	string_append_char.c \
	string_create.c \
	string_destroy.c \
	string_print.c \
	string_realloc.c
SERVER_OBJECTS = \
	memory_create.o \
	memory_destroy.o \
	print_cstring.o \
	print_int.o \
	server.o \
	string_append_char.o \
	string_create.o \
	string_destroy.o \
	string_print.o \
	string_realloc.o

all: client server

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

.PHONY: all client server clean fclean re