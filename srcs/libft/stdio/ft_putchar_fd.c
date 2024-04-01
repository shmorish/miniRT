/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmorish <shmorish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 05:15:00 by shmorish          #+#    #+#             */
/*   Updated: 2024/02/26 03:02:10 by shmorish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_stdio.h"

int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}
