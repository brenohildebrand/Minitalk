/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_realloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 10:51:15 by bhildebr          #+#    #+#             */
/*   Updated: 2023/12/08 22:16:07 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

void	string_realloc(t_string *string)
{
	char			*new_content;
	unsigned int	i;

	new_content = memory_create(2 * (*string)->size);
	i = 0;
	while (i < (*string)->length)
	{
		new_content[i] = (*string)->content[i];
		i++;
	}
	new_content[i] = '\0';
	free((*string)->content);
	(*string)->content = new_content;
	(*string)->size *= 2;
}