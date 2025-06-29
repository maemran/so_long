/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maemran < maemran@student.42amman.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 05:51:55 by maemran           #+#    #+#             */
/*   Updated: 2025/06/29 18:31:36 by maemran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	put_door(t_data *data, t_map *map)
{
	if (c_check(data) == 0)
		mlx_put_image_to_window(data->mlx, data->win, data->door, map->x,
			map->y);
	else
		mlx_put_image_to_window(data->mlx, data->win, data->empty, map->x,
			map->y);
}

void	put_img(t_data *data, t_map *map, char c)
{
	if (c == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->wall, map->x,
			map->y);
	else if (c == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->empty, map->x,
			map->y);
	else if (c == 'E')
		put_door(data, map);
	else if (c == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->player, map->x,
			map->y);
	else if (c == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->collect, map->x,
			map->y);
	else if (c == 'M')
		mlx_put_image_to_window(data->mlx, data->win, data->fire, map->x,
			map->y);
	else
		exit_pos(data, 1, map);
}

void	drow_map(char **string, t_data *data)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!(map))
	{
		perror("Error allocating memory\n");
		ft_exit(data, 0, 1);
	}
	map->y = 0;
	map->i = 0;
	while (string[map->i] != NULL)
	{
		map->j = 0;
		map->x = 0;
		while (string[map->i][map->j] != '\0')
		{
			put_img(data, map, string[map->i][map->j]);
			map->x += 50;
			map->j++;
		}
		map->y += 50;
		map->i++;
	}
	free(map);
}

void	ft_exit_img(t_data *data, int n)
{
	perror("Error to creat img\n");
	if (n == 1 || n == 2 || n == 3 || n == 4 || n == 5)
		mlx_destroy_image(data->mlx, data->door);
	if (n == 2 || n == 3 || n == 4 || n == 5)
		mlx_destroy_image(data->mlx, data->wall);
	if (n == 3 || n == 4 || n == 5)
		mlx_destroy_image(data->mlx, data->collect);
	if (n == 4 || n == 5)
		mlx_destroy_image(data->mlx, data->empty);
	if (n == 5)
		mlx_destroy_image(data->mlx, data->player);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	ft_exit(data, 1, 1);
}

void	init_img(t_data *data)
{
	data->door = mlx_xpm_file_to_image(data->mlx,
			"./textures/door.xpm", &data->w, &data->h);
	if (!(data->door))
		ft_exit_img(data, 0);
	data->wall = mlx_xpm_file_to_image(data->mlx,
			"./textures/wall.xpm", &data->w, &data->h);
	if (!(data->wall))
		ft_exit_img(data, 1);
	data->collect = mlx_xpm_file_to_image(data->mlx,
			"./textures/collectible.xpm", &data->w, &data->h);
	if (!(data->collect))
		ft_exit_img(data, 2);
	data->empty = mlx_xpm_file_to_image(data->mlx,
			"./textures/floor.xpm", &data->w, &data->h);
	if (!(data->empty))
		ft_exit_img(data, 3);
	data->player = mlx_xpm_file_to_image(data->mlx,
			"./textures/player.xpm", &data->w, &data->h);
	if (!(data->player))
		ft_exit_img(data, 4);
	data->fire = mlx_xpm_file_to_image(data->mlx,
			"./textures/fire.xpm", &data->w, &data->h);
	if (!(data->fire))
		ft_exit_img(data, 5);
}
