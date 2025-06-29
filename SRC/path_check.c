/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maemran < maemran@student.42amman.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 05:40:26 by maemran           #+#    #+#             */
/*   Updated: 2025/06/29 18:32:00 by maemran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map[i]);
	free(map);
}

void	ft_exit(t_data *data, int n, int type)
{
	if (n == 0)
	{
		mlx_destroy_image(data->mlx, data->collect);
		mlx_destroy_image(data->mlx, data->door);
		mlx_destroy_image(data->mlx, data->empty);
		mlx_destroy_image(data->mlx, data->player);
		mlx_destroy_image(data->mlx, data->wall);
		mlx_destroy_image(data->mlx, data->fire);
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free_map(data->string);
		free(data->mlx);
		free(data);
		exit(type);
	}
	if (n == 1)
	{
		free_map(data->string);
		free(data);
		exit(type);
	}
}

void	flood_fill(char **tab, int y, int x)
{
	if (tab[y][x] == '1' || tab[y][x] == 'M')
		return ;
	if (tab[y][x] != 'F')
	{
		tab[y][x] = 'F';
		flood_fill(tab, y, x - 1);
		flood_fill(tab, y, x + 1);
		flood_fill(tab, y - 1, x);
		flood_fill(tab, y + 1, x);
	}
}

char	**map_copy(t_data *data, t_vars *vars)
{
	char	**map;
	int		i;

	i = 0;
	map = (char **)malloc(sizeof(char *) * ((vars->y) + 1));
	if (!(map))
	{
		free(vars);
		ft_exit(data, 1, 1);
	}
	while (data->string[i])
	{
		map[i] = ft_strdup(data->string[i]);
		if (map[i] == NULL)
		{
			while (i >= 0)
				free(map[i--]);
			free(vars);
			ft_exit(data, 1, 1);
		}
		i++;
	}
	map[i] = NULL;
	return (map);
}

void	valid_path(t_data *data, t_vars *vars)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	map = map_copy(data, vars);
	flood_fill(map, data->i_p, data->j_p);
	while (data->string[i])
	{
		j = 0;
		while (data->string[i][j] != '\0')
		{
			if (((data->string[i][j] == 'C') && map[i][j] == 'C')
				|| ((data->string[i][j] == 'E') && map[i][j] == 'E'))
			{
				ft_printf("the Path is not valid\n");
				free(vars);
				free_map(map);
				ft_exit(data, 1, 1);
			}
			j++;
		}
		i++;
	}
	free_map(map);
}
