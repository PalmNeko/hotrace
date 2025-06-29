/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 19:10:10 by tookuyam          #+#    #+#             */
/*   Updated: 2025/06/29 23:17:23 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotstring.h"
#include <stddef.h>

size_t	hash(t_hotstring key)
{
	const char	*str;
	size_t		hash;

	str = key;
	hash = 14695981039346656037UL;
	while (*str)
	{
		hash ^= (unsigned char)(*str++);
		hash *= 1099511628211UL;
	}
	return (hash);
}
