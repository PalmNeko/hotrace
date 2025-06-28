/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_hashnode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 19:50:26 by tookuyam          #+#    #+#             */
/*   Updated: 2025/06/28 22:40:21 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"
#include "utils.h"
#include <stdlib.h>

static int	insert_hashnode(
				t_hashmap *map,
				size_t index,
				t_hotstring key,
				t_hotstring value);

int	add_hashnode(t_hashmap *map, t_hotstring key, t_hotstring value)
{
	size_t		index;
	size_t		hash_value;
	int			add_result;

	hash_value = hash(key);
	index = calc_start_index(hash_value, map->max_size);
	add_result = insert_hashnode(map, index, key, value);
	return (add_result);
}

static int	insert_hashnode(
				t_hashmap *map,
				size_t index,
				t_hotstring key,
				t_hotstring value)
{
	t_hashnode	*node;
	size_t		times;

	times = 0;
	node = &map->table[index];
	while (node != NULL)
	{
		if (is_equal_hotstring(node->key, key))
		{
			assign_hashnode(node, key, value);
			return (HASHMAP_DUPLICATED);
		}
		if (is_empty_hashnode(node))
		{
			assign_hashnode(node, key, value);
			map->size++;
			return (HASHMAP_OK);
		}
		node = next_hashnode(map, &index, ++times);
		if (times > 10)
			return (HASHMAP_OVER_HOP);
	}
	return (HASHMAP_OVER_HOP);
}
