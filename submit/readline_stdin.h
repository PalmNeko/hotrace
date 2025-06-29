/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_stdin.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 20:26:01 by kitsuki           #+#    #+#             */
/*   Updated: 2025/06/28 20:26:25 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READLINE_STDIN_H
# define READLINE_STDIN_H

# include <stddef.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>

# define READ_BUF 20

size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *str);
char	*ft_strjoin(const char *s1, const char *s2);
char	*readline_stdin(char **buffer);

#endif
