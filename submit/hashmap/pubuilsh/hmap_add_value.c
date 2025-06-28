/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hmap_add_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 21:21:24 by tookuyam          #+#    #+#             */
/*   Updated: 2025/06/28 23:22:53 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"

t_ehashmap	hmap_add_value(t_hashmap **map, t_hotstring key, t_hotstring value)
{
	t_ehashmap	add_result;

	if (map == NULL || *map == NULL)
		return (HASHMAP_ERROR);
	add_result = add_hashnode(*map, key, value);
	while (add_result == HASHMAP_OVER_HOP)
	{
		add_result = extend_hashmap(map, (*map)->max_size + 1);
		if (add_result == HASHMAP_ENOMEM)
		{
			free_hashmap(*map);
			*map = NULL;
			return (HASHMAP_ENOMEM);
		}
		add_result = add_hashnode(*map, key, value);
	}
	return (add_result);
}
