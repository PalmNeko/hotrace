/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hashmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 19:18:03 by tookuyam          #+#    #+#             */
/*   Updated: 2025/06/28 22:44:06 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"
#include "utils.h"
#include <stdlib.h>

int	init_hashmap(t_hashmap *map, size_t size)
{
	if (map == NULL)
		return (-1);
	map->table = NULL;
	map->size = 0;
	map->max_size = size;
	map->max_elm_size = 10;
	if (size <= 0)
		return (-1);
	map->table = create_hashnode_list(size * map->max_elm_size);
	if (map->table == NULL)
		return (-1);
	return (0);
}
