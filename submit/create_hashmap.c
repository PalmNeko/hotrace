/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_hashmap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 19:16:59 by tookuyam          #+#    #+#             */
/*   Updated: 2025/06/28 21:47:00 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"
#include <stdlib.h>

t_hashmap	*create_hashmap(size_t size)
{
	t_hashmap	*map;

	if (size <= 0)
		return (NULL);
	map = malloc(sizeof(t_hashmap));
	if (!map)
		return (NULL);
	if (init_hashmap(map, size) == -1)
	{
		free(map);
		return (NULL);
	}
	return (map);
}
