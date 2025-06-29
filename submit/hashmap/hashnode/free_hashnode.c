/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_hashnode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 19:42:03 by tookuyam          #+#    #+#             */
/*   Updated: 2025/06/28 22:26:46 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"
#include <stdlib.h>

void	free_hashnode(t_hashnode *const node)
{
	if (node == NULL)
		return ;
	if (node->key != NULL)
		free(node->key);
	if (node->value != NULL)
		free(node->value);
}
