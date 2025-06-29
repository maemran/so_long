/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maemran < maemran@student.42amman.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 18:40:09 by maemran           #+#    #+#             */
/*   Updated: 2025/06/29 18:40:10 by maemran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_u(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb >= 10)
	{
		i = i + ft_putnbr_u(nb / 10);
	}
	i += ft_putchar(nb % 10 + '0');
	return (i);
}
