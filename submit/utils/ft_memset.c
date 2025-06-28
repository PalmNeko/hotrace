/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 19:31:34 by tookuyam          #+#    #+#             */
/*   Updated: 2025/06/28 19:32:13 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/** please improve this function */
void	*ft_memset(void *ptr, int value, size_t size)
{
	unsigned char	*byte_ptr;
	size_t			i;

	if (ptr == NULL || size == 0)
		return (ptr);
	byte_ptr = (unsigned char *)ptr;
	i = 0;
	while (i < size)
	{
		byte_ptr[i] = (unsigned char)value;
		i++;
	}
	return (ptr);
}
