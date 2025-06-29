/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maemran <maemran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:57:49 by maemran           #+#    #+#             */
/*   Updated: 2024/09/05 12:26:30 by maemran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		size;
	char	*string;

	start = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[start] != '\0' && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1) - 1;
	while (end > start && ft_strchr(set, s1[end]))
		end--;
	size = end - start + 1;
	string = malloc(size + 1);
	if (string == NULL)
		return (NULL);
	string = (char *)ft_memcpy(string, s1 + start, size);
	string[size] = '\0';
	return (string);
}
/*
int	main(void)
{
	char	*string;
	char	*set;

	string = "abcmohammadabc";
	set = "abc";
	printf("%s", ft_strtrim(string, set));
}
*/
