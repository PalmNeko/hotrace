/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extend_hashmap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 20:05:25 by tookuyam          #+#    #+#             */
/*   Updated: 2025/06/28 22:54:59 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"

static t_ehashmap	move_hashmap(
						t_hashmap *src,
						t_hashmap *dst);

// rehashmap
t_ehashmap	extend_hashmap(t_hashmap **map, size_t additional_size)
{
	t_hashmap	*new_map;
	size_t		new_size;
	t_ehashmap	add_result;

	if (map == NULL || additional_size == 0)
		return (HASHMAP_ERROR);
	new_size = (*map)->max_size + additional_size;
	new_map = create_hashmap(new_size);
	if (new_map == NULL)
		return (HASHMAP_ENOMEM);
	add_result = move_hashmap(*map, new_map);
	if (add_result >= HASHMAP_ERROR)
	{
		free_hashmap(new_map);
		return (add_result);
	}
	free_hashmap(*map);
	*map = new_map;
	return (HASHMAP_OK);
}

static t_ehashmap	move_hashmap(
							t_hashmap *src,
							t_hashmap *dst)
{
	size_t		i;
	t_ehashmap	add_result;

	i = 0;
	while (i < src->max_size * src->max_elm_size)
	{
		if (src->table[i].key != NULL)
		{
			add_result = add_hashnode(
					dst, src->table[i].key, src->table[i].value);
			if (add_result >= HASHMAP_ERROR)
				return (add_result);
		}
		i++;
	}
	return (HASHMAP_OK);
}
