/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 15:37:18 by tookuyam          #+#    #+#             */
/*   Updated: 2025/06/28 20:08:26 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

int	main(void)
{
	char	*buf;
	char	*input;
	size_t	len;

	buf = NULL;
	while (true)
	{
		input = readline_stdin(&buf);
		if (input == NULL)
		{
			if (buf != NULL)
				free(buf);
			return (1);
		}
		len = ft_strlen(input);
		write(STDOUT_FILENO, input, len);
		if (len != 0 && input[len - 1] != '\n')
			break ;
		free(input);
	}
	if (buf != NULL)
		free(buf);
	return (0);
}
