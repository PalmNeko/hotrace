/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_hashnode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 20:27:17 by tookuyam          #+#    #+#             */
/*   Updated: 2025/06/28 20:27:29 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"

void	assign_hashnode(t_hashnode *node, t_hotstring key, t_hotstring value)
{
	if (node == NULL)
		return ;
	node->key = key;
	node->value = value;
}
