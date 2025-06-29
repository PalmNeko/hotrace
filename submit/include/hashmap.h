/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 15:46:19 by tookuyam          #+#    #+#             */
/*   Updated: 2025/06/28 22:40:03 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHMAP_H
# define HASHMAP_H

# include "hotstring.h"
# include <stddef.h>

typedef struct s_hashnode
{
	t_hotstring		key;
	t_hotstring		value;
}	t_hashnode;

typedef struct s_hashmap
{
	t_hashnode	*table;
	size_t		size;
	size_t		max_size;
	size_t		max_elm_size;
}	t_hashmap;

typedef enum e_hashmap_error
{
	HASHMAP_OK,
	HASHMAP_DUPLICATED,
	HASHMAP_ERROR,
	HASHMAP_OVER_HOP,
	HASHMAP_ENOMEM,
}	t_ehashmap;

size_t		hash(t_hotstring key);
size_t		calc_start_index(
				size_t hash_value, size_t max_size, size_t elm_size);

/** publish */
t_hashmap	*hmap_new_hashmap(size_t size);
void		hmap_destroy_hashmap(t_hashmap **map);
t_ehashmap	hmap_add_value(t_hashmap **map, t_hotstring key, t_hotstring value);
t_hashnode	*hmap_get_node(t_hashmap *map, t_hotstring key);

/** hashmap */
int			get_from_hashmap(t_hashmap *map, t_hotstring key);
void		free_hashmap(t_hashmap *map);
t_ehashmap	extend_hashmap(t_hashmap **map, size_t additional_size);
t_hashmap	*create_hashmap(size_t size);
int			init_hashmap(t_hashmap	*map, size_t size);

/** hashnode list */
t_hashnode	*create_hashnode_list(size_t size);
void		free_hashnode_list(t_hashnode *node_list, size_t size);

/** hashnode */
void		free_hashnode(t_hashnode *const node);
int			add_hashnode(t_hashmap *map, t_hotstring key, t_hotstring value);
t_hashnode	*get_hashnode(t_hashmap *map, t_hotstring key);
bool		is_empty_hashnode(const t_hashnode *node);
t_hashnode	*next_hashnode(t_hashmap *map, size_t *index, size_t times);
void		assign_hashnode(
				t_hashnode *node, t_hotstring key, t_hotstring value);

#endif
