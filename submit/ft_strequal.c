/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 19:56:22 by tookuyam          #+#    #+#             */
/*   Updated: 2025/06/28 22:19:34 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>

bool	ft_strequal(const char *str1, const char *str2)
{
	if (str1 == NULL || str2 == NULL)
		return (false);
	while (true)
	{
		if (*str1 != *str2)
			return (false);
		if (*str1 == '\0')
			return (true);
		str1++;
		str2++;
	}
	return (false);
}
