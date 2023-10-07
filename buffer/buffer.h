/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:15:10 by bhildebr          #+#    #+#             */
/*   Updated: 2023/10/07 03:07:55 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_H
# define BUFFER_H

# include <stdlib.h>
# include <unistd.h>

# ifndef SUCCESS
#  define SUCCESS 0
# endif

# ifndef ERROR
#  define ERROR -1
# endif

typedef struct s_buffer {
	unsigned long	current_length;
	unsigned long	max_length;
	char			*content;
}	t_buffer;

int	malloc_buffer(t_buffer **buffer_address);
int	realloc_buffer_content(
		t_buffer *buffer,
		unsigned long original_length,
		unsigned long new_length
		);
int	add_buffer_to_buffer(t_buffer *buffer, t_buffer *source_buffer);
int	free_buffer(t_buffer *buffer);
int	add_character_to_buffer(t_buffer *buffer, char character);
int	append_cstring_to_buffer(t_buffer *buffer, char *string);
int	append_character_to_buffer(t_buffer *buffer, char character);
int	prepend_character_to_buffer(t_buffer *buffer, char character);
int	add_cstring_to_buffer(t_buffer *buffer, char *string);
int	add_unsigned_character_to_buffer(t_buffer *buffer, unsigned char character);
int	print_buffer(t_buffer *buffer);
int	clean_buffer(t_buffer *buffer);

#endif