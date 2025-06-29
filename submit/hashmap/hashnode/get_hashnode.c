/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hashnode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 19:53:04 by tookuyam          #+#    #+#             */
/*   Updated: 2025/06/28 22:44:28 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"

t_hashnode	*get_hashnode(t_hashmap *map, t_hotstring key)
{
	size_t		index;
	t_hashnode	*node;
	size_t		times;

	if (map == NULL || key == NULL)
		return (NULL);
	index = calc_start_index(hash(key), map->max_size, map->max_elm_size);
	node = &map->table[index];
	times = 0;
	while (node != NULL)
	{
		node = &map->table[index];
		if (is_empty_hashnode(node))
			return (NULL);
		if (is_equal_hotstring(node->key, key))
			return (node);
		next_hashnode(map, &index, times);
		times++;
	}
	return (NULL);
}
