/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maemran <maemran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:11:43 by maemran           #+#    #+#             */
/*   Updated: 2024/09/03 12:58:12 by maemran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*string;
	int		length;

	string = malloc(ft_strlen(s) + 1);
	length = 0;
	if (string == NULL)
		return (NULL);
	while (s[length] != '\0')
	{
		string[length] = s[length];
		length++;
	}
	string[length] = '\0';
	return (string);
}
/*
int	main(void)
{
	const char	*s = "mohammad";

	printf("%s", ft_strdup(s));
}
*/
