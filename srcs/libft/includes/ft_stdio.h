/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdio.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmorish <shmorish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 10:07:11 by shmorish          #+#    #+#             */
/*   Updated: 2024/02/26 10:10:38 by shmorish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDIO_H
# define FT_STDIO_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

# include <stddef.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include <stdarg.h>
# include "ft_stdlib.h"

int		ft_printf(const char *format, ...);
int		ft_putchar_fd(char c, int fd);
int		ft_putendl_fd(const char *s, int fd);
int		ft_putnbr_fd(int num, int fd);
int		ft_putstr_fd(char *str, int fd);
int		ft_putunbr_fd(unsigned int num, int fd);
int		ft_dprintf(int fd, const char *format, ...);
int		ft_vprintf(const char *format, va_list args);
int		ft_vdprintf(int fd, const char *format, va_list args);
char	*get_next_line(int fd);

#endif
