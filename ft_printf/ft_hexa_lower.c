/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_lower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maemran < maemran@student.42amman.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 18:39:08 by maemran           #+#    #+#             */
/*   Updated: 2025/06/29 18:39:12 by maemran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa_lower(unsigned long nb)
{
	int	i;

	i = 0;
	if (nb >= 16)
	{
		i += ft_hexa_lower(nb / 16);
		i += ft_hexa_lower(nb % 16);
	}
	else
	{
		i += write(1, &"0123456789abcdef"[nb], 1);
		return (i);
	}
	return (i);
}
