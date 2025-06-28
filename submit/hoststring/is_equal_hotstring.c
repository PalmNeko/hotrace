/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_equal_hotstring.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 19:55:53 by tookuyam          #+#    #+#             */
/*   Updated: 2025/06/28 19:57:28 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotstring.h"
#include "utils.h"

bool	is_equal_hotstring(t_hotstring str1, t_hotstring str2)
{
	return (ft_strequal(str1, str2));
}
