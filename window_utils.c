/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:59:15 by dmeirele          #+#    #+#             */
/*   Updated: 2024/01/15 18:59:15 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_memory(t_map *data)
{
	free_map(data);
	free(data->mlx_ptr);
	free(data);
}

int	close_window(t_map *data)
{
	if (data->img)
	{
		mlx_destroy_image(data->mlx_ptr, data->img[0]);
		mlx_destroy_image(data->mlx_ptr, data->img[1]);
		mlx_destroy_image(data->mlx_ptr, data->img[2]);
		mlx_destroy_image(data->mlx_ptr, data->img[3]);
		mlx_destroy_image(data->mlx_ptr, data->img[4]);
	}
	free(data->img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free_memory(data);
	exit(0);
	return (0);
}

int	handle_key_press(int keysym, t_map *data)
{
	if (keysym == ESC)
		close_window(data);
	if (keysym == U_ARROW || keysym == W_KEY)
		refresh(data, data->p_loc[0], data->p_loc[1] - 1);
	if (keysym == D_ARROW || keysym == S_KEY)
		refresh(data, data->p_loc[0], data->p_loc[1] + 1);
	if (keysym == R_ARROW || keysym == D_KEY)
		refresh(data, data->p_loc[0] + 1, data->p_loc[1]);
	if (keysym == L_ARROW || keysym == A_KEY)
		refresh(data, data->p_loc[0] - 1, data->p_loc[1]);
	return (0);
}

void	window_utilities(t_map	*data)
{
	int	length;
	int	height;

	length = data->columns * 32;
	height = data->lines * 32;
	find_end(data);
	find_player(data);
	check_entities(data, 0, 0);
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return ;
	data->win_ptr = mlx_new_window(data->mlx_ptr, length, height, "So_Long");
	load_images(data);
	render(data, -1, -1);
	data->map[data->p_loc[1]][data->p_loc[0]] = '0';
	mlx_hook(data->win_ptr, 2, (1L << 0), handle_key_press, data);
	mlx_hook(data->win_ptr, 17, 0, close_window, data);
	mlx_loop(data->mlx_ptr);
}
