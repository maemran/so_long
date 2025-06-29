/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maemran < maemran@student.42amman.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 05:20:11 by maemran           #+#    #+#             */
/*   Updated: 2025/06/29 18:31:51 by maemran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	map_check_1(t_data *data, t_vars *vars)
{
	int		i;
	size_t	x;

	i = 1;
	x = ft_strlen(data->string[0]);
	while (data->string[i] != NULL)
	{
		if (x != ft_strlen(data->string[i]))
		{
			ft_printf("The map is not rectangular\n");
			free(vars);
			ft_exit(data, 1, 1);
		}
		i++;
	}
}

void	map_check_3(t_data *data, t_vars *vars, int i, int j)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->string[0][x] != '\0')
	{
		if (data->string[0][x] != '1' || data->string[i - 1][x] != '1')
		{
			ft_printf("There is a invalid char between a row of ones\n");
			free(vars);
			ft_exit(data, 1, 1);
		}
		x++;
	}
	while (data->string[y] != NULL)
	{
		if (data->string[y][0] != '1' || data->string[y][j - 1] != '1')
		{
			ft_printf("There is a invalid char between a column of ones.\n");
			free(vars);
			ft_exit(data, 1, 1);
		}
		y++;
	}
}

void	pe_check(t_data *data, t_vars *vars)
{
	int	c;
	int	i;
	int	j;

	c = 0;
	i = 0;
	while (data->string[i])
	{
		j = 0;
		while (data->string[i][j] != '\0')
		{
			if (data->string[i][j] == 'P' || data->string[i][j] == 'E')
				c++;
			j++;
		}
		i++;
	}
	if (c != 2)
	{
		ft_printf("Problem with character E OR P\n");
		free(vars);
		ft_exit(data, 1, 1);
	}
	c_nums(data, vars);
}

int	c_check(t_data *data)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	flag = 0;
	while (data->string[i] != NULL)
	{
		j = 0;
		while (data->string[i][j] != '\0')
		{
			if (data->string[i][j] == 'C')
				flag = 1;
			j++;
		}
		i++;
	}
	return (flag);
}

int	d_check(t_data *data)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	flag = 0;
	while (data->string[i] != NULL)
	{
		j = 0;
		while (data->string[i][j] != '\0')
		{
			if (data->string[i][j] == 'E')
				flag = 1;
			j++;
		}
		i++;
	}
	return (flag);
}
