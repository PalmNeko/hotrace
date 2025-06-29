/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_add_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuki <itsuki@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-29 09:08:32 by itsuki            #+#    #+#             */
/*   Updated: 2025-06-29 09:08:32 by itsuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

static t_input_status	try_add_value(t_hashmap **map, char *key, char *value)
{
	t_ehashmap	status;

	status = hmap_add_value(map, key, value);
	if (status >= HASHMAP_ERROR)
	{
		free(key);
		free(value);
		return (ERROR);
	}
	else if (status == HASHMAP_DUPLICATED)
	{
		free(key);
		free(value);
	}
	return (CONTINUE);
}

t_input_status	handle_add_value(t_hashmap **map, char **buf)
{
	char	*key;
	char	*value;

	key = readline_stdin(buf);
	if (key == NULL || *key == '\0')
	{
		if (key != NULL)
			free(key);
		return (ERROR);
	}
	else if (*key == '\n')
	{
		free(key);
		return (FINISH);
	}
	value = readline_stdin(buf);
	if (value == NULL || *value == '\0')
	{
		if (value != NULL)
			free(value);
		free(key);
		return (ERROR);
	}
	*(key + ft_strlen(key) - 1) = '\0';
	return (try_add_value(map, key, value));
}
