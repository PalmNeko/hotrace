/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hmap_destroy_hashmap.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 21:33:54 by tookuyam          #+#    #+#             */
/*   Updated: 2025/06/29 21:25:08 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"

void	hmap_destroy_hashmap(t_hashmap **map)
{
	if (map == NULL)
		return ;
	free_hashmap(*map, false);
	*map = NULL;
	return ;
}
