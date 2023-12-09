/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_append_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 10:48:41 by bhildebr          #+#    #+#             */
/*   Updated: 2023/12/08 22:12:24 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

void	string_append_char(t_string *string, char character)
{
	if ((*string)->length + 2 > (*string)->size)
		string_realloc(string);
	(*string)->content[(*string)->length] = character;
	(*string)->length++;
	(*string)->content[(*string)->length] = '\0';
}