/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_empty_hashnode.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 20:18:28 by tookuyam          #+#    #+#             */
/*   Updated: 2025/06/28 20:18:35 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"

bool	is_empty_hashnode(const t_hashnode *node)
{
	if (node == NULL)
		return (true);
	if (node->key == NULL || node->value == NULL)
		return (true);
	return (false);
}
