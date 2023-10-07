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

BUFFER_DIR = ./buffer
BUFFER_INCLUDES = buffer.h
BUFFER_SOURCES = \
				malloc_buffer.c \
				free_buffer.c \
				clean_buffer.c \
				realloc_buffer_content.c			
				print_buffer.c \
				add_character_to_buffer.c
BUFFER_OBJECTS = \
				malloc_buffer.o \
				free_buffer.o \
				clean_buffer.o \
				realloc_buffer_content.o \
				print_buffer.o \
				add_character_to_buffer.o

all: client server

client:
	$(CC) client.c -o $(CLIENT_NAME)

server: buffer
	$(CC) server.c -o $(SERVER_NAME)

buffer: $(BUFFER_OBJECTS)

$(BUFFER_OBJECTS): $(BUFFER_SOURCES)

clean:
	$(RM) client.o
	$(RM) server.o

fclean: clean
	$(RM) $(CLIENT_NAME)
	$(RM) $(SERVER_NAME)

re: fclean all

.PHONY: all client server buffer clean fclean re