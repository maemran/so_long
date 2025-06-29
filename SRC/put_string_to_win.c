/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_string_to_win.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maemran <maemran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:08:50 by maemran           #+#    #+#             */
/*   Updated: 2025/01/04 16:08:50 by maemran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*ft_string(int moves)
{
	char	*s;
	char	*string;
	char	*msg;

	s = "Number of Moves: ";
	string = ft_itoa(moves);
	if (string == NULL)
		return (NULL);
	msg = ft_strjoin (s, string);
	free(string);
	if (msg == NULL)
		return (NULL);
	return (msg);
}

void	put_string_to_win(t_data *data, int moves)
{
	char	*string;

	string = ft_string(moves);
	if (string == NULL)
	{
		ft_printf("Error allocating memory\n");
		ft_exit(data, 0, 1);
	}
	mlx_string_put(data->mlx, data->win, 10, 20, 0x0000FF00, string);
	free(string);
}

int	check_m(t_data *data)
{
	int	i;
	int	j;
	int	m;

	i = 0;
	m = 0;
	while (data->string[i])
	{
		j = 0;
		while (data->string[i][j] != '\0')
		{
			if (data->string[i][j] == 'M')
				m++;
			j++;
		}
		i++;
	}
	return (m);
}

int	close_window(t_data *data)
{
	ft_exit(data, 0, 0);
	return (0);
}

void	exit_pos(t_data *data, int n, t_map *map)
{
	if (n == 0 && c_check(data) == 0
		&& data->string[data->i_e][data->j_e] != 'P')
		data->string[data->i_e][data->j_e] = 'E';
	else if (n == 1)
	{
		free(map);
		ft_printf("Character not allowed\n");
		ft_exit(data, 0, 1);
	}
}
