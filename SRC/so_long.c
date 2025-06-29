/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maemran < maemran@student.42amman.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 15:27:57 by maemran           #+#    #+#             */
/*   Updated: 2025/06/29 18:32:06 by maemran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	error_msg(t_data *data, t_vars *vars, char *msg, int n)
{
	if (n == 4)
		close (vars->fd);
	if (n == 3 || n == 4 || n == 5 || n == 6)
		free(data);
	if (n == 4 || n == 5 || n == 6)
		free(vars->s1);
	if (n == 5 || n == 6)
		free(vars->s);
	if (n == 2 || n == 3 || n == 4 || n == 5 || n == 6)
		free(vars);
	if (n == 1 || n == 2 || n == 3 || n == 4 || n == 6)
		perror(msg);
	if (n == 5)
		ft_printf("%s", msg);
	exit(1);
}

void	ft_read(t_data *data, t_vars *vars)
{
	vars->s1 = ft_strdup("");
	if (!(vars->s1))
		error_msg(data, vars, "Error allocating memory\n", 3);
	vars->s = get_next_line(vars->fd);
	if (!vars->s)
		error_msg(data, vars, "Error allocating memory for GNL\n", 4);
	vars->y = 0;
	while (vars->s != NULL)
	{
		vars->temp = vars->s1;
		if (vars->s != NULL)
		{
			vars->s1 = ft_strjoin(vars->temp, vars->s);
			if (vars->s1 == NULL)
				error_msg(data, vars, "Error allocating memory\n", 5);
			vars->y++;
		}
		free(vars->temp);
		free(vars->s);
		vars->s = get_next_line(vars->fd);
	}
	new_line_check(data, vars);
	close(vars->fd);
	data->string = ft_split(vars->s1, '\n');
}

void	ft_game_brain(t_vars *vars, t_data *data)
{
	pe_pos(data);
	valid_path(data, vars);
	data->hight = vars->y * 50;
	data->width = vars->x * 50;
	free(vars);
	data->mlx = mlx_init();
	if (!(data->mlx))
	{
		perror("Error initializing MLX\n");
		ft_exit(data, 1, 1);
	}
	data->win = mlx_new_window(data->mlx, data->width, data->hight, "so_long");
	if (!(data->win))
	{
		perror("Error creating window\n");
		free(data->mlx);
		ft_exit(data, 1, 1);
	}
	init_img(data);
	data->m_nums = check_m(data);
	drow_map(data->string, data);
	put_string_to_win(data, 0);
	mlx_hook(data->win, 2, 1L << 0, handle_key, data);
	mlx_hook(data->win, 17, 0, close_window, data);
	mlx_loop(data->mlx);
}

void	process(t_data *data, t_vars *vars)
{
	ft_read(data, vars);
	if (!(data->string))
		error_msg(data, vars, "Error allocating memory\n", 6);
	free(vars->s);
	vars->x = ft_strlen(data->string[0]);
	free(vars->s1);
	pe_check(data, vars);
	map_check_1(data, vars);
	map_check_3(data, vars, vars->y, vars->x);
}

int	main(int argc, char **argv)
{
	t_vars	*vars;
	t_data	*data;

	if (argc > 2 || argc == 1)
	{
		ft_printf("More than 2 args\n");
		exit(1);
	}
	else
	{
		vars = (t_vars *)malloc(sizeof(t_vars));
		if (!vars)
			error_msg(NULL, vars, "Error allocating memory\n", 1);
		data = (t_data *)malloc(sizeof(t_data));
		if (!data)
			error_msg(data, vars, "Error allocating memory\n", 2);
		vars->fd = open(argv[1], O_RDONLY);
		process(data, vars);
		ft_game_brain(vars, data);
	}
	return (0);
}
