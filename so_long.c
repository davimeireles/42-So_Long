/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:06:50 by dmeirele          #+#    #+#             */
/*   Updated: 2023/12/13 17:10:32 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int close_window(void *param)
{
	t_data *data = (t_data *)param;

	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(0);

	return (0);
}

void	free_struct(t_data *data)
{
	free(data->mlx_ptr);
	free(data->win_ptr);
	free(data);
}

int main(void)
{
	t_data *data;

	data = malloc(sizeof(t_data));
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr,1920,1080,"My program");
	mlx_hook(data->win_ptr,17,0,close_window, &data);
	mlx_loop(data->mlx_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free_struct(data);
}