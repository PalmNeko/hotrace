/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 15:37:18 by tookuyam          #+#    #+#             */
/*   Updated: 2025/06/28 23:24:23 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"
#include "utils.h"
#include <unistd.h>
#include <errno.h>
#include <stdio.h>

int	main(void)
{
	t_hashmap	*map;
	t_hashnode	*node;

	map = hmap_new_hashmap(1);
	if (map == NULL)
	{
		perror("hashmap new");
		return (1);
	}
	if (hmap_add_value(&map, "key1", "value1\n") > HASHMAP_ERROR
		|| hmap_add_value(&map, "key2", "value2\n") > HASHMAP_ERROR
		|| hmap_add_value(&map, "key3", "value3\n") > HASHMAP_ERROR
		|| hmap_add_value(&map, "key4", "value4\n") > HASHMAP_ERROR
		|| hmap_add_value(&map, "key5", "value5\n") > HASHMAP_ERROR
		|| hmap_add_value(&map, "key6", "value6\n") > HASHMAP_ERROR
		|| hmap_add_value(&map, "key7", "value7\n") > HASHMAP_ERROR
		|| hmap_add_value(&map, "key8", "value8\n") > HASHMAP_ERROR
		|| hmap_add_value(&map, "key9", "value9\n") > HASHMAP_ERROR
		|| hmap_add_value(&map, "key10", "value10\n") > HASHMAP_ERROR
		|| hmap_add_value(&map, "key11", "value11\n") > HASHMAP_ERROR)
	{
		perror("hashmap add value");
		return (1);
	}
	printf("%zu %zu\n", map->size, map->max_size);
	node = hmap_get_node(map, "key3");
	if (node != NULL)
		print_hotstring(node->value);
	else
		perror("hashmap get node");

	char a = ' ';
	const int size = 35;
	int values[size];
	for (int i = 0; i < size; i++)
		values[i] = 0;
	printf("range: %d\n", '~' - ' ');
	while (' ' <= a && a <= '~')
	{
		char c[200];
		for (int i = 0; i < 199; i++)
			c[i] = 'x';
		c[68] = a;
		c[199] = '\0';
		size_t index = hash(c) % size;
		values[index]++;
		printf("%s: %zu\n", c, index);
		a++;
	}

	int i = 0;
	while (i < size)
	{
		if (values[i] > 1)
			printf("hash %d: %d\n", i, values[i]);
		i++;
	}
	return (0);
}
