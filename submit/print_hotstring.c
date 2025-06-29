/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hotstring.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 21:43:00 by tookuyam          #+#    #+#             */
/*   Updated: 2025/06/28 21:50:56 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotstring.h"
#include "utils.h"
#include <stddef.h>
#include <unistd.h>

void	print_hotstring(t_hotstring str)
{
	ft_putstr_fd(1, str);
}
