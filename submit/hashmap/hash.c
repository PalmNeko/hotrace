/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 19:10:10 by tookuyam          #+#    #+#             */
/*   Updated: 2025/06/28 23:19:03 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotstring.h"
#include <stddef.h>

size_t	hash(t_hotstring key)
{
	const char	*str;
	size_t		hash;

	str = key;
	hash = 0;
	while (*str != '\0')
	{
		hash += (*str ^ 0x66C63);
		str++;
	}
	return (hash);
}
