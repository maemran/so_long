/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maemran <maemran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 13:35:27 by maemran           #+#    #+#             */
/*   Updated: 2024/09/01 19:55:07 by maemran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static int	ft_strlen(const char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
		length++;
	return (length);
}

char	*ft_strrchr(const char *s, int c)
{
	int				length;
	unsigned char	uc;

	length = ft_strlen(s);
	uc = (unsigned char)c;
	while (length >= 0)
	{
		if ((unsigned char)s[length] == uc)
			return ((char *)(s + length));
		length--;
	}
	return (NULL);
}
/*
int	main(void)
{
	printf("%s", ft_strrchr("mohammad ali emran",'p'));
}
*/
