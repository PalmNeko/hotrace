/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_hashnode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 19:49:06 by tookuyam          #+#    #+#             */
/*   Updated: 2025/06/28 21:10:06 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"
#include "utils.h"
#include <stddef.h>

t_hashnode	*create_hashnode(t_hotstring key, t_hotstring value)
{
	t_hashnode	*node;

	node = ft_calloc(sizeof(t_hashnode));
	if (node == NULL)
		return (NULL);
	node->key = key;
	node->value = value;
	return (node);
}
