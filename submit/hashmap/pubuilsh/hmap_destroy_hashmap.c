/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hmap_destroy_hashmap.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 21:33:54 by tookuyam          #+#    #+#             */
/*   Updated: 2025/06/28 21:34:39 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"

void	hmap_destroy_hashmap(t_hashmap **map)
{
	if (map == NULL)
		return ;
	free_hashmap(*map);
	*map = NULL;
	return ;
}
