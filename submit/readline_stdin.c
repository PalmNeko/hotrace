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

static ssize_t	handle_read_stdin(char *stack)
{
	static ssize_t	closed_status = 1;
	ssize_t			size;

	if (closed_status <= 0)
		return (closed_status);
	size = read(STDIN_FILENO, stack, READ_BUF);
	if (size <= 0)
		closed_status = size;
	return (size);
}

char	*readline_stdin(char **buffer)
{
	char	stack[READ_BUF + 1];
	ssize_t	size;
	char	*tmp;

	while (true)
	{
		size = search_newline(*buffer);
		if (size >= 0)
			return (get_strline(buffer, size));
		size = handle_read_stdin(stack);
		if (size < 0)
			return (NULL);
		stack[size] = '\0';
		tmp = ft_strjoin(*buffer, stack);
		if (tmp == NULL)
			return (NULL);
		if (*buffer != NULL)
			free(*buffer);
		*buffer = NULL;
		if (size == 0)
			return (tmp);
		else
			*buffer = tmp;
	}
}
