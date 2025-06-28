/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 21:49:09 by tookuyam          #+#    #+#             */
/*   Updated: 2025/06/28 21:51:04 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_fd(int fd, const char *str)
{
	size_t	len;

	if (str == NULL)
		return ;
	len = 0;
	while (str[len] != '\0')
		len++;
	write(fd, str, len);
}
