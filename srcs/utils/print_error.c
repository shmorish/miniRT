/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 20:31:28 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/01 21:27:32 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	print_error(char *str)
{
	ft_putstr_fd("ERROR: ", 2);
	ft_putstr_fd(str, 2);
	ft_putchar_fd('\n', 2);
}

void	print_perror(char *str)
{
	ft_putstr_fd("ERROR: ", 2);
	perror(str);
}

void	print_error_and_exit(char *str)
{
	print_error(str);
	exit(1);
}

void	print_perror_and_exit(char *str)
{
	print_perror(str);
	exit(1);
}

void	print_error_with_context_and_exit(char *str1, char *str2)
{
	ft_putstr_fd("ERROR: ", 2);
	ft_putstr_fd(str1, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(str2, 2);
	ft_putchar_fd('\n', 2);
	exit(1);
}
