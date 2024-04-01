/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_split_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 04:23:51 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/02 04:27:00 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

size_t	count_split(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

void	is_split_count(char **split, size_t expected, char *err_msg)
{
	size_t	cnt;

	cnt = count_split(split);
	if (cnt != expected)
		print_error_and_exit(err_msg);
}
