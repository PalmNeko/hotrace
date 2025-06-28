/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_hashmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 19:34:54 by tookuyam          #+#    #+#             */
/*   Updated: 2025/06/28 21:06:27 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"
#include <stdlib.h>

void	free_hashmap(t_hashmap *map)
{
	if (map == NULL)
		return ;
	if (map->table != NULL)
		free_hashnode_list(map->table, map->max_size);
	free(map);
	map = NULL;
}
