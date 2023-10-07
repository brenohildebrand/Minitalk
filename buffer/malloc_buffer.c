/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_buffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:32:44 by bhildebr          #+#    #+#             */
/*   Updated: 2023/09/14 06:24:52 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer.h"

int	malloc_buffer(t_buffer **buffer_address)
{
	*buffer_address = malloc(sizeof(t_buffer));
	if (*buffer_address == NULL)
		return (ERROR);
	(*buffer_address)->content = (char *)malloc(1 * sizeof(char));
	if ((*buffer_address)->content == NULL)
		return (ERROR);
	(*buffer_address)->current_length = 0;
	(*buffer_address)->max_length = 1;
	return (SUCCESS);
}
