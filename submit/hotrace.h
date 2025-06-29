/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 15:39:15 by tookuyam          #+#    #+#             */
/*   Updated: 2025/06/28 20:26:49 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# include "readline_stdin.h"
# include "hashmap.h"

typedef enum e_input_status
{
	CONTINUE,
	FINISH,
	ERROR
}	t_input_status;

/** handle input */
t_input_status	handle_add_value(t_hashmap **map, char **buf);
t_input_status	handle_get_node(t_hashmap *map, char **buf);

#endif
