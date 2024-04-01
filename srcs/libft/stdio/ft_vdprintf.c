/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 00:07:39 by shmorish          #+#    #+#             */
/*   Updated: 2024/02/26 14:53:08 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_stdio.h"

static int	sort_format(int fd, va_list args, const char format);

int	ft_vdprintf(int fd, const char *format, va_list args)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			ft_putchar_fd(format[i++], fd);
			count++;
		}
		else
		{
			count += sort_format(fd, args, format[i + 1]);
			i += 2;
		}
	}
	return (count);
}

static int	ft_puthex(unsigned long num, int uppercase, int fd)
{
	char	*hex_digits;
	int		len;

	len = 0;
	hex_digits = "0123456789abcdef";
	if (uppercase)
		hex_digits = "0123456789ABCDEF";
	if (num >= 16)
		len += ft_puthex(num / 16, uppercase, fd);
	len += ft_putchar_fd(hex_digits[num % 16], fd);
	return (len);
}

static int	ft_putptr(void *ptr, int fd)
{
	long	len;

	len = 0;
	len += ft_putstr_fd("0x", fd);
	len += ft_puthex((unsigned long)ptr, 0, fd);
	return (len);
}

static int	sort_format(int fd, va_list args, const char format)
{
	if (format == 'c')
		return (ft_putchar_fd(va_arg(args, int), fd));
	else if (format == 's')
		return (ft_putstr_fd(va_arg(args, char *), fd));
	else if (format == 'p')
		return (ft_putptr(va_arg(args, void *), fd));
	else if (format == 'i' || format == 'd')
		return (ft_putnbr_fd(va_arg(args, int), fd));
	else if (format == 'u')
		return (ft_putunbr_fd(va_arg(args, unsigned int), fd));
	else if (format == 'x' || format == 'X')
		return (ft_puthex(va_arg(args, unsigned int), (format == 'X'), fd));
	else if (format == '%')
		return (ft_putchar_fd('%', fd));
	return (0);
}
