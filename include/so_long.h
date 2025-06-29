/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maemran < maemran@student.42amman.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 00:19:00 by maemran           #+#    #+#             */
/*   Updated: 2025/06/29 18:32:41 by maemran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include <X11/keysym.h>
# include <mlx.h>

typedef struct s_map
{
	int		y;
	int		x;
	int		i;
	int		j;
}			t_map;

typedef struct s_vars
{
	int		fd;
	char	*s;
	char	*temp;
	char	*s1;
	int		y;
	int		x;
}			t_vars;

typedef struct s_data
{
	char	**string;
	void	*mlx;
	void	*win;
	void	*collect;
	void	*wall;
	void	*player;
	void	*fire;
	void	*door;
	void	*empty;
	int		width;
	int		hight;
	int		h;
	int		w;
	int		i_p;
	int		j_p;
	int		i_e;
	int		j_e;
	int		m_nums;
}			t_data;

void		map_check_1(t_data *data, t_vars *vars);
void		map_check_3(t_data *data, t_vars *vars, int i, int j);
void		pe_check(t_data *data, t_vars *vars);
int			c_check(t_data *data);
int			d_check(t_data *data);
void		free_map(char **map);
void		ft_exit(t_data *data, int n, int type);
void		flood_fill(char **tab, int y, int x);
char		**map_copy(t_data *data, t_vars *vars);
void		valid_path(t_data *data, t_vars *vars);
void		exit_pos(t_data *data, int n, t_map *map);
void		put_img(t_data *data, t_map *map, char c);
void		drow_map(char **string, t_data *data);
void		ft_exit_img(t_data *data, int n);
void		init_img(t_data *data);
void		pe_pos(t_data *data);
int			new_pos(t_data *data, char c);
int			handle_key(int keycode, t_data *data);
void		error_msg(t_data *data, t_vars *vars, char *msg, int n);
void		ft_read(t_data *data, t_vars *vars);
void		ft_game_brain(t_vars *vars, t_data *data);
void		c_nums(t_data *data, t_vars *vars);
char		*ft_string(int moves);
void		put_string_to_win(t_data *data, int moves);
void		new_line_check(t_data *data, t_vars *vars);
int			check_m(t_data *data);
void		process(t_data *data, t_vars *vars);
int			close_window(t_data *data);
void		put_door(t_data *data, t_map *map);

#endif
