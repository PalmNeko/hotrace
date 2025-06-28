/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 20:00:59 by kitsuki           #+#    #+#             */
/*   Updated: 2025/06/28 20:27:17 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline_stdin.h"

size_t	ft_strlen(const char *str)
{
	size_t	ret;

	if (str == NULL)
		return (0);
	ret = 0;
	while (str[ret] != '\0')
		ret++;
	return (ret);
}

char	*ft_strdup(const char *str)
{
	char	*ret;
	size_t	tmp;
	size_t	len;

	len = ft_strlen(str);
	ret = malloc(len + 1);
	if (ret == NULL)
		return (NULL);
	tmp = 0;
	while (tmp < len)
	{
		ret[tmp] = str[tmp];
		tmp++;
	}
	ret[len] = '\0';
	return (ret);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	tmp;
	char	*ret;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ret = malloc(s1_len + s2_len + 1);
	if (ret == NULL)
		return (NULL);
	tmp = 0;
	while (tmp < s1_len)
	{
		ret[tmp] = s1[tmp];
		tmp++;
	}
	while (tmp < s1_len + s2_len)
	{
		ret[tmp] = s2[tmp - s1_len];
		tmp++;
	}
	ret[tmp] = '\0';
	return (ret);
}
