/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hmap_add_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 21:21:24 by tookuyam          #+#    #+#             */
/*   Updated: 2025/06/29 23:05:01 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"

t_ehashmap	hmap_add_value(t_hashmap **map, t_hotstring key, t_hotstring value)
{
	t_ehashmap	add_result;
	size_t		additional_size;

	if (map == NULL || *map == NULL)
		return (HASHMAP_ERROR);
	add_result = add_hashnode(*map, key, value);
	additional_size = (*map)->max_size / 2 * 2 + 1;
	while (add_result == HASHMAP_OVER_HOP)
	{
		add_result = extend_hashmap(map, additional_size);
		if (add_result == HASHMAP_ENOMEM)
		{
			free_hashmap(*map, false);
			*map = NULL;
			return (HASHMAP_ENOMEM);
		}
		add_result = add_hashnode(*map, key, value);
		additional_size += 2;
	}
	return (add_result);
}
