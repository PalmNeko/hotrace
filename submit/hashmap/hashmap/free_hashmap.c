/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_hashmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 19:34:54 by tookuyam          #+#    #+#             */
/*   Updated: 2025/06/29 21:31:14 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"
#include <stdlib.h>

void	free_hashmap(t_hashmap *map, bool copyed)
{
	if (map == NULL)
		return ;
	if (map->table != NULL)
		free_hashnode_list(map->table, map->max_size * map->max_elm_size,
			copyed);
	free(map);
	map = NULL;
}
