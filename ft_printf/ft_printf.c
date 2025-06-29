/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maemran < maemran@student.42amman.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 18:39:43 by maemran           #+#    #+#             */
/*   Updated: 2025/06/29 18:39:45 by maemran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_type(va_list args, char c)
{
	int	i;

	i = 0;
	if (c == 'c')
		i += ft_putchar(va_arg(args, int));
	else if (c == 's')
		i += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		i += ft_pointer(va_arg(args, unsigned long int));
	else if (c == 'd' || c == 'i')
		i += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		i += ft_putnbr_u(va_arg(args, unsigned int));
	else if (c == 'x')
		i += ft_hexa_lower(va_arg(args, unsigned int));
	else if (c == 'X')
		i += ft_hexa_upper(va_arg(args, unsigned int));
	else if (c == '%')
		i += ft_putchar('%');
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		index;

	va_start(arg, str);
	i = 0;
	index = 0;
	while (str && str[index])
	{
		if (str[index] == '%' && str[index + 1])
		{
			index++;
			i += ft_type(arg, str[index]);
		}
		else
			i += write(1, &str[index], 1);
		index++;
	}
	va_end(arg);
	return (i);
}

// int main(void)
// {
//     char *str = "Hello, World!";
//     char ch = 'A';
//     unsigned int u_n = 4294967295;
//     int i_n = -42;
//     void *ptr = &str;
//     unsigned int hex_n = 255;

//	   printf("Test case for string\n");
//     printf("Standard printf: %s\n", str);
//     ft_printf("Custom ft_printf: %s\n\n", str);

//     printf("Test case for char\n");
//     printf("Standard printf: %c\n", ch);
//     ft_printf("Custom ft_printf: %c\n\n", ch);

//     printf("Test case for unsigned decimal\n");
//     printf("Standard printf: %u\n", u_n);
//     ft_printf("Custom ft_printf: %u\n\n", u_n);

//     printf("Test case for lowercase hex\n");
//     printf("Standard printf: %x\n", hex_n);
//     ft_printf("Custom ft_printf: %x\n\n", hex_n);

//     printf("Test case for uppercase hex\n");
//     printf("Standard printf: %X\n", hex_n);
//     ft_printf("Custom ft_printf: %X\n\n", hex_n);

// 	   printf("Test case for pointer\n");
//     printf("Standard printf: %p\n", ptr);
//     ft_printf("Custom ft_printf: %p\n\n", ptr);

//     printf("Test case for int\n");
//     printf("Standard printf: %i\n", i_n);
//     ft_printf("Custom ft_printf: %i\n\n", i_n);

//     printf("Test case for decimal\n");
//     printf("Standard printf: %d\n", i_n);
//     ft_printf("Custom ft_printf: %d\n", i_n);

//     return (0);
// }
