/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_hashnode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 20:19:00 by tookuyam          #+#    #+#             */
/*   Updated: 2025/06/28 22:51:06 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"

t_hashnode	*next_hashnode(t_hashmap *map, size_t *index, size_t times)
{
	if (map == NULL || index == NULL || times >= map->max_elm_size)
		return (NULL);
	(*index)++;
	return (&map->table[*index]);
}
