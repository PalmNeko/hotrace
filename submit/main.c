/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 15:37:18 by tookuyam          #+#    #+#             */
/*   Updated: 2025/06/28 23:27:01 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include "utils.h"

static int	free_all(t_hashmap **map, char **buf)
{
	if (*map != NULL)
		hmap_destroy_hashmap(map);
	if (*buf != NULL)
	{
		free(*buf);
		*buf = NULL;
	}
	return (0);
}

static int	handle_error(t_hashmap **map, char **buf, const char *msg)
{
	free_all(map, buf);
	ft_putstr_fd(STDERR_FILENO, msg);
	return (1);
}

int	main(void)
{
	t_hashmap		*map;
	char			*buf;
	t_input_status	flag;

	buf = NULL;
	map = hmap_new_hashmap(1001);
	if (map == NULL)
		return (handle_error(&map, &buf, "error in: initialize map.\n"));
	while (true)
	{
		flag = handle_add_value(&map, &buf);
		if (flag == ERROR)
			return (handle_error(&map, &buf, "error in: add key-value.\n"));
		else if (flag == FINISH)
			break ;
	}
	while (true)
	{
		flag = handle_get_node(map, &buf);
		if (flag == ERROR)
			return (handle_error(&map, &buf, "error in: get value.\n"));
		else if (flag == FINISH)
			break ;
	}
	return (free_all(&map, &buf));
}
