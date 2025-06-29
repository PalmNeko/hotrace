/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_hashnode_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 19:47:36 by tookuyam          #+#    #+#             */
/*   Updated: 2025/06/28 21:28:58 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"
#include "utils.h"

t_hashnode	*create_hashnode_list(size_t size)
{
	return (ft_calloc(sizeof(t_hashnode) * size));
}
