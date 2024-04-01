/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdbl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmorish <shmorish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 05:23:47 by shmorish          #+#    #+#             */
/*   Updated: 2024/04/01 06:20:09 by shmorish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_stdio.h"

int	ft_putdbl_fd(double num, int fd)
{
    int	len;

    len = 0;
    if (num < 0)
    {
        len = ft_putchar_fd('-', fd);
        num = -num;
    }
    len += ft_putnbr_fd((int)num, fd);
    len += ft_putchar_fd('.', fd);
    num -= (int)num;
    num *= 1000000;
    len += ft_putnbr_fd((int)num, fd);
    return (len);
}
