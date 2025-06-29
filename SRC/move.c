/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maemran < maemran@student.42amman.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 06:16:54 by maemran           #+#    #+#             */
/*   Updated: 2025/06/29 18:31:56 by maemran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	new_line_check(t_data *data, t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->s1[i] != '\0')
	{
		if (vars->s1[i] == '\n' && vars->s1[i + 1] == '\n')
			error_msg(data, vars, "new line in the map\n", 5);
		i++;
	}
}

void	c_nums(t_data *data, t_vars *vars)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	c = 0;
	while (data->string[i])
	{
		j = 0;
		while (data->string[i][j] != '\0')
		{
			if (data->string[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	if (c == 0)
	{
		ft_printf("Map should be contain at least one C char\n");
		free(vars);
		ft_exit(data, 1, 1);
	}
}

void	pe_pos(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->string[i])
	{
		j = 0;
		while (data->string[i][j] != '\0')
		{
			if (data->string[i][j] == 'P')
			{
				data->i_p = i;
				data->j_p = j;
			}
			if (data->string[i][j] == 'E')
			{
				data->i_e = i;
				data->j_e = j;
			}
			j++;
		}
		i++;
	}
}

int	new_pos(t_data *data, char c)
{
	int	flag;

	flag = 1;
	data->string[data->i_p][data->j_p] = '0';
	if (c == 'w' && data->string[(data->i_p) - 1][data->j_p] != '1')
		data->i_p -= 1;
	else if (c == 's' && data->string[(data->i_p) + 1][data->j_p] != '1')
		data->i_p += 1;
	else if (c == 'a' && data->string[data->i_p][(data->j_p) - 1] != '1')
		data->j_p -= 1;
	else if (c == 'd' && data->string[data->i_p][(data->j_p) + 1] != '1')
		data->j_p += 1;
	else
		flag = 0;
	data->string[data->i_p][data->j_p] = 'P';
	return (flag);
}

int	handle_key(int key, t_data *data)
{
	static int	counter = 0;
	int			flag;

	if (key == XK_Escape)
		ft_exit(data, 0, 0);
	else if (key == XK_w)
		flag = new_pos(data, 'w');
	else if (key == XK_s)
		flag = new_pos(data, 's');
	else if (key == XK_a)
		flag = new_pos(data, 'a');
	else if (key == XK_d)
		flag = new_pos(data, 'd');
	if (data->m_nums != check_m(data))
		ft_exit(data, 0, 0);
	exit_pos(data, 0, NULL);
	mlx_clear_window(data->mlx, data->win);
	drow_map(data->string, data);
	if ((key == XK_w || key == XK_s || key == XK_a || key == XK_d) && flag == 1)
		counter++;
	put_string_to_win(data, counter);
	if (d_check(data) == 0 && c_check(data) == 0)
		ft_exit(data, 0, 0);
	return (0);
}
