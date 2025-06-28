/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 19:22:56 by tookuyam          #+#    #+#             */
/*   Updated: 2025/06/28 21:50:29 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stddef.h>
# include <stdbool.h>

void	*ft_calloc(size_t size);
void	*ft_memset(void *ptr, int value, size_t size);
bool	ft_strequal(const char *str1, const char *str2);
void	ft_putstr_fd(int fd, const char *str);

#endif
