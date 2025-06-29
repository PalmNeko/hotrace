/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_stdin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 17:51:53 by kitsuki           #+#    #+#             */
/*   Updated: 2025/06/28 20:26:59 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline_stdin.h"

static ssize_t	search_newline(const char *str)
{
	ssize_t	len;

	if (str == NULL)
		return (-1);
	len = 0;
	while (str[len] != '\0')
	{
		if (str[len] == '\n')
			return (len);
		len++;
	}
	return (-1);
}

static char	*get_strline(char **buffer, ssize_t size)
{
	char		*tmp;
	char		*ret;

	if (*(*buffer + size + 1) == '\0')
		tmp = NULL;
	else
	{
		tmp = ft_strdup(*buffer + size + 1);
		if (tmp == NULL)
			return (NULL);
	}
	ret = *buffer;
	ret[size + 1] = '\0';
	*buffer = tmp;
	return (ret);
}

char	*readline_stdin(char **buffer)
{
	static char	stack[READ_BUF + 1];
	ssize_t		size;
	char		*tmp;

	while (true)
	{
		size = search_newline(*buffer);
		if (size >= 0)
			return (get_strline(buffer, size));
		size = read(STDIN_FILENO, stack, READ_BUF);
		if (size < 0)
			return (NULL);
		else if (size == 0)
		{
			tmp = *buffer;
			*buffer = NULL;
			return (tmp);
		}
		stack[size] = '\0';
		tmp = ft_strjoin(*buffer, stack);
		if (tmp == NULL)
			return (NULL);
		free(*buffer);
		*buffer = tmp;
	}
}
