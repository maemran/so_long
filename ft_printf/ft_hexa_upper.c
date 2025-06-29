/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_upper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maemran < maemran@student.42amman.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 18:39:19 by maemran           #+#    #+#             */
/*   Updated: 2025/06/29 18:39:21 by maemran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa_upper(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb >= 16)
	{
		i += ft_hexa_upper(nb / 16);
		i += ft_hexa_upper(nb % 16);
	}
	else
	{
		i += write(1, &"0123456789ABCDEF"[nb], 1);
		return (i);
	}
	return (i);
}
