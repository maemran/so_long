/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maemran < maemran@student.42amman.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 18:39:30 by maemran           #+#    #+#             */
/*   Updated: 2025/06/29 18:39:32 by maemran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointer(unsigned long int nb)
{
	int	i;

	i = 0;
	if (nb != 0)
	{
		i += ft_putstr("0x");
		i += ft_hexa_lower(nb);
	}
	else
		i += write(1, "(nil)", 5);
	return (i);
}
