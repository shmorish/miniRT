/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmorish <shmorish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 05:23:12 by shmorish          #+#    #+#             */
/*   Updated: 2024/02/26 03:16:19 by shmorish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_stdio.h"

int	ft_putnbr_fd(int num, int fd)
{
	int	len;

	len = 0;
	if (num == INT_MIN)
	{
		ft_putstr_fd("-2147483648", fd);
		return (11);
	}
	if (num < 0)
	{
		len = ft_putchar_fd('-', fd);
		num = -num;
	}
	if (num >= 10)
		len += ft_putnbr_fd(num / 10, fd);
	len += ft_putchar_fd(num % 10 + '0', fd);
	return (len);
}

int	ft_putunbr_fd(unsigned int num, int fd)
{
	int	len;

	len = 0;
	if (num >= 10)
		len += ft_putunbr_fd(num / 10, fd);
	len += ft_putchar_fd(num % 10 + '0', fd);
	return (len);
}
