/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctype.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 22:59:27 by shmorish          #+#    #+#             */
/*   Updated: 2024/02/26 16:18:46 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CTYPE_H
# define FT_CTYPE_H

# include <limits.h>

int	ft_isalnum(int c);
int	ft_isalpha(int c);
int	ft_isascii(int c);
int	ft_isblank(int c);
int	ft_isdigit(int c);
int	ft_isdouble(char *str);
int	ft_isint(char *str);
int	ft_islower(int c);
int	ft_isnumber(int c);
int	ft_isprint(int c);
int	ft_isspace(int c);
int	ft_isstrspace(char *str);
int	ft_isupper(int c);
int	ft_tolower(int c);
int	ft_toupper(int c);

#endif