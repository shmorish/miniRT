/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdlib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 10:09:53 by shmorish          #+#    #+#             */
/*   Updated: 2024/01/08 11:32:48 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDLIB_H
# define FT_STDLIB_H

# include <limits.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>

int			ft_abs(int n);
int			ft_atoi(const char *str);
long		ft_atol(const char *str);
long long	ft_atoll(const char *str);
void		*ft_calloc(size_t count, size_t size);
char		*ft_itoa(int n);
double		ft_atof(const char *str);
long		ft_strtol(const char *str);
void		*ft_xmalloc(size_t size);

#endif