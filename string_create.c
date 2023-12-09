/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 10:45:23 by bhildebr          #+#    #+#             */
/*   Updated: 2023/12/08 10:53:43 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

t_string	string_create(void)
{
	t_string	string;

	string = memory_create(sizeof(struct s_string));
	string->length = 0;
	string->size = 1 * sizeof(char);
	string->content = memory_create(string->size);
	string->content[0] = '\0';
	return (string);
}