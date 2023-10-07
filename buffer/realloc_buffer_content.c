/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_buffer_content.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:33:16 by bhildebr          #+#    #+#             */
/*   Updated: 2023/09/18 14:57:00 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer.h"

int	realloc_buffer_content(
	t_buffer *buffer,
	unsigned long original_length,
	unsigned long new_length
){
	char			*new_content;
	unsigned long	i;

	new_content = (char *)malloc(new_length);
	if (new_content == NULL)
		return (ERROR);
	i = 0;
	while (i < original_length)
	{
		new_content[i] = buffer->content[i];
		i++;
	}
	free(buffer->content);
	buffer->content = new_content;
	buffer->max_length = new_length;
	return (SUCCESS);
}
