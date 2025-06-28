/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_hashnode_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 19:39:45 by tookuyam          #+#    #+#             */
/*   Updated: 2025/06/28 21:29:06 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"
#include <stdlib.h>

void	free_hashnode_list(t_hashnode *node_list, size_t size)
{
	size_t	i;

	if (node_list == NULL)
		return ;
	i = 0;
	while (i < size)
	{
		free_hashnode(&node_list[i]);
		i++;
	}
	free(node_list);
	node_list = NULL;
}
