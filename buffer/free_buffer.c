/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_buffer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:33:27 by bhildebr          #+#    #+#             */
/*   Updated: 2023/09/14 06:24:41 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer.h"

int	free_buffer(t_buffer *buffer)
{
	free(buffer->content);
	free(buffer);
	return (SUCCESS);
}
