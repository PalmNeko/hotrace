/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_hashnode_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 19:39:45 by tookuyam          #+#    #+#             */
/*   Updated: 2025/06/29 21:30:21 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"
#include <stdlib.h>

void	free_hashnode_list(t_hashnode *node_list, size_t size, bool copyed)
{
	size_t	i;

	if (node_list == NULL)
		return ;
	i = 0;
	if (!copyed)
	{
		while (i < size)
		{
			free_hashnode(&node_list[i]);
			i++;
		}
	}
	free(node_list);
	node_list = NULL;
}
