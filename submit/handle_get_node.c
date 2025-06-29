/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_add_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuki <itsuki@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-29 09:10:06 by itsuki            #+#    #+#             */
/*   Updated: 2025-06-29 09:10:06 by itsuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include "utils.h"

static void	print_no_key(const char *key)
{
	ft_putstr_fd(STDOUT_FILENO, key);
	ft_putstr_fd(STDOUT_FILENO, ": Not found.\n");
}

t_input_status	handle_get_node(t_hashmap *map, char **buf)
{
	char			*key;
	t_input_status	status;
	size_t			len;
	t_hashnode		*node;

	key = readline_stdin(buf);
	if (key == NULL)
		return (ERROR);
	len = ft_strlen(key);
	status = CONTINUE;
	if (len == 0 || *(key + len - 1) != '\n')
		status = FINISH;
	else
		*(key + --len) = '\0';
	if (len != 0)
	{
		node = hmap_get_node(map, key);
		if (node != NULL)
			print_hotstring(node->value);
		else
			print_no_key(key);
	}
	free(key);
	return (status);
}
