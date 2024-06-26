/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmorish <shmorish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:25:57 by morishitash       #+#    #+#             */
/*   Updated: 2024/02/26 10:13:42 by shmorish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ctype.h"

int	ft_isspace(int c)
{
	return (ft_isblank(c) || (10 <= c && c <= 13));
}
