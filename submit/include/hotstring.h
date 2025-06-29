/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotstring.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 15:46:48 by tookuyam          #+#    #+#             */
/*   Updated: 2025/06/28 21:44:03 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTSTRING_H
# define HOTSTRING_H

# include <stdbool.h>

typedef char	*t_hotstring;

bool	is_equal_hotstring(t_hotstring str1, t_hotstring str2);
void	print_hotstring(t_hotstring str);

#endif
