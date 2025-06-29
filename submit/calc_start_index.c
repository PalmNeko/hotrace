/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_start_index.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 22:39:16 by tookuyam          #+#    #+#             */
/*   Updated: 2025/06/28 22:39:56 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"

size_t	calc_start_index(size_t hash_value, size_t max_size, size_t elm_size)
{
	return ((hash_value % max_size) * elm_size);
}
