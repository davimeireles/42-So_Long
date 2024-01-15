/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:48:47 by dmeirele          #+#    #+#             */
/*   Updated: 2024/01/15 14:48:47 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_old(t_map *data)
{
	int		old_x;
	int		old_y;
	char	**map;

	old_x = data->p_loc[0];
	old_y = data->p_loc[1];
	map = data->map;
	if (map[old_y][old_x] == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img[4], old_x * 32, old_y * 32);
	if (map[old_y][old_x] == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img[3], old_x * 32, old_y * 32);
}

void	render_new(t_map *data)
{
	int		x;
	int		y;
	char	**map;

	x = data->p_loc[0];
	y = data->p_loc[1];
	map = data->map;
	if (map[y][x] == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img[3], x * 32, y * 32);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img[1], x * 32, y * 32);
}

void	init_values(t_map *data)
{
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->img = NULL;
	data->map = NULL;
	data->p_loc[0] = 0;
	data->p_loc[1] = 0;
	data->e_loc[0] = 0;
	data->e_loc[1] = 0;
	data->moves = 0;
	data->lines = 0;
	data->columns = 0;
	data->coins = 0;
	data->player = 0;
	data->exit = 0;
}
