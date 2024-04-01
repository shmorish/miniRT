/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 20:31:51 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/01 20:35:02 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdio.h>
# include "libft.h"

// print_error.c
void	print_error(char *str);
void	print_perror(char *str);
void	print_error_and_exit(char *str);
void	print_perror_and_exit(char *str);

#endif
